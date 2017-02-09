#pragma once

#ifndef _H_SIMULATIONENGINE
#define _H_SIMULATIONENGINE

#include <Eigen\dense>
#include "Scene.h"

namespace Simulator 
{
	class SimulationEngine 
	{
	public:
		SimulationEngine();
		~SimulationEngine();

		void intialize(Geometry::Scene *pScene);
		void update();
		void UnaryForces();

		void Integrate_RK1(float h);


	protected:
		Geometry::Scene *mScene;

	};
}

#endif