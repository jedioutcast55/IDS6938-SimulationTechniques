#pragma once

#ifndef _H_PARTICLESYSTEM
#define _H_PARTICLESYSTEM

#include <Eigen\dense>
#include "Geometry.h"

namespace Geometry 
{
	class ParticleSystem : public Geometry
	{
	public:
		ParticleSystem();
		~ParticleSystem();

		void SetVelocities(Eigen::MatrixXf & pVelocities);
		void SetMasses(Eigen::MatrixXf & pMasses);
		void SetForces(Eigen::MatrixXf & pForces);
		Eigen::MatrixXf & GetVelocities(void);
		Eigen::MatrixXf & GetMasses(void);
		Eigen::MatrixXf & GetForces(void);

		
		void UpdateVelocityAtCol(unsigned int column, Eigen::Vector3f &new_vol);
		void UpdateForceAtCol(unsigned int column, Eigen::Vector3f &new_for);
		void UpdateMassAtIndex(unsigned int column, float &new_mass);

	protected:
		Eigen::MatrixXf  mVelocities; //Vertex Velocity x, y, z coords
		Eigen::MatrixXf  mMasses; //Vertex mass scalers coords
		Eigen::MatrixXf  mForces; //Vertex Force x, y, z coords

	};
}

#endif