#pragma once

#ifndef _H_PARTICLES
#define _H_PARTICLES

#include "helper.hpp"


namespace Visualizer
{
	class Points : public Geometry::ParticleSystem
	{
	public:
		Points();
		~Points();

		void init();

		void Visualize(Eigen::Matrix4f &mvp);
		void VisualizeWireFrame();

		float GetPointSize();
		void SetPointSize(float size);

		void ChangePositions();

		nanogui::GLShader *mShader;

	private:
		float mPointSize;
	};
}

#endif