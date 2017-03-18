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

#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
	unsigned int N = 100000;  // number of values generated
	unsigned int engineSelection;
	std::string histogramFileName;
	std::string rawFileName;
	std::string usefulDataFileName;

	// Requests sample size from the command line:
	std::cout << "Please enter the sample size N: ";
	std::cin >> N;
	std::cout << std::endl;

	// Get a random seed

	//use a random device
	std::random_device rd;

	// 1) Change random number generators
	std::mt19937_64 engine(rd());
	engineSelection = 1;
	//std::knuth_b engine(rd());
	//engineSelection = 2;
	//std::minstd_rand engine(rd());
	//engineSelection = 3;
	//std::ranlux48 engine(rd());
	//engineSelection = 4;

	// Setting the string file names according to pseudo-random engine:
	switch (engineSelection)
	{
	case 1:
		histogramFileName = "mt19937_64_histogram_results.txt";
		rawFileName = "mt19937_64_raw_results.txt";
		usefulDataFileName = "mt19937_64_useful_stats.txt";
		break;
	case 2:
		histogramFileName = "knuth_b_histogram_results.txt";
		rawFileName = "knuth_b_raw_results.txt";
		usefulDataFileName = "knuth_b_useful_stats.txt";
		break;
	case 3:
		histogramFileName = "minstd_rand_histogram_results.txt";
		rawFileName = "minstd_rand_raw_results.txt";
		usefulDataFileName = "minstd_rand_useful_stats.txt";
		break;
	case 4:
		histogramFileName = "ranlux48_histogram_results.txt";
		rawFileName = "ranlux48_raw_results.txt";
		usefulDataFileName = "ranlux48_useful_stats.txt";
		break;
	default:
		histogramFileName = "histogram_results.txt";
		rawFileName = "raw_results.txt";
		usefulDataFileName = "useful_stats.txt";
		break;
	}


	// Another seed intialization routine (this is just here for future reference for you.)
	// initialize the random number generator with time-dependent seed
	//uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	//std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
	//std::mt19937_64 e2;
	//e2.seed(ss);



	//  2) - Change distribution types
	//std::uniform_real_distribution<> dist(0, 1);  // example of a uniform distribution
	//std::uniform_real_distribution<> dist(0, 100);  // example of a uniform distribution
	//std::normal_distribution<> dist(50, 10);    // example of a normal distribution
	std::normal_distribution<> dist(0,0.33);    // example of a normal distribution
	//std::chi_squared_distribution <double> dist(50.0);
	//std::bernoulli_distribution dist(0.5);
	//std::poisson_distribution<int> dist(50.0);
	//std::geometric_distribution<int> dist(0.5);


	auto generator = std::bind(dist, engine);

	// 3) Play with N
	//unsigned int N = 100000;  // number of values generated
	//double randomValue;
	double x;
	double y;

	double radius;
	double angleTheta;

	std::map<int, int> hist; //Counts of discrete values
	//std::vector<double> raw; //raw random values 
	

	// A two dimensional object:
	std::multimap<double,double> raw;


	for (unsigned int i = 0; i < N; ++i) {
		//randomValue = generator();
		radius = generator();
		angleTheta = (2 * M_PI * generator());

		x = (radius * cos(angleTheta));
		y = (radius * sin(angleTheta));
		
		//++hist[std::round(randomValue)]; // count the values
		//raw.push_back(randomValue);  //push the raw values

		//Input values into a two dimensional structure
		// The key on the map is the x value
		// The correspondent to each key is the y value
		raw.insert(std::pair<double,double> (x, y));
		

	}

	for (auto p : hist) {
		
		// Uncomment if you want to see the values
		//std::cout << std::fixed << std::setprecision(1) << std::setw(2)
		//	<< p.first << " -  "<< p.second << std::endl;

		//std::cout << std::fixed << std::setprecision(1) << std::setw(2)
		//	<< p.first << "  " << std::string(p.second / (N/500), '*') << std::endl;

	}


	// Print Results to File
	std::ofstream myfile;
	/*myfile.open(histogramFileName.c_str());

	myfile << "Sample size N: " << N << std::endl;

	for (auto p : hist) {
		myfile << std::fixed << std::setprecision(1) << std::setw(2)
			<< p.first << "\t" << p.second  << std::endl;
	}
	myfile.close(); */

	myfile.open(rawFileName.c_str());

	myfile << "Sample size N: " << N << std::endl;

	for (auto p : raw) {
		myfile << std::fixed << std::setprecision(5) << std::setw(2)
			<< p.first << "\t" << p.second << std::endl;
	}
	myfile.close();


	//if you choose to write useful stats here
	/*myfile.open(usefulDataFileName.c_str());

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
	
	myfile.close();*/

}