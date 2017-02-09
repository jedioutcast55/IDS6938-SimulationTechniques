#include "theCamera.h"


/** @brief Constructs a camera
*
*  Constructs a camera object by setting the position, look at position, up vector.
*  Puts together a model matrix, and projection matrix.
*
*  @param width - float - width of window
*  @param height - float - height of window
*  @return void.
*/
Visualizer::theCamera::theCamera()
{
	mIdenityMatrix = glm::mat4(1.0f);
	mOrthoProjection = mIdenityMatrix * glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f);
}


void Visualizer::theCamera::settheCamera(float width, float height)
{
	screenWidth = width;
	screenHeight = height;

	setCameraPosition(40.0f, 40.0f, 40.0f);
	setLookAtPosition(0.0f, 0.0f, 0.0f);
	setupVector(0.0f, 0.0f, 1.0f);

	//setModelMatrix(glm::vec3(1.0f, 0.0f, 0.0f), 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	mModelMatrix = glm::mat4(1.0f);
	mProjectionMatrix = glm::mat4(1.0f);
	//setProjectionMatrix(45.0f, width / height, 0.1f, 100000.0f);

	setViewMatrix(getCameraPosition(), getLookAtPosition(), getupVector());
	setName("myCamera");

	realdiv = float(width + height);
	roty = 0.0f;
	rotx = 0.0f;
}


/** @brief Deconstructor a camera
*
*  This function deconstructs the camera object
*/
Visualizer::theCamera::~theCamera(void)
{
}


/** @brief Translates the camera
*
*  This function translates the camera in space.
*
*  @param diffx - float - change in x
*  @param diffy - float - change in y
*  @return void.
*/
void Visualizer::theCamera::translate(float diffx, float diffy)
{
	glm::vec3 c = getCameraPosition() - getLookAtPosition();
	float change = sqrt(c.x*c.x + c.y*c.y + c.z*c.z);

	//get the the view vector and then the right vector
	glm::vec3 cameraW = glm::normalize(getLookAtPosition() - getCameraPosition());
	glm::vec3 cameraU = glm::normalize(glm::cross(getupVector(), cameraW));

	//TODO: need to add - Translate based on the magnitude 
	float magnitude = sqrt((cameraU.x*cameraU.x) + (cameraU.y*cameraU.y) + (cameraU.z*cameraU.z));

	//x_changep/=magnitude;
	//y_changep/=magnitude;
	//z_changep/=magnitude;

	//Do the actual translation lookatPosition
	glm::vec3 changel = getLookAtPosition() + getupVector() * (35.5f*diffy / screenWidth);
	changel += cameraU * (16.0f*diffx / screenHeight);

	//Do the actual translation cameraPosition
	glm::vec3 changec = getCameraPosition() + getupVector() * (35.5f*diffy / screenWidth);
	changec += cameraU * (16.0f*diffx / screenHeight);

	//set the camera
	setCameraPosition(changec.x, changec.y, changec.z);
	setLookAtPosition(changel.x, changel.y, changel.z);
	setViewMatrix(getCameraPosition(), getLookAtPosition(), getupVector());
}


/** @brief Rotates the camera
*
*  This function rotates the camera in space.
*
*  @param diffx - float - change in x
*  @param diffy - float - change in y
*  @return void.
*/
void Visualizer::theCamera::rotate(float diffx, float diffy)
{
	roty = -(float) 0.025f * diffx;
	rotx = -(float) 0.025f * diffy;
	float phi = (rotx);
	float theta = (roty);

	//get the view vector and the right vector
	glm::vec3 cameraW = glm::normalize(getLookAtPosition() - getCameraPosition());
	glm::vec3 cameraU = glm::normalize(glm::cross(cameraW, getupVector()));

	//Get the quaterion rotate about the x and y axis: but fix the up axis to be constant
	glm::quat myQuat = glm::normalize(glm::angleAxis(theta, glm::vec3(0.0f, 0.0f, 1.0f)) *  glm::angleAxis(phi, glm::vec3(cameraU.x, cameraU.y, cameraU.z)));
	glm::mat4 rotmat = glm::toMat4(myQuat); //make a rotation matrix

	//Get the Camera position and vector to be rotated
	//(remember to translate back, rotate, then translate)
	glm::vec4 myPoint(getCameraPosition().x - getLookAtPosition().x, getCameraPosition().y - getLookAtPosition().y, getCameraPosition().z - getLookAtPosition().z, 1.0f);
	glm::vec4 myVector(getupVector().x, getupVector().y, getupVector().z, 0.0f);

	//Do the rotation
	glm::vec4 newPosition = rotmat * myPoint;
	glm::vec4 newUpVector = rotmat * myVector;
	//glm::vec4 newUpVector =  myQuat * myVector*  glm::conjugate(myQuat); //not sure why this did not work
	newUpVector = glm::normalize(newUpVector);

	//translate back
	newPosition.x += getLookAtPosition().x;
	newPosition.y += getLookAtPosition().y;
	newPosition.z += getLookAtPosition().z;

	//set the camera
	setCameraPosition(newPosition.x, newPosition.y, newPosition.z);
	setupVector(newUpVector.x, newUpVector.y, newUpVector.z);
	setViewMatrix(getCameraPosition(), getLookAtPosition(), getupVector());
}


/** @brief Zooms the camera
*
*  This function zooms the camera in space.
*
*  @param realdiff- float - total diff moved in both directions
*  @return void.
*/
void Visualizer::theCamera::zoom(float realdiff)
{
	//find the view vector, and move the camera on it
	glm::vec3 change = getCameraPosition() - getLookAtPosition();
	glm::vec3 change2 = getLookAtPosition() + change * (1 + 9.0f*realdiff / realdiv);

	//set the camera
	setCameraPosition(change2.x, change2.y, change2.z);
	setViewMatrix(getCameraPosition(), getLookAtPosition(), getupVector());
}


/** @brief Update the MVP Matrix
*
*  This function updates the MVP matrix : P * V * M
*
*  @return glm::mat4 - MVP matrix.
*/
glm::mat4 Visualizer::theCamera::updateMVP()
{
	return mProjectionMatrix * (mViewMatrix * mModelMatrix);
}


/** @brief Update the MV Matrix -Ortho
*
*  This function updates the MV Ortho matrix :  V * M
*
*  @return glm::mat4 - MV matrix.
*/
glm::mat4 Visualizer::theCamera::updateMVP_ORTHO()
{
	return  mOrthoProjection;
}


/** @brief Gets the camera position
*
*  This function returns the camera position in 3D space.
*
*  @return glm::vec3 - camera position.
*/
glm::vec3 Visualizer::theCamera::getCameraPosition()
{
	return mCameraPosition;
}


/** @brief Gets the look at  position
*
*  This function returns the camera look at position in 3D space.
*
*  @return glm::vec3 - look at position.
*/
glm::vec3 Visualizer::theCamera::getLookAtPosition()
{
	return mLookAtPosition;
}


/** @brief Gets the camera up vector
*
*  This function returns the camera up vector.
*
*  @return glm::vec3 - camera up vector.
*/
glm::vec3 Visualizer::theCamera::getupVector()
{
	return mCameraUpVector;
}


/** @brief Sets the camera position
*
*  This function sets the camera position in 3D space.
*
*  @param x - float- x position
*  @param y - float- y position
*  @param z - float- z position
*  @return void.
*/
void Visualizer::theCamera::setCameraPosition(float x, float y, float z)
{
	mCameraPosition.x = x;
	mCameraPosition.y = y;
	mCameraPosition.z = z;
}


/** @brief Sets the look at position
*
*  This function sets the camera looks at position in 3D space.
*
*  @param x - float- x position
*  @param y - float- y position
*  @param z - float- z position
*  @return void.
*/
void Visualizer::theCamera::setLookAtPosition(float x, float y, float z)
{
	mLookAtPosition.x = x;
	mLookAtPosition.y = y;
	mLookAtPosition.z = z;
}


/** @brief Sets the camera up vectir
*
*  This function sets the camera up vector.
*
*  @param x - float- x direction
*  @param y - float- y direction
*  @param z - float- z direction
*  @return void.
*/
void Visualizer::theCamera::setupVector(float x, float y, float z)
{
	mCameraUpVector.x = x;
	mCameraUpVector.y = y;
	mCameraUpVector.z = z;
}


/** @brief Returns Projection Matrix
*
*  This function returns the camera Projection Matrix.
*
*  @return glm::mat4 - camera projection matrix.
*/
glm::mat4 Visualizer::theCamera::getProjectionMatrix()
{
	return mProjectionMatrix;
}


/** @brief Returns View Matrix
*
*  This function returns the camera View Matrix.
*
*  @return glm::mat4 - camera view matrix.
*/
glm::mat4 Visualizer::theCamera::getViewMatrix()
{
	return mViewMatrix;
}


/** @brief Returns Model Matrix
*
*  This function returns the camera Model Matrix.
*
*  @return glm::mat4 - camera model matrix.
*/
glm::mat4 Visualizer::theCamera::getModelMatrix()
{
	return mModelMatrix;
}


/** @brief Process mouse event.
*
*  This function processes mouse events.
*
*  @return void.
*/
void Visualizer::theCamera::process_mouse_event()
{
}


/** @brief Returns the camera name
*
*  This function returns the camera name.
*
*  @return std::string  - camera name.
*/
std::string Visualizer::theCamera::getName()
{
	return mName;
}


/** @brief Sets teh camera name
*
*  This function sets the camera name.
*
*  @param - name - std::string  - camera name
*  @return void.
*/
void Visualizer::theCamera::setName(std::string name)
{
	mName = name;
}


/** @brief Sets the Model Matrix
*
*  This function sets the Model Matrix.
*
*  @param rotate - glm::vec3 - rotate
*  @param rotateaxis - float - axis to rotate
*  @aram translate - glm::vec3 - translate
*  @param scale - glm::vec3 - scale
*  @return void.
*/
void Visualizer::theCamera::setModelMatrix(glm::vec3 rotate, float rotateaxis, glm::vec3 translate, glm::vec3 scale)
{
	mModelMatrix = glm::mat4(1.0f);
	mModelMatrix = glm::rotate(mModelMatrix, rotateaxis, rotate);
	mModelMatrix = glm::translate(mModelMatrix, translate);
	mModelMatrix = glm::scale(mModelMatrix, scale);
}


/** @brief Sets the projection matrix
*
*  This function sets the projection matrix for a projective transform.
*
*  @param fovy - float - field of view y
*  @param aspect - float - aspect ration
*  @param zNear - float - zNear plane
*  @param zFar - float - zFar plane
*  @return void.
*/
void Visualizer::theCamera::setProjectionMatrix(float fovy, float aspect, float zNear, float zFar)
{
	mProjectionMatrix = glm::mat4(1.0f);
	mProjectionMatrix *= glm::perspective(fovy, aspect, zNear, zFar);
}


/** @brief Sets the projection matrix for orthographic mode
*
*  This function sets the projection matrix for a orthographic transform.
*
*  @param left - float - left position
*  @param right - float - right position
*  @param bottom - float - bottom position
*  @param top - float - top position
*  @param zNear - float - zNear plane
*  @param zFar - float - zFar plane
*  @return void.
*/
void Visualizer::theCamera::setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar)
{
	mProjectionMatrix = glm::mat4(1.0f);
	mProjectionMatrix *= glm::ortho(left, right, bottom, top, zNear, zFar);
}


/** @brief Sets the view matrix
*
*  This function sets the view matrix for the camera
*
*  @param position - glm::vec3 - camera position
*  @param lookat - glm::vec3 - look at position
*  @param up - glm::vec3 - up vector
*  @return void.
*/
void Visualizer::theCamera::setViewMatrix(glm::vec3 &position, glm::vec3 &lookat, glm::vec3 &up)
{
	mViewMatrix = glm::mat4(1.0f);
	mViewMatrix *= glm::lookAt(
		position,    // The eye's position in 3d space
		lookat,   // What the eye is looking at
		up);  // The eye's orientation vector (which way is up)
}

void Visualizer::theCamera::setViewMatrixY(glm::vec3 &position, glm::vec3 &lookat, glm::vec3 &up)
{
	mViewMatrix = glm::mat4(1.0f);
	mViewMatrix *= glm::lookAt(
		position,    // The eye's position in 3d space
		lookat,   // What the eye is looking at
		up);  // The eye's orientation vector (which way is up)

	mViewMatrix[1][0] *= -1.0f;
	mViewMatrix[1][1] *= -1.0f;
	mViewMatrix[1][2] *= -1.0f;
	mViewMatrix[1][3] *= -1.0f;


}