//Eulers Method to solve a differential equation
#define _USE_MATH_DEFINES

#include <cmath>
#include<iostream>
#include<iomanip>
#include<math.h>
#include <string>
#include <sstream>
#include <fstream>

/*
Compute the dy/dx
*/
double df(double x, double y)            //function for defining dy/dx
{
    return y - (1.0 / 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
}


/*
Compute the exact answer
*/
double exact(double x)            //function for defining dy/dx
{
    return exp(x / 2.0)*sin(5.0 * x);
}


/*
Calculate the error
*/
double error(double exact, double approx)
{
    return abs(exact - approx) / exact;
}


/*
This implements the Euler method equation
*/
double rk1(double y, double h, double x)
{
    return y + h * df(x, y);
}


/*
This implements the Midpoint method equation
*/
double rk2(double y, double h, double x)
{
	double k1 = df(x, y);
	double h_half = h / 2.0;
    return  y + h * df( x + h_half, y + (h_half * k1) );
}


/*
This implements the RK4 method equation
*/
double rk4(double y, double h, double x)
{
	double h_half = h/2.0;
	double k1 = df(x, y);
	double k2 = df(x+ h_half, y + (h_half * k1));
	double k3 = df(x + h_half, y + (h_half * k2));;
	double k4 = df(x + h, y + (h * k3));;
    return  y + h * (1.0 / 6.0)*(k1 + 2.0 * k2 + 2.0 * k3 + k4);
}



std::string toString(double x, double y_euler, double y_midpoint, double y_RK4, double y_exact, double presision)
{
	
	std::ostringstream out;
	out << std::setprecision(presision) << x << "\t";
	out << std::setprecision(presision) << y_euler << "\t";
	out << std::setprecision(presision) << y_midpoint << "\t";
	out << std::setprecision(presision) << y_RK4 << "\t";
	out << std::setprecision(presision) << y_exact << "\t";
	out << std::setprecision(presision) << error(exact(x), y_euler) << "%\t";
	out << std::setprecision(presision) << error(exact(x), y_midpoint) << "%\t";
	out << std::setprecision(presision) << error(exact(x), y_RK4)<<"%";
	
	return   out.str();
}

void implementMethodEquationbyTimeStep(double _y_euler, double _y_midpoint, double _y_RK4, double _x, double _h, int loopCounter, std::ofstream* writeDataFile)
{
	std::cout << std::fixed << std::showpoint;
	// Header information for column printouts
	std::cout << "x" << "\t" << "y (Euler)" << "\t" << "y (midpoint)" << "\t" << "y (RK4)" << "\t"
		<< "EXACT" << "\t\t" << "%Err(E)" << "\t\t" << "%Err(M)" << "\t\t" << "%Err(RK4)" << std::endl;
	std::cout << "----" << "\t" << "----------" << "\t" << "----------" << "\t" << "----------"
		<< "\t" << "----------" << "\t" << "-------" << "\t\t" << "-------" << "\t\t" << "------" << std::endl;

	//intial values
	std::cout << toString(_x, _y_euler, _y_midpoint, _y_RK4, exact(_x), 10) << std::endl;

	*writeDataFile << "This is for Time Step h = " << _h <<std::endl;

	*writeDataFile << "x" << "\t" << "y (Euler)" << "\t" << "y (midpoint)" << "\t" << "y (RK44)" << "\t"
		<< "EXACT" << "\t\t" << "%Err(E)" << "\t\t" << "%Err(M)" << "\t\t" << "%Err(RK4)" << std::endl;

	*writeDataFile << "----" << "\t" << "----------" << "\t" << "----------" << "\t" << "----------"
		<< "\t" << "----------" << "\t" << "-------" << "\t\t" << "-------" << "\t\t" << "------" << std::endl;

	*writeDataFile << toString(_x, _y_euler, _y_midpoint, _y_RK4, exact(_x), 10) << std::endl;

	for (int i = 0; i < loopCounter; i++)
	{
		_y_euler = rk1(_y_euler, _h, _x);  //caculate y_{i+1}
		_y_midpoint = rk2(_y_midpoint, _h, _x);  //caculate y_{i+1}
		_y_RK4 = rk4(_y_RK4, _h, _x);  //caculate y_{i+1}
		_x = _x + _h;       //increment x

		std::cout << toString(_x, _y_euler, _y_midpoint, _y_RK4, exact(_x), 10) << std::endl;

		// There is a more efficient way to write to a file as to do of the calculation first and
		// then write to a file only access I/O when needed, but for convinience I will use this method.
		// Remember I/O is very expensive !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		*writeDataFile << toString(_x, _y_euler, _y_midpoint, _y_RK4, exact(_x), 10) << std::endl;
	}

}




int main()
{
	double y_euler = 0.0;
	double y_midpoint = 0.0;
	double y_RK4 = 0.0;
	double x = 0.0;
	double h = 0.1;
	int precisionLoop = 0;
    
	

	// Implement all three numberica method with time step of (h=0.1)
	// Since we are running the numerical methods from 1 to 10, the loop must be run 10 divided by the time step h.  Careful we are using mix types. 
	// For this case it will work!!!!!!!!!!!!!!!!!!!!!!!!
	precisionLoop = (10 / h);

	// Create a file to save data:
	std::ofstream dataFile;
	dataFile.open("NumericalMethodDataFile.txt");

	
	// Time step at h= 0.1
	implementMethodEquationbyTimeStep(y_euler, y_midpoint, y_RK4, x, h, precisionLoop, &dataFile);

	dataFile << std::endl;
	std::cout << std::endl;

	// Reset all values and do it for a different time step
	y_euler = 0.0;
	y_midpoint = 0.0;
	y_RK4 = 0.0;
	x = 0.0;
	h = 0.05;
	precisionLoop = 0;

	// Calculate precision loop:
	precisionLoop = (10 / h);

	// Time step at h= 0.05
	implementMethodEquationbyTimeStep(y_euler, y_midpoint, y_RK4, x, h, precisionLoop, &dataFile);

	dataFile << std::endl;
	std::cout << std::endl;

	// Reset all values and do it for a different time step
	y_euler = 0.0;
	y_midpoint = 0.0;
	y_RK4 = 0.0;
	x = 0.0;
	h = 0.5;
	precisionLoop = 0;

	// Calculate precision loop:
	precisionLoop = (10 / h);

	// Time step at h= 0.5
	implementMethodEquationbyTimeStep(y_euler, y_midpoint, y_RK4, x, h, precisionLoop, &dataFile);

	dataFile << std::endl;
	std::cout << std::endl;

	// Reset all values and do it for a different time step
	y_euler = 0.0;
	y_midpoint = 0.0;
	y_RK4 = 0.0;
	x = 0.0;
	h = 1.0;
	precisionLoop = 0;

	// Calculate precision loop:
	precisionLoop = (10 / h);

	// Time step at h= 1.0
	implementMethodEquationbyTimeStep(y_euler, y_midpoint, y_RK4, x, h, precisionLoop, &dataFile);

	// Close the file
	dataFile.close();


    return 0;
}