#include "particlesystem.h"

Geometry::ParticleSystem::ParticleSystem()
{

}


Geometry::ParticleSystem::~ParticleSystem()
{
	//clean up a bit
	mGeometry.resize(0, 0);;
	mGeometry_indices.resize(0, 0);
	mColors.resize(0, 0);
	mUvs.resize(0, 0);
	mNormals.resize(0, 0);
	mVelocities.resize(0, 0);
}


void Geometry::ParticleSystem::SetVelocities(Eigen::MatrixXf & pVelocities)
{
	mVelocities = pVelocities;
}


void Geometry::ParticleSystem::SetForces(Eigen::MatrixXf & pForces)
{
	mForces = pForces;
}

void Geometry::ParticleSystem::SetMasses(Eigen::MatrixXf & pMasses)
{
	mMasses = pMasses;
}

Eigen::MatrixXf & Geometry::ParticleSystem::GetVelocities(void) {
	return mVelocities;
}

Eigen::MatrixXf & Geometry::ParticleSystem::GetForces(void) {
	return mForces;
}

Eigen::MatrixXf & Geometry::ParticleSystem::GetMasses(void) {
	return mMasses;
}


void Geometry::ParticleSystem::UpdateVelocityAtCol(unsigned int column, Eigen::Vector3f &new_vol)
{
	mVelocities.col(column) << new_vol(0), new_vol(1), new_vol(2);

	return;
}


void Geometry::ParticleSystem::UpdateForceAtCol(unsigned int column, Eigen::Vector3f &new_for)
{
	mForces.col(column) << new_for(0), new_for(1), new_for(2);

	return;
}

void Geometry::ParticleSystem::UpdateMassAtIndex(unsigned int column, float &new_mass)
{
	mMasses.col(mGeometry_indices.col(column)(0)) << new_mass;

	return;
}