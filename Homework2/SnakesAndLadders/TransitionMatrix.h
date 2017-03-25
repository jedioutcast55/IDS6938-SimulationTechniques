// TransitionMatrix.h
int size = 101;  //Start with a 101 x 101 matrix

Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);

unsigned int ROLLS = 50; //TODO

double prob = 0.0 ;  //TODO




void SetTransitionMatrix()
{
	
	TransitionMatrix.setZero();

	
	int j = 0;
	int countIter = 0;
	double pIncrease = (2.0 / 6.0);

	//TODO
	// Building the transition matrix
	for (int i = 0; i < size; i++)
	{
		j = i + 1;  
		countIter = 0;
	
		for (j; j < size; j++)
		{
			//TransitionMatrix(i, j + 1) = (1.0 / 6.0);
			if (countIter < 7)
			{
				TransitionMatrix(i, j) = (1.0 / 6.0);
				countIter++;
			}

			// Check for the end of rows and colums
			if (i >= (size - 6) && (j == size - 1))
			{
				TransitionMatrix(i, j) = pIncrease;
				pIncrease = pIncrease + (1.0 / 6.0);
			}

		}
	} 

	// Need to complete the last six rows
	/*int  k = 95;
	int l = 4;

	double increaseP = 2.0;

	for (k; k < 100; k++)
	{
		j = k;
		for (j; j < (k + l); j++)
		{
			TransitionMatrix(k, j + 1) = (1.0 / 6.0);
		}

		// Update the last column
		TransitionMatrix(k, j + 1) = (increaseP/ 6.0);
		increaseP = increaseP + 1;
		l = l - 1;

	} */

	// The last column of the last row has to be done manually.
	TransitionMatrix((size - 1), (size - 1)) = 1.0;
	
}