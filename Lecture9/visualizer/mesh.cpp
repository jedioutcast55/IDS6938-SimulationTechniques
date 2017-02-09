#include "mesh.h"


Visualizer::Mesh::Mesh()
{
	mShader = new nanogui::GLShader;
}


Visualizer::Mesh::~Mesh()
{
	mShader->free();
}

void Visualizer::Mesh::InitShaders(std::string name)
{
	mShader = new nanogui::GLShader;
	mShader->init(name, Visualizer::VertexShaderCode_Render, Visualizer::FragmentShaderCode_Render2_ToneMap);
	mShader->bind();
	mShader->uploadIndices(mGeometry_indices);
	mShader->uploadAttrib("position", mGeometry);
	mShader->uploadAttrib("colors", mColors);
	mShader->setUniform("fill", 1);
	mShader->setUniform("tonemap", (int)false);
	mShader->setUniform("invWhitePoint", 1.0f);
	mShader->setUniform("invGamma", 1.0f);
}


/** @brief Draws the actual primative to screen.
*
*  OpenGL command to draw the elements of the points to the screen.
*
*  @return void.
*/
void Visualizer::Mesh::Visualize(Eigen::Matrix4f &mvp, ToneMapping const * toneMap)
{
	bool backFaceCull = false;
	glLineWidth(1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	mShader->bind();
	mShader->setUniform("fill", 1);
	mShader->setUniform("modelViewProj", mvp);
	if (toneMap != NULL) {
		mShader->setUniform("tonemap", (int)true);
		mShader->setUniform("invWhitePoint", 1.0f / toneMap->whitePoint);
		mShader->setUniform("invGamma", 1.0f / toneMap->gamma);
		backFaceCull = toneMap->backfaceCull;
	} else {
		mShader->setUniform("tonemap", (int)false);
		mShader->setUniform("invWhitePoint", 1.0f);
		mShader->setUniform("invGamma", 1.0f);        //these parameters leave the color unchanged (ie no tone mapping performed)
	}

	if (backFaceCull) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}

	mShader->drawIndexed(GL_TRIANGLES, 0, mGeometry_indices.cols());

	if (backFaceCull) {
		glDisable(GL_CULL_FACE);
	}
}


void Visualizer::Mesh::Visualize(Eigen::Matrix4f &mvp, unsigned int temp_pindex, unsigned int patch_triangle_count)
{
	mShader->bind();
	mShader->setUniform("fill", 1);
	mShader->setUniform("modelViewProj", mvp);
	mShader->drawIndexed(GL_TRIANGLES, temp_pindex, patch_triangle_count);
}

void Visualizer::Mesh::Visualize(Eigen::Matrix4f &mvp, const std::vector<int> &triangleIndices)
{
	mShader->bind();
	mShader->setUniform("fill", 1);
	mShader->setUniform("modelViewProj", mvp);
	for (auto& tri : triangleIndices) {
		mShader->drawIndexed(GL_TRIANGLES, tri, 1);  //could try to combine contiguous triangles if that was worthwhile
	}
}



void Visualizer::Mesh::VisualizeWireFrame(Eigen::Matrix4f &mvp)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	mShader->bind();
	mShader->setUniform("fill", 0);
	mShader->setUniform("modelViewProj", mvp);
	mShader->drawIndexed(GL_TRIANGLES, 0, mGeometry_indices.cols());
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void Visualizer::Mesh::ChangeMeshColors()
{
	mShader->bind();
	mShader->uploadAttrib("colors", mColors);
}