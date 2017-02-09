#pragma once

#ifndef _H_FULLSCREENQUAD
#define _H_FULLSCREENQUAD

#include "helper.hpp"
#include "Geometry.h"

namespace Visualizer
{

	class FullScreenQuad : public Geometry::Geometry
	{
	public:
		FullScreenQuad();
		~FullScreenQuad();

		void Visualize(Eigen::Matrix4f &mvp);
		void VisualizeWireFrame();
	//private:
		nanogui::GLShader mShader;
	};
}

#endif