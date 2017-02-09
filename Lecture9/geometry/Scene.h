#pragma once
#ifndef _H_SCENE_EP
#define _H_SCENE_EP

#include "Geometry.h"
#include "ParticleSystem.h"

namespace Geometry
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		Geometry * get_Geometry( void );
		void SetGeometry(Geometry *geo);
		ParticleSystem * GetParticleSystem(void);
		void SetParticleSystem(ParticleSystem *part);


	private:
		Geometry* mGeometry;
		ParticleSystem* mParticles;

	};
}

#endif

