#include "Scene.h"


Geometry::Scene::Scene()
{
	mGeometry = new Geometry();
	mParticles = new ParticleSystem();
}


Geometry::Scene::~Scene()
{
	delete[] mGeometry;
}


/** @brief Returns the Geometry
*
*  This function returns the Geometry
*
*  @return Geometry::Geometry -  geomery
*
*/
Geometry::Geometry * Geometry::Scene::get_Geometry(void)
{
	return mGeometry;
}



void Geometry::Scene::SetGeometry(Geometry *geo)
{
	mGeometry = geo;
}

Geometry::ParticleSystem * Geometry::Scene::GetParticleSystem(void)
{
	return mParticles;
}

void Geometry::Scene::SetParticleSystem(ParticleSystem *part)
{
	mParticles = part;
}