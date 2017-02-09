#include "GridLines.h"


Visualizer::GridLines::GridLines()
{
	int icounter = 0;
	int grid_line_count = 10;

	int gcolumn = 0;
	int icolumn = 0;
	int ccolumn = 0;

	int number_of_columns = (grid_line_count * 2 + 1) * 4;

	mGeometry.resize(3, number_of_columns);
	mColors.resize(4, number_of_columns);
	mGeometry_indices.resize(2, number_of_columns/2);

	for (int i = -grid_line_count; i <= grid_line_count; i = i + 1)
	{

		mGeometry.col(gcolumn++) << grid_line_count, (float)i, 0.0f; 
		mGeometry.col(gcolumn++) << -grid_line_count, (float)i, 0.0f;
		mGeometry.col(gcolumn++) << (float)i, grid_line_count, 0.0f; 
		mGeometry.col(gcolumn++) << (float)i, -grid_line_count, 0.0f;

		mGeometry_indices.col(icolumn++) << icounter, icounter + 1; //goes in backwards if ++?
		icounter += 2;
		mGeometry_indices.col(icolumn++) << icounter, icounter + 1; //goes in backwards if ++?
		icounter += 2;

		//all white
		mColors.col(ccolumn++) << 1.0f, 1.0f, 1.0f, 1.0f;
		mColors.col(ccolumn++) << 1.0f, 1.0f, 1.0f, 1.0f;
		mColors.col(ccolumn++) << 1.0f, 1.0f, 1.0f, 1.0f;
		mColors.col(ccolumn++) << 1.0f, 1.0f, 1.0f, 1.0f;

	}



	mShader.init("grid_simple_shader", VertexShaderCode_Render, FragmentShaderCode_Render); //shader source cod in ShaderSourceCode.h

	mShader.bind();
	mShader.uploadIndices(mGeometry_indices);
	mShader.uploadAttrib("position", mGeometry);
	mShader.uploadAttrib("colors", mColors);


}


Visualizer::GridLines::~GridLines()
{
	mShader.free();
}




/** @brief Draws the actual primative to screen.
*
*  OpenGL command to draw the elements of the points to the screen.
*
*  @return void.
*/
void Visualizer::GridLines::Visualize(Eigen::Matrix4f& mvp)
{
	glLineWidth(1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	mShader.bind();
	mShader.setUniform("modelViewProj", mvp);
	mShader.drawIndexed(GL_LINES, 0, mGeometry_indices.cols());
}


void Visualizer::GridLines::VisualizeWireFrame()
{
}