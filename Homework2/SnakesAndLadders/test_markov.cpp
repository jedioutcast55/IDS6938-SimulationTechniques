#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"
#include <list>


// Check that each row in a Eigen Matrix equates to one.
bool checkTransitionMatrix(Eigen::MatrixXf *eigenMatrix)
{
	bool matrixCheck = false;
	float sum = 0;


	for (int i = 0; i < eigenMatrix->rows(); i++)
	{
		// reset sum for each row
		sum = 0;
		for (int j = 0; j < eigenMatrix->cols(); j++)
		{
			sum = sum + ((*eigenMatrix)(i, j));
		}


		if (sum > 0.90 && sum < 1.2)
		{
			matrixCheck = true;
		}
		else
		{
			matrixCheck = false;
			// You can return at this point since all the rows must add to one.
			return matrixCheck;
		}
	}

	return matrixCheck;
}

int main(){

	SetTransitionMatrix();

	bool matrixHealth = false;

	

	std::cout << std::endl;
	std::cout << "The number of rows: " << TransitionMatrix.rows() << std::endl;
	std::cout << "The number of columns: " << TransitionMatrix.cols() << std::endl;
	std::cout << std::endl;

	// Check the matrix
	matrixHealth = checkTransitionMatrix(&TransitionMatrix);


	int rows = TransitionMatrix.rows();
	int columns = TransitionMatrix.cols();

	for (int m = 0; m < rows; m++)
	{

		for (int n = 0; n < columns; n++)
		{
			std::cout << TransitionMatrix(m, n) << " ";
		}
		
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	//std::ofstream myfile;
	//myfile.open("markov_results.txt");


   // TODO add Markov vector - Matrix multiplication

	std::list<Eigen::VectorXf> listVectorXf;
	// If we have a vlid matrix:
	if (matrixHealth)
	{
		for (int i = 0; i < rows; i++)
		{
			v = v.transpose() * TransitionMatrix;

			// Input all data into a structure:
			listVectorXf.push_back(v);
		}

		// Print Results to File
		std::ofstream myfile;
		myfile.open("markov_results.txt");

		for (auto p : listVectorXf)
		{
			std::cout << p.transpose();
			myfile << p.transpose() << std::endl;
			myfile << std::endl;
			std::cout << std::endl;
		}

		//for (int i = 0; i < rows; i++)
		//{
		//std::cout << v.transpose() << std::endl;
		//myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats
		//}

		//std::cout <<  v.transpose() << std::endl;
		//myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats

		myfile.close();
	}
	else
	{
		std::cout << std::endl;
		std::cout << "The health of the matrix is: " << matrixHealth << std::endl;
		std::cout << "No appropriate matrix" << std::endl;
		std::cout << std::endl;
	}

	
	
	


  return 1;
}