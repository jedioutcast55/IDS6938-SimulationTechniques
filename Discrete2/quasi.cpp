#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <functional> 
#include <numeric>     

#include "sobol.hpp"

#define _USE_MATH_DEFINES
#include <math.h>

# define DIM_MAX 2

int dim_num = 1;
float *r;
int seed;
int seed_in;
int seed_out;

double getQuasiRandomNumber(int *seed)
{
	i4_sobol(dim_num, seed, r);
	return r[0];
}


void getNDimQuasiRandomNumber(int *seed, int dim_number, float *r)
{
	i4_sobol(dim_number, seed, r);
}




int main()
{
	unsigned int N = 100000;  // number of values generated

	// Requests sample size from the command line:
	std::cout << "Please enter the sample size N: ";
	std::cin >> N;
	std::cout << std::endl;


	r = new float[DIM_MAX];

	int newSeed = 0;

	//use a random device
	std::random_device rd;
	// Another seed intialization routine (this is just here for future reference for you.)
	// initialize the random number generator with time-dependent seed
	uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	//std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	// 2 different ways to get a random starting seed
	//seed = rd();
	//srand(time(NULL));
	newSeed = rd()/1000.0;



	// 3) Play with N
	//unsigned int N = 100000;  // number of values generated
	//double randomValue;
	//std::map<int, int> hist; //Counts of discrete values
	//std::vector<double> raw; //raw random values 
	//std::vector<double> xValues;
	
	double x = 0;
	double y = 0;

	double radius;
	double angleTheta;

	// A two dimensional object:
	std::multimap<double, double> raw;
	


	/*for (unsigned int i = 0; i < N; ++i) {
		//randomValue = 0 + getQuasiRandomNumber(&seed) * 100;	
		x = 0 + getQuasiRandomNumber(&seed);
		y = 0.0;		
		
		//++hist[std::round(randomValue)]; // count the values
		//raw.push_back(randomValue);  //push the raw values

		// The correspondent to each key is the y value
		 //raw.insert(std::pair<double, double>(x, y));
		xValues.push_back(x);
	}


	// Added for Unit square:
	for (auto p : xValues)
	{
	
		y = 0 + getQuasiRandomNumber(&newSeed);

		raw.insert(std::pair<double, double>(p, y));    
	}*/


	// Do this for Unit Circle:
	for (unsigned int i = 0; i < N; ++i) 
	{
		radius = 0 + getQuasiRandomNumber(&seed);
		angleTheta = (2 * M_PI * (0 + getQuasiRandomNumber(&newSeed)));


		x = (radius * cos(angleTheta));
		y = (radius * sin(angleTheta));

		raw.insert(std::pair<double, double>(x, y));
	
	}


	//for (auto p : hist) {

		// Uncomment if you want to see the values
		//std::cout << std::fixed << std::setprecision(1) << std::setw(2)
		//	<< p.first << " -  "<< p.second << std::endl;

		//std::cout << std::fixed << std::setprecision(1) << std::setw(2)
		//	<< p.first << "  " << std::string(p.second / (N / 500), '*') << std::endl;

	//}


	// Print Results to File
	std::ofstream myfile;
	/*myfile.open("QuasiSobolo_histogram_results.txt");

	myfile << "Sample size N: " << N << std::endl;

	for (auto p : hist) {
		myfile << std::fixed << std::setprecision(1) << std::setw(2)
			<< p.first << "\t" << p.second << std::endl;
	}
	myfile.close(); */

	myfile.open("QuasiSobolo_raw_results.txt");

	myfile << "Sample size N: " << N << std::endl;

	/*for (auto p : raw) {
		myfile << std::fixed << std::setprecision(5) << std::setw(2)
			<< p << std::endl;
	} */

	for (auto p : raw)
	{
		myfile << std::fixed << std::setprecision(5) << std::setw(2)
			<< p.first << "\t" << p.second << std::endl;
	}
	myfile.close();


	//if you choose to write useful stats here
	/*myfile.open("QuasiSobolo_useful_stats.txt");

	myfile << "Sample size N: " << N << std::endl;

	double sum = std::accumulate(raw.begin(), raw.end(), 0.0);
	double mean = sum / raw.size();
	myfile << "mean: " << mean << std::endl;
	std::cout << "mean: " << mean << std::endl;

	std::vector<double> diff(raw.size());
	std::transform(raw.begin(), raw.end(), diff.begin(),
		std::bind2nd(std::minus<double>(), mean));
	double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	double stdev = std::sqrt(sq_sum / raw.size());
	myfile << "stdev: " << stdev << std::endl;
	std::cout << "stdev: " << stdev << std::endl;

	myfile.close(); */

}