#include "SimulationEngine.h"


Simulator::SimulationEngine::SimulationEngine() { }
Simulator::SimulationEngine::~SimulationEngine() { }


void Simulator::SimulationEngine::intialize(Geometry::Scene *pScene)
{
	mScene = pScene;
}

void Simulator::SimulationEngine::update()
{

}
