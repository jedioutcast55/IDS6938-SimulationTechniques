
#pragma once
#ifndef _H_VIEWER
#define _H_VIEWER

#include "helper.hpp"
#include "GridLines.h"
#include "AxisLines.h"
#include "FullScreenQuad.h"
#include "theCamera.h"
#include "Points.h"
#include "mesh.h"
#include "SimulationEngine.h"

namespace Visualizer
{
	class Visualizer : public nanogui::Screen {

	public:

		Visualizer();
		virtual ~Visualizer();

		void intialize(Geometry::Scene *pScene);

		virtual bool keyboardEvent(int key, int scancode, int action, int modifiers);
		virtual bool mouseMotionEvent(const Eigen::Vector2i &p, const Eigen::Vector2i &rel, int button, int modifiers);
		virtual bool mouseButtonEvent(const Eigen::Vector2i &p, int button, bool down, int modifiers);
		void draw(NVGcontext *ctx);
		void drawContents();

	private:
		Geometry::Scene *mScene;
		Visualizer::theCamera mCamera; ///< Camera object 

		Visualizer::Points *mTestParticleSimulationSystem;

		Visualizer::GridLines mGridLines;
		Visualizer::AxisLines mAxisLines;
		Visualizer::FullScreenQuad mFullScreenQuad;

		Visualizer::Mesh *mGeometry;
		Simulator::SimulationEngine *mSimulationEngine;

		Visualizer::ToneMapping toneMap;   //tone mapping to applied when rendering

		//Mouse commands
		double mLastx;
		double mLasty;
		bool mButtons[3];
		bool mAltButton;
		bool mWireFrameMode;


		Eigen::Vector3f mIintialCameraUp;
		Eigen::Vector3f mIntialCameraPosition;
		Eigen::Vector3f mIntialCameraLookAt;

	};
}
#endif