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



// Save Game Matrix to file
void saveGameMatrixToFile(std::ofstream *file, Eigen::MatrixXf *matrixPTR)
{
	// 
	(*file) << "Game Matrix" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			(*file) << (*matrixPTR)(i, j) << "\t";
		}
		(*file) << std::endl;
	}

	(*file) << std::endl;
}
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

void printMatrixToTheScreen(int maxRows, int maxColumns, Eigen::MatrixXf *matrix)
{
	for (int m = 0; m < maxRows; m++)
	{

		for (int n = 0; n < maxColumns; n++)
		{
			std::cout << (*matrix)(m, n) << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

}

void vectorMatrixMultiplication(bool matrixHealth, int rows, std::ofstream *file, Eigen::MatrixXf *matrixPTR)
{
	std::list<Eigen::VectorXf> listVectorXf;
	// If we have a vlid matrix:
	if (matrixHealth)
	{
		for (int i = 0; i < rows; i++)
		{
			v = v.transpose() * (*matrixPTR);

			// Input all data into a structure:
			listVectorXf.push_back(v);
		}

		(*file) << "Game Matrix Probability" << std::endl;
		for (auto p : listVectorXf)
		{
			std::cout << p.transpose();

			// Print vector to file.
			for (int k = 0; k < size; k++)
			{
				(*file) << p.transpose()(k) << "\t";
			}

			(*file) << std::endl;
			//myfile << p.transpose() << std::endl;
			//myfile << std::endl;
			//std::cout << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Not a well form matrix  !!!!!!!!!!!!!!!!!!" << std::endl;
		std::cout << std::endl;
	}

}

int main(){

	SetTransitionMatrix();

	SetShootsLaddersTransitionMatrix();

	bool nullGameHealth = false;

	bool snakeLaddersMatrixHealth = false;

	int rows = 0;

	// Check the matrix
	nullGameHealth = checkTransitionMatrix(&TransitionMatrix);
	snakeLaddersMatrixHealth = checkTransitionMatrix(&ShootsLaddersTransitionMatrix);

   
	// Print the matrix to the screen
	printMatrixToTheScreen(TransitionMatrix.rows(), TransitionMatrix.cols(), &TransitionMatrix);

	printMatrixToTheScreen(ShootsLaddersTransitionMatrix.rows(), ShootsLaddersTransitionMatrix.cols(), &ShootsLaddersTransitionMatrix);

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	//std::ofstream myfile;
	//myfile.open("markov_results.txt");


   // TODO add Markov vector - Matrix multiplication

	// Set rows
	rows = TransitionMatrix.rows();

	// Open file to print:
	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	//saveGameMatrixToFile(&myfile, &TransitionMatrix);
	//vectorMatrixMultiplication(nullGameHealth, rows, &myfile, &TransitionMatrix);

	saveGameMatrixToFile(&myfile, &ShootsLaddersTransitionMatrix);
	vectorMatrixMultiplication(snakeLaddersMatrixHealth, size, &myfile, &ShootsLaddersTransitionMatrix);



		//for (int i = 0; i < rows; i++)
		//{
		//std::cout << v.transpose() << std::endl;
		//myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats
		//}

		//std::cout <<  v.transpose() << std::endl;
		//myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats

		myfile.close();
	
  return 1;
}