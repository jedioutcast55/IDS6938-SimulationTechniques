#include "Points.h"


Visualizer::Points::Points() 
{


}


Visualizer::Points::~Points()
{
	mShader->free();
}

void Visualizer::Points::init()
{
	mShader = new nanogui::GLShader();
	mPointSize = 8.0f;

	mShader->init("point_simple_shader", VertexShaderCode_Render, FragmentShaderCode_Render); //shader source cod in ShaderSourceCode.h
	
	mShader->bind();
	mShader->uploadAttrib("position", mGeometry);
	mShader->uploadAttrib("colors", mColors);

}


/** @brief Draws the actual primative to screen.
*
*  OpenGL command to draw the elements of the points to the screen.
*
*  @return void.
*/
void Visualizer::Points::Visualize(Eigen::Matrix4f& mvp)
{
	glPointSize(mPointSize);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	mShader->bind();
	mShader->setUniform("modelViewProj", mvp);
	mShader->drawArray(GL_POINTS, 0, mGeometry.cols());

}


void Visualizer::Points::VisualizeWireFrame()
{

}


float Visualizer::Points::GetPointSize()
{
	return mPointSize;
}

void Visualizer::Points::SetPointSize(float size)
{
	mPointSize = size;
}


void Visualizer::Points::ChangePositions()
{
	mShader->bind();
	mShader->uploadAttrib("position", mGeometry);
}