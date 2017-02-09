#include "AxisLines.h"


Visualizer::AxisLines::AxisLines()
{

	mGeometry.resize(3, 4);
	mColors.resize(4, 4);
	mGeometry_indices.resize(2, 5);

	float axis_size = 2.0f;

	mGeometry.col(0) << axis_size, 0.0f, 0.0f;
	mGeometry.col(1) << 0.0f, axis_size, 0.0f;
	mGeometry.col(2) << 0.0f, 0.0f, axis_size;
	mGeometry.col(3) << 0.0f, 0.0f, 0.0f;

	mColors.col(0) << 1.0f, 0.0f, 0.0f, 1.0f;
	mColors.col(1) << 0.0f, 1.0f, 0.0f, 1.0f;
	mColors.col(2) << 0.0f, 0.0f, 1.0f, 1.0f;
	mColors.col(3) << 1.0f, 1.0f, 1.0f, 1.0f;

	mGeometry_indices.col(0) << 0, 1; //end points
	mGeometry_indices.col(1) << 2, 3;

	mGeometry_indices.col(2) << 0, 3; //lines
	mGeometry_indices.col(3) << 1, 3;
	mGeometry_indices.col(4) << 2, 3;

	mShader.init("axis_simple_shader", VertexShaderCode_Render, FragmentShaderCode_Render); //shader source cod in ShaderSourceCode.h

	mShader.bind();
	mShader.uploadIndices(mGeometry_indices);
	mShader.uploadAttrib("position", mGeometry);
	mShader.uploadAttrib("colors", mColors);

}


Visualizer::AxisLines::~AxisLines()
{
	mShader.free();
}


/** @brief Draws the actual primative to screen.
*
*  OpenGL command to draw the elements of the points to the screen.
*
*  @return void.
*/
void Visualizer::AxisLines::Visualize(Eigen::Matrix4f& mvp)
{
	glLineWidth(1.0f);
	glPointSize(8.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	mShader.bind();
	mShader.setUniform("modelViewProj", mvp);
	mShader.drawIndexed(GL_POINTS, 0, 4);
	mShader.drawIndexed(GL_LINES, 2, 5);

}


void Visualizer::AxisLines::VisualizeWireFrame()
{

}