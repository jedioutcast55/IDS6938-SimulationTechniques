#include "Geometry.h"


Geometry::Geometry::Geometry()
{
}


Geometry::Geometry::~Geometry()
{
	//clean up a bit
	mGeometry.resize(0, 0);;
	mGeometry_indices.resize(0, 0);
	mColors.resize(0, 0);
	mUvs.resize(0, 0);
	mNormals.resize(0, 0);
}


/** @brief Loads OBJ files.
*
*  This function loads OBJ files using tinyobj loader.
*  Currently this is set to a 1-1 mapping of triangles to patches
*  and the indexes are a flat vector, with no compression.
*
*  @param filename - const char* - Filename for OBJ file
*  @param basename - const char* - base directory for OBJ file
*  @return unsigned int - Obj loading success >0 - total number of patches, 0 for fail
*
*/
unsigned int Geometry::Geometry::LoadOBJFile_Triangles(const char* filename, const char* basepath, bool triangulate, Eigen::Vector4f &intialization_color)
{

	// Load OBJ file.
	std::vector<tinyobj::shape_t> shapes; // all shapes that will be loaded by tinyobj
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::material_t> materials;
	std::string err; // test for an error
	
	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, filename,
		basepath, triangulate);

	int patchID = 0;
	std::vector<int> triangle_patch_indices;
	unsigned int icounter = 0;




	// load all the shapes from the obj file
	for (size_t i = 0; i < shapes.size(); i++)
	{
		assert((shapes[i].mesh.indices.size() % 3) == 0); //error if not triangualized corretly by tinyobj

														  //more than one mesh?
		unsigned indices_start_index = mGeometry_indices.rows();
		unsigned geometry_start_index = mGeometry.rows();
		unsigned colors_start_index = mColors.rows();
		//unsigned normals_start_index = mNormals.rows();
		//unsigned uvs_start_index = mUVs.rows();
		

		mGeometry.resize(3, shapes[i].mesh.indices.size() + mGeometry.rows());
		mColors.resize(4, shapes[i].mesh.indices.size() + mColors.rows());
		//mUvs.resize(2, shapes[i].mesh.num_face_vertices.size() + mUvs.rows());
		//mNormals.resize(3, shapes[i].mesh.num_face_vertices.size() + mNormals.rows());
		mGeometry_indices.resize(3, shapes[i].mesh.indices.size() / 3 + mGeometry_indices.rows());

		size_t index_offset = 0;

		// For each face
		for (size_t f = 0; f < shapes[i].mesh.num_face_vertices.size(); f ++)
		{
			size_t fnum = shapes[i].mesh.num_face_vertices[f];

			// For each vertex in the face
			for (size_t v = 0; v < fnum; v++) {
				tinyobj::index_t idx = shapes[i].mesh.indices[index_offset + v];
				mGeometry.col(f*3 + v + geometry_start_index) << attrib.vertices[3 * idx.vertex_index + 0], attrib.vertices[3 * idx.vertex_index + 1], attrib.vertices[3 * idx.vertex_index + 2];
				mColors.col(f*3 + v + colors_start_index) << intialization_color(0), intialization_color(1), intialization_color(2), intialization_color(3);
			
			}

			// Currently have a 1-1 mapping, (but this can be shortend in the future).
			mGeometry_indices.col(f  + indices_start_index) << icounter, icounter + 1, icounter + 2; //goes in backwards if ++?
			icounter += 3;

			patchID++;
			index_offset += fnum;
		} //end face loop

	} //end Shapes



	return patchID;
}


/** @brief Sets the Geometry Vector
*
*  This function sets the main Geometry vector to the input
*
*  @param pGeometry - Eigen::MatrixXf & - main geometry vector
*
*/
void Geometry::Geometry::set_mGeometry(Eigen::MatrixXf & pGeometry)
{
	mGeometry = pGeometry;
}


/** @brief Sets the Color Vector
*
*  This function sets the Color vector to the input
*
*  @param pColor - Eigen::MatrixXf & - color vector
*
*/
void Geometry::Geometry::set_mColors(Eigen::MatrixXf & pColors)
{
	mColors = pColors;
}


/** @brief Sets the uvs Vector
*
*  This function sets the uvs vector to the input
*
*  @param pUVs - Eigen::MatrixXf & - uvs vector
*
*/
void Geometry::Geometry::set_mUvs(Eigen::MatrixXf & pUVs)
{
	mUvs = pUVs;
}


/** @brief Sets the Normal Vector
*
*  This function sets the normal vector to the input
*
*  @param pNormal -  Eigen::MatrixXf & - normal vector
*
*/
void Geometry::Geometry::set_mNormals(Eigen::MatrixXf & pNormals)
{
	mNormals = pNormals;
}


/** @brief Sets the indices Vector
*
*  This function sets the indices vector to the input
*
*  @param pGeometry_indices - std::vector<unsigned int> & - indices vector
*
*/
void Geometry::Geometry::set_mGeometry_indices(MatrixXu & pGeometry_indices)
{
	mGeometry_indices = pGeometry_indices;
}


/** @brief Returns the geoemtry vector
*
*  This function returns the geometry vecotr
*
*  @return Eigen::MatrixXf - Geometry Vector
*
*/
Eigen::MatrixXf & Geometry::Geometry::get_mGeometry(void)
{
	return mGeometry;
}


/** @brief Returns the color vector
*
*  This function returns the color vecotr
*
*  @return Eigen::MatrixXf - color Vector
*
*/
Eigen::MatrixXf & Geometry::Geometry::get_mColors(void)
{
	return mColors;
}



/** @brief Returns the uvs vector
*
*  This function returns the uvs vecotr
*
*  @return Eigen::MatrixXf - uvs Vector
*
*/
Eigen::MatrixXf & Geometry::Geometry::get_mUvs(void)
{
	return mUvs;
}


/** @brief Returns the normal vector
*
*  This function returns the normal vecotr
*
*  @return Eigen::MatrixXf - normal Vector
*
*/
Eigen::MatrixXf & Geometry::Geometry::get_mNormals(void)
{
	return mNormals;
}


/** @brief Returns the indices vector
*
*  This function returns the indices vecotr
*
*  @return std::vector<unsigned int> - indices Vector
*
*/
MatrixXu & Geometry::Geometry::get_mGeometry_indices(void)
{
	return mGeometry_indices;
}


void Geometry::Geometry::UpdateColorAtIndex(unsigned int column, Eigen::Vector4f &new_color)
{
	mColors.col(mGeometry_indices.col(column)(0)) << new_color(0), new_color(1), new_color(2), new_color(3);
	mColors.col(mGeometry_indices.col(column)(1)) << new_color(0), new_color(1), new_color(2), new_color(3);
	mColors.col(mGeometry_indices.col(column)(2)) << new_color(0), new_color(1), new_color(2), new_color(3);

	return;
}


void Geometry::Geometry::UpdatePositionAtIndex(unsigned int column, Eigen::Vector3f &new_pos)
{
	mGeometry.col(mGeometry_indices.col(column)(0)) << new_pos(0), new_pos(1), new_pos(2);
	mGeometry.col(mGeometry_indices.col(column)(1)) << new_pos(0), new_pos(1), new_pos(2);
	mGeometry.col(mGeometry_indices.col(column)(2)) << new_pos(0), new_pos(1), new_pos(2);

	return;
}

void Geometry::Geometry::UpdatePositionAtCol(unsigned int column, Eigen::Vector3f &new_pos)
{
	mGeometry.col(column) << new_pos(0), new_pos(1), new_pos(2);

	return;
}

void Geometry::Geometry::UpdateColorAtCol(unsigned int column, Eigen::Vector4f &new_color)
{
	mColors.col(column) << new_color(0), new_color(1), new_color(2), new_color(3);

	return;
}



void Geometry::Geometry::getAABB(Eigen::Vector3f &minBB, Eigen::Vector3f &maxBB)
{
	Eigen::Vector3f v0, v1, v2;
	for (int j = 0; j < mGeometry_indices.cols(); ++j) {  //triangles 
		v0 = mGeometry.col(mGeometry_indices.col(j)(0));
		v1 = mGeometry.col(mGeometry_indices.col(j)(1));
		v2 = mGeometry.col(mGeometry_indices.col(j)(2));
		minBB(0) = std::min(minBB(0), v0(0));  //index + j - offset of vertex and 3 that make up triangle
		minBB(1) = std::min(minBB(1), v0(1));
		minBB(2) = std::min(minBB(2), v0(2));
		maxBB(0) = std::max(maxBB(0), v0(0));
		maxBB(1) = std::max(maxBB(1), v0(1));
		maxBB(2) = std::max(maxBB(2), v0(2));

		minBB(0) = std::min(minBB(0), v1(0));
		minBB(1) = std::min(minBB(1), v1(1));
		minBB(2) = std::min(minBB(2), v1(2));
		maxBB(0) = std::max(maxBB(0), v1(0));
		maxBB(1) = std::max(maxBB(1), v1(1));
		maxBB(2) = std::max(maxBB(2), v1(2));

		minBB(0) = std::min(minBB(0), v2(0));
		minBB(1) = std::min(minBB(1), v2(1));
		minBB(2) = std::min(minBB(2), v2(2));
		maxBB(0) = std::max(maxBB(0), v2(0));
		maxBB(1) = std::max(maxBB(1), v2(1));
		maxBB(2) = std::max(maxBB(2), v2(2));
	}

}


float Geometry::Geometry::getBoundingRadius(Eigen::Vector3f &minBB, Eigen::Vector3f &maxBB)
{
	Eigen::Vector3f origin = Eigen::Vector3f(0.0f, 0.0f, 0.0f);

	return sqrt(std::max(
		pow((minBB(0) - origin(0)), 2) + pow((minBB(1) - origin(1)), 2) + pow((minBB(2) - origin(2)), 2),
		pow((maxBB(0) - origin(0)), 2) + pow((maxBB(1) - origin(1)), 2) + pow((maxBB(2) - origin(2)), 2)
		)
		);
}


Eigen::Vector3f Geometry::Geometry::getTriangleNormal(int triangle) {
	Eigen::Vector3f v0 = getTriangleVertex(triangle, 0);
	Eigen::Vector3f v1 = getTriangleVertex(triangle, 1);
	Eigen::Vector3f v2 = getTriangleVertex(triangle, 2);
	Eigen::Vector3f normalVector = (v1 - v0).cross(v2 - v0);
	normalVector.normalize();
	return normalVector;
}

/** @brief Computes the area of a triangle.
*
*  @return float - area of the triangle.
*/
float Geometry::Geometry::getTriangleArea(int triangle, Eigen::Vector3f *outTriangleNormal) {
	Eigen::Vector3f v0 = getTriangleVertex(triangle, 0);
	Eigen::Vector3f v1 = getTriangleVertex(triangle, 1);
	Eigen::Vector3f v2 = getTriangleVertex(triangle, 2);
	Eigen::Vector3f normalVector = (v1 - v0).cross(v2 - v0);
	float norm = normalVector.norm();
	if (outTriangleNormal != NULL) *outTriangleNormal = normalVector / norm;
	return 0.5f*norm;
}
