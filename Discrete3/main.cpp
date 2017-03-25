#include <iostream>
#include <functional>   
#include <numeric>  
#include <map>
#include "markov.h"

int main(){
  //SIMULATE DISCRETE TIME MARKOV CHAIN
  std::vector< std::vector<double> > matrix(11,std::vector<double> (11)); //initializes a 11x11 matrix with zeros

  //set transition matrix
  for (int i = 0; i < 11; i++)
  {
	  for (int j = 0; j < 11; j++)
	  {
		  matrix[i][j] = 0.0;
	  }
  }

  //set transition matrix
  int j = 0;
  int k =11;
  int countIter = 0;
  double pIncrease = (2.0 / 6.0);
  for (int i = 0; i < k; i++)
  {
	  j = i + 1;

	  
	  countIter = 0;

	  // We only need to do it six times - six rolls.
	  for (j; j < k; j++)
	  {
		  if (countIter < 7)
		  {
			  matrix[i][j] = (1.0 / 6.0);
			  countIter++;
		  }


		  if (i >= (k - 6) && (j == k-1))
		  {
			  matrix[i][j] = pIncrease;
			  pIncrease = pIncrease + (1.0 / 6.0);
		  }
	  }

	
  }

  // Last state by itself
  matrix[k - 1][k - 1] = 1;

  for (int m = 0; m < 11; m++)
  {
	  std::cout << "This is state: " << m << std::endl;

	  for (int n = 0; n < 11; n++)
	  {
		  std::cout << matrix[m][n] << " ";
	  }

	  std::cout << std::endl;
  }

  std::cout << std::endl;



  int steps = 100;
  int start = 0;
  double T = 8.5;
  
  //simulate discrete time Markov Chain
  //unsigned int N = 100000;
  //std::map<int, int> hist;
  std::vector<int> discreteMC;
  //for (unsigned int i = 0; i < N; ++i){
	 discreteMC = DTMC(matrix, steps, start);
//	  ++hist[std::round(discreteMC.back())];
//  }
  //Returns an array with the states at each step of the discrete-time Markov Chain
  //The number of transitions is given by steps. The initial state is given by start 
  //(the states are indexed from 0 to n-1 where n is the number of arrays in transMatrix).

  for (auto elem : discreteMC)
	  std::cout << elem << std::endl;

  std::cout  << std::endl;

//  for (auto p : hist)
//	  std::cout << p.first << "\t" << p.second << std::endl;


   std::cout<<std::endl << "End State is: " << discreteMC.back() << std::endl << std::endl;





  return 0;
}