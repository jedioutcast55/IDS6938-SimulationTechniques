#include "Visualizer.h"


Visualizer::Visualizer::Visualizer() : nanogui::Screen(Eigen::Vector2i(VIZWIDTH, VIZHEIGHT), "Basic OpenGL Visualizer")
{
	toneMap.whitePoint = 1.0f;
	toneMap.gamma = 2.2f;
	toneMap.backfaceCull = false;

	nanogui::Window *window = new nanogui::Window(this, "Particle Test");




	


	/* All NanoGUI widgets are initialized at this point. Now
	create an OpenGL shader to draw the main window contents.

	NanoGUI comes with a simple Eigen-based wrapper around OpenGL 3,
	which eliminates most of the tedious and error-prone shader and
	buffer object management.
	*/

	mCamera.settheCamera(VIZWIDTH, VIZHEIGHT);
	mLastx = 0.0f;
	mLasty = 0.0f;
	mButtons[0] = mButtons[1] = mButtons[2] = mAltButton = 0;
	mWireFrameMode  = 1;


	mIintialCameraUp = Eigen::Vector3f(0.0f, 0.0f, 1.0f);
	mIntialCameraLookAt = Eigen::Vector3f(0.0f, 0.0f, 0.0f);

	//mIntialCameraPosition = Eigen::Vector3f(13.0f, 13.0f, 13.0f);
	mIntialCameraPosition = Eigen::Vector3f(20.0f, 0.0f, 0.0f);

}


Visualizer::Visualizer::~Visualizer()
{

}



void Visualizer::Visualizer::intialize(Geometry::Scene *pScene)
{
	mScene = pScene;
	mCamera.setCameraPosition(mIntialCameraPosition(0), mIntialCameraPosition(1), mIntialCameraPosition(2));
	mCamera.setLookAtPosition(mIntialCameraLookAt(0), mIntialCameraLookAt(1), mIntialCameraLookAt(2));
	mCamera.setupVector(mIintialCameraUp(0), mIintialCameraUp(1), mIintialCameraUp(2));
	mCamera.setProjectionMatrix(45.0f, VIZWIDTH / VIZHEIGHT, 0.1f, 10000.1f);

	//mCamera.setProjectionMatrix(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 1000.1f);
	mCamera.setViewMatrix(mCamera.getCameraPosition(), mCamera.getLookAtPosition(), mCamera.getupVector());

	//Dynamically sub cast Geomety -> to (renderable) mesh
	mGeometry = static_cast<Mesh*>(mScene->get_Geometry());
	mGeometry->InitShaders("mesh_simple_shader");
	//for (unsigned int pindex = 0; pindex < mGeometry->get_mGeometry_indices().cols(); pindex++) 
	//	mGeometry->UpdateColorAtIndex(pindex, Eigen::Vector4f(0.35f, 0.35f, 0.35f, 1.0f));
	//mGeometry->ChangeMeshColors();


	mTestParticleSimulationSystem = static_cast<Points*>(mScene->GetParticleSystem());
	mTestParticleSimulationSystem->init();
	mTestParticleSimulationSystem->SetPointSize(8.0f);

	mSimulationEngine = new Simulator::SimulationEngine();
	mSimulationEngine->intialize(pScene);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}






bool Visualizer::Visualizer::keyboardEvent(int key, int scancode, int action, int modifiers) {
	if (Screen::keyboardEvent(key, scancode, action, modifiers))
		return true;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		setVisible(false);
		return true;
	}

	if ((key == GLFW_KEY_LEFT_ALT || key == GLFW_KEY_RIGHT_ALT) && action == GLFW_PRESS)
	{
		mAltButton = 1;
		return true;
	}
	if ((key == GLFW_KEY_LEFT_ALT || key == GLFW_KEY_RIGHT_ALT) && action == GLFW_RELEASE)
	{
		mAltButton = 0;
		return true;
	}
	if (key == GLFW_KEY_C && action == GLFW_PRESS) {
		mCamera.setCameraPosition(mIntialCameraPosition(0), mIntialCameraPosition(1), mIntialCameraPosition(2));
		mCamera.setLookAtPosition(mIntialCameraLookAt(0), mIntialCameraLookAt(1), mIntialCameraLookAt(2));
		mCamera.setupVector(mIintialCameraUp(0), mIintialCameraUp(1), mIintialCameraUp(2));
		mCamera.setProjectionMatrix(45.0f, VIZWIDTH / VIZHEIGHT, 0.1f, 10000.1f);

		//mCamera.setProjectionMatrix(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 1000.1f);
		mCamera.setViewMatrix(mCamera.getCameraPosition(), mCamera.getLookAtPosition(), mCamera.getupVector());
		return true;
	}
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		mWireFrameMode = !mWireFrameMode;
	}



	return false;
}


bool Visualizer::Visualizer::mouseButtonEvent(const Eigen::Vector2i &p, int button, bool down, int modifiers)
{
	if (Screen::mouseButtonEvent(p, button, down, modifiers))
		return true;

	mLastx = p(0);
	mLasty = p(1);

	switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT:
		mButtons[0] = ((GLFW_PRESS == down) ? 1 : 0);
		break;
	case GLFW_MOUSE_BUTTON_RIGHT:
		mButtons[2] = ((GLFW_PRESS == down) ? 1 : 0);
		break;
	case GLFW_MOUSE_BUTTON_MIDDLE:
		mButtons[1] = ((GLFW_PRESS == down) ? 1 : 0);
		break;
	default:
		break;
	}

	return true;
}



bool Visualizer::Visualizer::mouseMotionEvent(const Eigen::Vector2i &p, const Eigen::Vector2i &rel, int button, int modifiers)
{
	float diffx = (float)p(0) - (float)mLastx;
	float diffy = (float)p(1) - (float)mLasty;
	mLastx = p(0);
	mLasty = p(1);

	float realdiff = -(diffx + diffy);

	if (mButtons[2] && mAltButton)
	{
		mCamera.zoom(realdiff);
		return true;
	}
	if (mButtons[0] && mAltButton)
	{
		mCamera.rotate(diffx, diffy);
		return true;
	}

	if (mButtons[1] && mAltButton)
	{
		mCamera.translate(diffx, diffy);
		return true;
	}


	return true;
}


void Visualizer::Visualizer::draw(NVGcontext *ctx)
{
	/* Animate the scrollbar */
	//mProgress->setValue(std::fmod((float)glfwGetTime() / 10, 1.0f));

	/* Draw the user interface */
	nanogui::Screen::draw(ctx);
}

void  Visualizer::Visualizer::drawContents()
{
	/* Draw the window contents using OpenGL */
	mFullScreenQuad.Visualize(Eigen::Matrix4f(glm::value_ptr(mCamera.updateMVP_ORTHO())));
	mGridLines.Visualize(Eigen::Matrix4f(glm::value_ptr(mCamera.updateMVP())));
	mAxisLines.Visualize(Eigen::Matrix4f(glm::value_ptr(mCamera.updateMVP())));

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);



	mGeometry->Visualize(Eigen::Matrix4f(glm::value_ptr(mCamera.updateMVP())), &toneMap);

	mTestParticleSimulationSystem->Visualize(Eigen::Matrix4f(glm::value_ptr(mCamera.updateMVP())));

	mSimulationEngine->update();
	mTestParticleSimulationSystem->ChangePositions();



	if (mWireFrameMode)
	{
		mGeometry->VisualizeWireFrame(Eigen::Matrix4f(glm::value_ptr(mCamera.updateMVP())));
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}