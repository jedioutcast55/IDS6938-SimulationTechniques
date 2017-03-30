// TransitionMatrix.h
int size = 101;  //Start with a 101 x 101 matrix

Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::MatrixXf ShootsLaddersTransitionMatrix(size, size);
Eigen::VectorXf v(size);
Eigen::VectorXf v_ShootsLadder(size);

//unsigned int ROLLS = 44; //TODO
unsigned int ROLLS = 300;

double prob = (1.0/6.0) ;  //TODO




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
			if (countIter < 6)
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

	// The last column of the last row has to be done manually.
	TransitionMatrix((size - 1), (size - 1)) = 1.0;


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

	
	
}

void SetShootsLaddersTransitionMatrix()
{
	ShootsLaddersTransitionMatrix = TransitionMatrix;

	// Build the shoots and ladders
	for (int i = 0; i < size; i++)
	{
		// Ladders
		if (ShootsLaddersTransitionMatrix(i, 3) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 3) = 0;
			ShootsLaddersTransitionMatrix(i, 19) = (ShootsLaddersTransitionMatrix(i, 19) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 15) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 15) = 0;
			ShootsLaddersTransitionMatrix(i, 37) = (ShootsLaddersTransitionMatrix(i, 37) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 22) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 22) = 0;
			ShootsLaddersTransitionMatrix(i, 42) = (ShootsLaddersTransitionMatrix(i, 42) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 25) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 25) = 0;
			ShootsLaddersTransitionMatrix(i, 64) = (ShootsLaddersTransitionMatrix(i, 64) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 41) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 41) = 0;
			ShootsLaddersTransitionMatrix(i, 73) = (ShootsLaddersTransitionMatrix(i, 73) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 53) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 53) = 0;
			ShootsLaddersTransitionMatrix(i, 74) = (ShootsLaddersTransitionMatrix(i, 74) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 63) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 63) = 0;
			ShootsLaddersTransitionMatrix(i, 86) = (ShootsLaddersTransitionMatrix(i, 86) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 76) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 76) = 0;
			ShootsLaddersTransitionMatrix(i, 91) = (ShootsLaddersTransitionMatrix(i, 91) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 84) > 0)  // This is a ladder
		{
			ShootsLaddersTransitionMatrix(i, 84) = 0;
			ShootsLaddersTransitionMatrix(i, 98) = (ShootsLaddersTransitionMatrix(i, 98) + prob);
		}


		// Snakes.
		if (ShootsLaddersTransitionMatrix(i, 11) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 11) = 0;
			ShootsLaddersTransitionMatrix(i, 7) = (ShootsLaddersTransitionMatrix(i, 7) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 18) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 18) = 0;
			ShootsLaddersTransitionMatrix(i, 13) = (ShootsLaddersTransitionMatrix(i, 13) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 28) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 28) = 0;
			ShootsLaddersTransitionMatrix(i, 12) = (ShootsLaddersTransitionMatrix(i, 12) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 36) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 36) = 0;
			ShootsLaddersTransitionMatrix(i, 34) = (ShootsLaddersTransitionMatrix(i, 34) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 47) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 47) = 0;
			ShootsLaddersTransitionMatrix(i, 26) = (ShootsLaddersTransitionMatrix(i, 26) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 77) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 77) = 0;
			ShootsLaddersTransitionMatrix(i, 16) = (ShootsLaddersTransitionMatrix(i, 16) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 83) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 83) = 0;
			ShootsLaddersTransitionMatrix(i, 39) = (ShootsLaddersTransitionMatrix(i, 39) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 92) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 92) = 0;
			ShootsLaddersTransitionMatrix(i, 75) = (ShootsLaddersTransitionMatrix(i, 75) + prob);
		}

		if (ShootsLaddersTransitionMatrix(i, 99) > 0)  // This is a Snake
		{
			ShootsLaddersTransitionMatrix(i, 99) = 0;
			ShootsLaddersTransitionMatrix(i, 70) = (ShootsLaddersTransitionMatrix(i, 70) + prob);
		}
	
	}

}