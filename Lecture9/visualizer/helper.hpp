#pragma once
#ifndef _H_HELPING_VIZ_SOURCE
#define _H_HELPING_VIZ_SOURCE

#define GLM_ENABLE_EXPERIMENTAL

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define VIZWIDTH 1024
#define VIZHEIGHT 768

//Include Eigen for matrix functionality.
#include <Eigen/Dense>

#include <string>
#include <iostream>
#include <vector>
#include <array>


#include <nanogui/nanogui.h>

#include <iostream>

#if defined(_WIN32)
#include <windows.h>
#endif


//Mathmatical defines
#define _USE_MATH_DEFINES
#include <math.h>

#include <string>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"
#include <Geometry.h>
#include <particlesystem.h>

#include "ShaderSourceCode.h"


struct ToneMapping {
	float whitePoint;   ///Value which will map to full white on display (ie max displayable value without clipping)
	float gamma;        ///Gamma value for display (typically around 2.2 for most monitors)
	bool backfaceCull;  ///Use backface culling? (not really a tonemap parameter but this is a convenient place to put it for now)
};



#endif