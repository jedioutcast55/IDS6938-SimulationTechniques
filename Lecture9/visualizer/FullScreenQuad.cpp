#include "FullScreenQuad.h"


Visualizer::FullScreenQuad::FullScreenQuad()
{

	Eigen::Vector3f lower_color(0.05f, 0.05f, 0.05f);
	//Eigen::Vector3f upper_color(0.492f, 0.566f, 0.644f); //blueish
	Eigen::Vector3f upper_color(0.4f, 0.4f, 0.4f); //greyish

	mGeometry.resize(3, 4);
	mColors.resize(4, 4);
	mGeometry_indices.resize(3, 2);

	mGeometry.col(0) << -1.0f, -1.0f, 0.0f;
	mGeometry.col(1) << 1.0f, -1.0f, 0.0f;
	mGeometry.col(2) << -1.0f, 1.0f, 0.0f;
	mGeometry.col(3) << 1.0f, 1.0f, 0.0f;

	mColors.col(0) << lower_color(0), lower_color(1), lower_color(2), 1.0f;
	mColors.col(1) << lower_color(0), lower_color(1), lower_color(2), 1.0f;
	mColors.col(2) << upper_color(0), upper_color(1), upper_color(2), 1.0f;
	mColors.col(3) << upper_color(0), upper_color(1), upper_color(2), 1.0f;

	mGeometry_indices.col(0) << 0, 1, 2;
	mGeometry_indices.col(1) << 2, 1, 3;

	mShader.init("quad_simple_shader", VertexShaderCode_Render, FragmentShaderCode_Render); //shader source cod in ShaderSourceCode.h

	mShader.bind();
	mShader.uploadIndices(mGeometry_indices);
	mShader.uploadAttrib("position", mGeometry);
	mShader.uploadAttrib("colors", mColors);
	

}



Visualizer::FullScreenQuad::~FullScreenQuad()
{
	mShader.free();
}




/** @brief Draws the actual primative to screen.
*
*  OpenGL command to draw the elements of the points to the screen.
*
*  @return void.
*/
void Visualizer::FullScreenQuad::Visualize(Eigen::Matrix4f & mvp)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	mShader.bind();
	mShader.setUniform("modelViewProj", mvp);
	mShader.drawIndexed(GL_TRIANGLES, 0, 2);
}


void Visualizer::FullScreenQuad::VisualizeWireFrame()
{
}