/**
*  Copyright 2014-2015 Program of Computer Graphics, Cornell University
*     580 Rhodes Hall
*     Cornell University
*     Ithaca NY 14853
*  Web: http://www.graphics.cornell.edu/
*
*  Not for commercial use. Do not redistribute without permission.
*
*  @file    theCamera.h
*  @brief Class that caculates and stores the form factors for radiosity
*
*  This file provides functionality for creating and using a quaterion based
*  camera designed for openGL. Camera exposes a number of settings that 
*  determine the viewing transformation needed to operate. 
*
*  This supports both projection and orthograthic modes.
*  Quaterion Camera - 'Similar' to Maya's functionality of pan, rotate, zoom.
*
*
*  @author  Joseph T. Kider Jr. (kiderj@graphics.cornell.edu)
*  @date    10/01/2014
*/

#pragma once
#ifndef CCAMERA_H
#define CCAMERA_H

#include "helper.hpp"

namespace Visualizer
{
	class theCamera
	{
	public:
		theCamera();
		void settheCamera(float width, float height);
		~theCamera(void);

		void process_mouse_event();
		void translate(float diffx, float diffy);
		void rotate(float diffx, float diffy);
		void zoom(float realdiff);

		void setModelMatrix(glm::vec3 rotate, float rotateaxis, glm::vec3 translate, glm::vec3 scale);
		void setProjectionMatrix(float fovy, float aspect, float zNear, float zFar);
		void setProjectionMatrix(float left, float right, float bottom, float top, float zNear, float zFar);
		void setViewMatrix(glm::vec3 &position, glm::vec3 &lookat, glm::vec3 &up);
		void setViewMatrixY(glm::vec3 &position, glm::vec3 &lookat, glm::vec3 &up);
		void setCameraPosition(float x, float y, float z);
		void setLookAtPosition(float x, float y, float z);
		void setupVector(float x, float y, float z);
		void setName(std::string name);

		glm::mat4 updateMVP();
		glm::mat4 updateMVP_ORTHO();

		glm::mat4 getProjectionMatrix();
		glm::mat4 getViewMatrix();
		glm::mat4 getModelMatrix();
		glm::vec3 getCameraPosition();
		glm::vec3 getLookAtPosition();
		glm::vec3 getupVector();
		std::string getName();

		glm::mat4 mProjectionMatrix; ///< Camera projection matrix

	private:
		
		glm::mat4 mViewMatrix; ///< Camera view matrix
		glm::mat4 mModelMatrix; ///< Camera model matrix
		glm::vec3 mCameraPosition; ///< Camera position
		glm::vec3 mLookAtPosition; ///< Camera look at position
		glm::vec3 mCameraUpVector; ///< Camera up vector

		float roty; ///< rotation from y movement
		float rotx; ///< rotation from x movement
		float screenWidth; ///< screen viewport width
		float screenHeight; ///< screen viewport height
		float realdiv; ///< width + height
		std::string mName; ///< Name of the camera

		glm::mat4 mIdenityMatrix;
		glm::mat4 mOrthoProjection;
	};
}
#endif // CCAMERA_H
