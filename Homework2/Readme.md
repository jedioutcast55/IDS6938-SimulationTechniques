#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

** Student: Roberto Cabrera

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #2. 

The assignment is due: **Tuesday, March 28 at 11:59PM (EST)**
Dr. Kider: I am requesting two day extension.  

My new date will be ** Thursday, March 30, 2017 at 11:59PM (EST) **  This will use the remaining days for the three day grace period you provided early in the semester.

asdfasdf
sadfsad


# Introduction
A Discrete-event Model simulates a complex system as an ordered sequence of well-defined events. Mathematically Discrete-event models use Markov Processes, Queuing systems, events, probability / statistics, and random variables. The purpose of this assignment is to learn the mathematical foundations, how to program these models, and how to simulate them. The assignment is due Tuesday, March 28, 2017 at 11:59 P.M.

Major parts for the Assignment
You can think of the assignment broken up to 4 major parts:
* Empirical Tests of Randomness
* Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations)
* Discrete Event Simulation - Queue Simulation
* Composing a final report

The goal of this assignment is to become familiar with the concepts in the second third of the class. You will be expected to compose a *final report* which demonstrates your understanding on the material in each section of the assignment. Be visual! - Pictures say a thousand words so you do not have to. Show off your different configurations and really explore the assignment.

# Assignment
##Part 0 - Getting Started
Read the assignment. Sync your fork with the [main IDS6938 repository](https://github.com/hepcatjk/IDS6938-SimulationTechniques). Use CMake to create project files for the Homework 2 assignment (*Hint: and Discrete Lecture folders*). Set your *startup project* to the correct project. Test building and executing the homework 2 project. Look over and understand the framework and find the functions you need to edit for the assignment.



##Part 1: Empirical Tests of Randomness (20 pts).
We looked at different ways to generate [pseudo-random numbers](https://en.wikipedia.org/wiki/Pseudorandom_number_generator) and [quasi random numbers](https://en.wikipedia.org/wiki/Low-discrepancy_sequence). Generating random numbers are crucial to Discrete-Event simulations which rely on random variables and stochastic processes. This problem explores different random number generators, distributions, and statistics. Different [C++ pseudo-random numbers engines are instantiated](http://www.cplusplus.com/reference/random/) already for you. Also a a wide variety of standard distributions are implemented. Two quasi random number generators are also provided.
* **(a) - 3pts:** Output the results of five different random number engines, using a uniform distribution for values between [0-100]. Generate useful charts and statistics from the output to analyze how uniform these values truly are. You are expected to look at some advanced statistics and test, for example: tests like the Kolmogorov-Smirnov test, Chi-square test, Autocorrelation test, and Spearman’s Rank Correlation Coefficient are a few examples of ones your could use.)
I will be using the following pseudo-random geneartor number engines:
 1) mt19937_64
 2) knuth_b
 3) minstd_rand
 4) ranlux48
 5) Quasi-sobolo
 The code use for this part resides under the Discrete2 folder.  The code for the first four engines resides in random.cpp and for Quadi-sobolo it start on quasi.cpp.  For the uniformity test I will be using the chi-square test (Chapter 2 RANDOM NUMBERS).
 
 1) mt19937_64
 ![](HW2Data/Part1/MT19937_64_Histogram.PNG?raw=true)
 Figure 1: Shows the histrogram for pseudo-random number generator mt19937_64 uniformity for sample size of 100000.
 
 For the chi-square test for uniformity is a goodness-of-fit test.  Using the null hypothesis, H0 Data came from a uniform [0,100] distribution. Ha: It did no come from this distribution.using a 95% confidence interval and using excel functions CHIINV() to attained a critical value and comparing with the summation of (Expected Values - Observer Values) Square divided by Expected Values.  Is this value is greated than the critical value then the null hypothesis will be rejected.  This method is use to approximate within confidence level of 95% that the random number generators approximate uniformity.  The next figure shows the result for the pseudo-random number generator mt19937_64.
 
 ![](HW2Data/Part1/mt19937_64_chi_square_test.PNG?raw=true)
 Figure 2: MT19937_64 Chi-square test result.
 The complete calculation can be found in IDS6938-SimulationTechniques\Homework2\HW2Data\Part1\Part1_pseudoRandomNumbersGenerator_MT19937_64.xlsx
    
 2) knuth_b
  ![](HW2Data/Part1/Knuth_b_Histogram.PNG?raw=true)
 Figure 3: Shows the histrogram for pseudo-random number generator knuth_b uniformity for sample size of 100000.
 
  ![](HW2Data/Part1/Knuth_b_chi_square_test.PNG?raw=true)
 Figure 4: knuth_b Chi-square test result.
 The complete calculation can be found in IDS6938-SimulationTechniques\Homework2\HW2Data\Part1\Part1_pseudoRandomNumbersGenerator_Knuth_b.xlsx
 
 3) minstd_rand
  ![](HW2Data/Part1/Minstd_rand_Histogram.PNG?raw=true)
 Figure 5: Shows the histrogram for pseudo-random number generator minstd_rand uniformity for sample size of 100000.
 
  ![](HW2Data/Part1/Minstd_rand_chi_square_test.PNG?raw=true)
 Figure 6: minstd_rand Chi-square test result.
 The complete calculation can be found in IDS6938-SimulationTechniques\Homework2\HW2Data\Part1\Part1_pseudoRandomNumbersGenerator_Minstd_rand.xlsx
 4) ranlux48
   ![](HW2Data/Part1/Ranlux48_Histogram.PNG?raw=true)
 Figure 7: Shows the histrogram for pseudo-random number generator ranlux48 uniformity for sample size of 100000.
 
  ![](HW2Data/Part1/Ranlux_chi_square_test.PNG?raw=true)
 Figure 8: ranlux48 Chi-square test result.
 The complete calculation can be found in IDS6938-SimulationTechniques\Homework2\HW2Data\Part1\Part1_pseudoRandomNumbersGenerator_Ranlux48.xlsx
 5) Quasi-sobolo 
 ![](HW2Data/Part1/Quasi_sobolo_Histogram.PNG?raw=true)
 Figure 9: Shows the histrogram for pseudo-random number generator Quasi-sobolo uniformity for sample size of 100000.
 
  ![](HW2Data/Part1/Quasi_sobolo_chi_square_test.PNG?raw=true)
 Figure 10: Quasi-sobolo Chi-square test result.
 The complete calculation can be found in IDS6938-SimulationTechniques\Homework2\HW2Data\Part1\Part1_pseudoRandomNumbersGenerator_QuasiSobolo.xlsx

* **(b) - 2pts:**  Vary *N* (amount of samples). How do things change.
Following are the graphics for all the previous pseudo-random engines with varying samples.  The samples use N as 100, 1000, and 10000.  With uniform distribution of numbers from 0 - 100.
 1) mt19937_64
 ![](HW2Data/Part1/MT19937_DifferentSamples.PNG?raw=true)
 Figure 11: Pseudo Random Number Generator mt19937_64 with varying samples of 100, 1000, and 10000.
 
 2) knuth_b
 ![](HW2Data/Part1/Knuth_B_DifferentSamples.PNG?raw=true)
 Figure 12: Pseudo Random Number Generator mt19937_64 with varying samples of 100, 1000, and 10000.
 
 3) minstd_rand
 ![](HW2Data/Part1/Minstd_rand_DifferentSamples.PNG?raw=true)
 Figure 13: Pseudo Random Number Generator mt19937_64 with varying samples of 100, 1000, and 10000.
 
 4) ranlux48
 ![](HW2Data/Part1/Ranlux48_DifferentSamples.PNG?raw=true)
 Figure 14: Pseudo Random Number Generator mt19937_64 with varying samples of 100, 1000, and 10000.
 
 5) Quasi-sobolo
 ![](HW2Data/Part1/QuasiSobolo_DifferentSamples.PNG?raw=true)
 Figure 15: Pseudo Random Number Generator mt19937_64 with varying samples of 100, 1000, and 10000.
 
 It can be seen the pseudo number generators you can start to see some patterns, speacially when start the number of samples.  

* **(c) - 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.
The pseudo-number generator to be use is mt19937_64.  With this engine the following distritubions:
  1) Normal Distribution
     ![](HW2Data/Part1/MT19937_NormalDistribution.PNG?raw=true)
     Figure 16: Historgram of Pseudo-Random Number Generator MT19937_64, sample size of 10000, and normal distribution    
     mean set to 50.0 and std distribution of 12.5.
     
  2) Chi Square Distribution
   ![](HW2Data/Part1/MT19937_ChiSquareDistribution.PNG?raw=true)
     Figure 17: Historgram of Pseudo-Random Number Generator MT19937_64, sample size of 10000, and chi-square 
     distribution mean set to 50.0.
     
  3) Bernoulli Distribution
  ![](HW2Data/Part1/MT19937_BernoulliDistribution.PNG?raw=true)
     Figure 18: Historgram of Pseudo-Random Number Generator MT19937_64, sample size of 10000, and bernoulli distribution 
     with a 50/50 (0.5) distribution.
     
  4) Poisson Distribution
  ![](HW2Data/Part1/MT19937_PoissonDistribution.PNG?raw=true)
     Figure 19: Historgram of Pseudo-Random Number Generator MT19937_64, sample size of 10000, and poisson distribution 
     with a mean of 50.0.
     
  5) Geometric Distribution
  ![](HW2Data/Part1/MT19937_GeometricDistribution.PNG?raw=true)
     Figure 20: Historgram of Pseudo-Random Number Generator MT19937_64, sample size of 10000, and geometric distribution 
     with a mean of 50.0.

* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.

![](HW2Data/Part1/UnitSquareUniformDistribution.PNG?raw=true)
Figure 21: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, ranlux48, and Quasi-sobolo with a uniform distribution.

* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)

This section will show the different engines with different distribution:
1) Normal Distribution:
![](HW2Data/Part1/UnitSquareNormalDistribution.PNG?raw=true)
Figure 22: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a normal distribution.
2) Chi-square Distribution:
![](HW2Data/Part1/UnitSquareChiSquareDistribution.PNG?raw=true)
Figure 23: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a Chi-square  distribution.
3) Poisson Distribution:
![](HW2Data/Part1/UnitSquarePoissonDistribution.PNG?raw=true)
Figure 24: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a Poisson distribution.
4) Binomial Distribution
![](HW2Data/Part1/UnitSquareBinomialDistribution.PNG?raw=true)
Figure 25: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a Binomial distribution.


* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

![](HW2Data/Part1/UnitCircleUniformDistribution.PNG?raw=true)
Figure 26: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, ranlux48, and Quasi-sobolo with a uniform distribution.

This section will show the different engines with different distribution:
1) Normal Distribution:
![](HW2Data/Part1/UnitCircleNormalDistribution.PNG?raw=true)
Figure 27: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a normal distribution.
2) Chi-square Distribution:
![](HW2Data/Part1/UnitCircleChiSquareDistribution.PNG?raw=true)
Figure 28: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a Chi-square  distribution.
3) Poisson Distribution:
![](HW2Data/Part1/UnitCirclePoissonDistribution.PNG?raw=true)
Figure 29: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a Poisson distribution.
4) Binomial Distribution
![](HW2Data/Part1/UnitCircleBinomialDistribution.PNG?raw=true)
Figure 30: Comparison graph of pseudo-random number generators - mt19937_64, knuth_b, minstd_rand, and ranlux48 with a Binomial distribution.

##Part 2 - Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations) (30 pts)

We all love board games. A board game can be viewed mathematically as a Markov chain, where the probability of moving to the next position depends only on the position you are currently at and the chances provided by tossing a dice. For this part of the homework we will simulate the game "*Snakes and Ladders*" (This goes by other names: Chutes and Ladders, Moksha Patam but all essentially the same gameplay.)

| Moksha Patam  | Snakes and Ladders |
| ------------- | ------------- |
| ![](images/snake1.jpg?raw=true)  | ![](images/snake2.jpg?raw=true) |

##### Background
The classic game has 100 positions on the board. You toss one die, and move squares based on the result of the die. If you land on a ladder you move up the ladder to a higher numbered square. If you land on a snake's mouth, you descend to a lower numbered square. For purposes of simulation, we will add one extra square 0 (starting position). So there are 101 positions on the board.

The game is **memoryless** - your progression to the next position is independent of how you arrived there (opposed to Blackjack or Candyland where your progression is based on what cards have been drawn). A Markov Chain defines the probability of a move from state *i* to state *j* by a **Transition Matrix**, *T*. So in the case of *Snakes and Ladders* the dimensions of a transition matrix is 101x101.

* **(a) Null State Game transition matrix - 10pts:** The *null state game* is defined by a game with no snakes and no ladders. This simplifies the game to just the moves of the two dice rolls. Create the transition matrix for the null state game. The Transition Matrix would be decided by the roll of a fair, six-sided die, so it would start to look like:
<BR>![](images/null.png?raw=true)<BR>
From state 0 it is equally probable of landing on squares 1-6. From state 1 t is equally probable of landing on squares 2-7, and so on. Create this transition matrix. The end is trickier, we will consider any roll past 100 a win case. (Opposed to rolling exactly onto square 100.) Confirm you have a well formed stochastic matrix (Write checks for confirming each row of T sums to one and all elements are non-negative). The Transition Matrix methods can be found in the TransitionMatrix.h file.

	* The transition matrix for the null game is written in the function SetTransitionMatrix() in the file 		TransitionMatrix.h.  This file can be found IDS6938-SimulationTechniques\Homework2\SnakesAndLadders.  The check that each row within the transition matrix summ up to 1 is done by the function: bool checkTransitionMatrix(Eigen::MatrixXf *eigenMatrix).  This function can be found in test_markov.cpp.

* **(b) Simulate and analyze the results of Null State Game - 10pts:** What is the modal number of moves required by a single player to finish the game? We will be simulating the game two different ways. 

	* **(1) Markov Chain**: The game can be analyzed with a row vector, *v* with 101 components, representing the probabilities that the player is on each of the positions. V(0) is (1,0,0,...,0) since we know we start at square 0. v evolves by: <BR>![](images/prob.png?raw=true)<BR>
For this part (1) use the *Markov project* in the Snake and Ladders starter code.<BR>

	* To do the vector multiplication and get the probability matrix for the null game, I created the function void vectorMatrixMultiplication(bool matrixHealth, int rows, std::ofstream *file, Eigen::MatrixXf *matrixPTR).  This function is found in test_makov.cpp.  In IDS6938-SimulationTechniques\Homework2\HW2Data\Part2\NullGame\Markov there are two files:
	1) NullGame_markov_results.txt - Raw data file produce by the code.
    2) NullsGameMarkovData.xlsx - Using the raw data file, use to analyse and create graphics.

From the Probability distribution matrix of the Null game produce the following statistics:

![](HW2Data/Part2/NullGame/Markov/NullGameMarkovStatistics.PNG?raw=true)
Figure 30: Null Game finishing the game in n-moves and cummulative probability of finishing the game in n-moves. Data use is from the Probability Distribution Matrix.


**(2) Monte Carlo**: he will will use a monte carlo process to solve our Discrete Time Markov Chains. Here (2) use the DTMC project, and utilize the DTMC method similar to what we did in class. <BR><BR>Produce graphs to analyze the results and show how the game evolves over time for both methods. Plot useful statistics of the results such as percentage chance of finishing the game in n-moves, cumulative probability of finishing the game in n-moves, and other ways to convey useful information of the results.

Using the null game transition matrix to run the software for a sample size of 1000.  Using the DTMC project to run a simulation which simulates running the null game a thousand times.  Code found in IDS6938-SimulationTechniques\Homework2\SnakesAndLadders.  The main exist in test_dtcm.cpp.

The data file for Null Game dtcm exist in IDS6938-SimulationTechniques\Homework2\HW2Data\Part2\NullGame\MonteCarlo.  This folder contains:
1) NullGame_dtcm_markov_results.txt - raw data file produce by the program.
2) DTMC_Data.xlsx - raw data analyse and graphics were created.

From the raw data analysis we found the modal # to finish the game is 28.  The data also provided the number the percentage of the number of moves necessary to finish the game as well as it cummulative percentage shown in figure 31.

![](HW2Data/Part2/NullGame/Markov/NullGameMarkovStatistics.PNG?raw=true)
Figure 31: Null Game finishing the game in n-moves and cummulative probability of finishing the game in n-moves. Data use is from the DTCM simulation results.

* **(c) Simulate and analyze the results of Snakes and Ladders -10pts:**  Construct a new transition matrix based on the table:


Ladders From  | Ladders To | |  Snakes From  | Snakes To 
-------- | -------- | ------------- | -------- | -------- 
3|19| |11|7
15|37| |18|13
22|42| |28|12
25|64| |36|34
41|73| |77|16
53|74| |47|26
63|86| |83|39
76|91| |92|75
84|98| |99|70



Run the same simulation and analyze your results similar to part (b) for the proper game of *Snakes and Ladders* for both methods. How often are the snakes and ladders used, how do the probability of finishing change, etc? What is the maximum and expected amount of moves for the game? Use charts and graphs to illustrate these points.

	* To do the vector multiplication and get the probability matrix for the Snake and Ladders game, Use the function void vectorMatrixMultiplication(bool matrixHealth, int rows, std::ofstream *file, Eigen::MatrixXf *matrixPTR).  This function is found in test_markov.cpp.  In IDS6938-SimulationTechniques\Homework2\HW2Data\Part2\SnakeAndLadders\Markov there are two files:
	1) SnakeAndLadders_markov_results.txt - Raw data file produce by the code.
    2) SnakeAndLadders_Markov_DataAnalysis.xlsx - Using the raw data file, use to analyse and create graphics.

From the Probability distribution matrix of the Snake and Ladders game produce the following statistics:

![](HW2Data/Part2/SnakeAndLadders/Markov/NullGameMarkovStatistics.PNG?raw=true)
Figure 32: Snakes and Ladders Game finishing the game in n-moves and cummulative probability of finishing the game in n-moves. Data use is from the Probability Distribution Matrix.

Using the Snakes and Ladders game transition matrix to run the software for a sample size of 1000.  Using the DTMC project to run a simulation which simulates running the Snakes and Ladders game a thousand times.  Code found in IDS6938-SimulationTechniques\Homework2\SnakesAndLadders.  The main exist in test_dtcm.cpp.

The data file for Snakes and Ladders Game for DTCM exist in IDS6938-SimulationTechniques\Homework2\HW2Data\Part2\SnakeAndLadders\MonteCarloDTCM.  This folder contains:
1) ShootsAndLadders_dtcm_markov_results.txt - raw data file produce by the program.
2) ShootsAndLadders_Data.xlsx - raw data analyse and graphics were created.
3) SnakeAndLadders_dtcm_markov_300_results.txt
4) ShootsAndLadders_Data_300_rolls.xlsx

From the raw data analysis we found the modal # to finish the game is 16.  The data also provided the number the percentage of the number of moves necessary to finish the game as well as it cummulative percentage shown in figure 33.


![](HW2Data/Part2/SnakeAndLadders/MonteCarloDTCMN/ullGameMarkovStatistics.PNG?raw=true)
Figure 33: Snakes and Ladders Game finishing the game in n-moves and cummulative probability of finishing the game in n-moves. Data use is from the DTCM simulation results.

In a run which included a 1000 samples and rolls 300, the results show that the maximum number of moves needed to win the game was 160.


![](HW2Data/Part2/SnakeAndLadders/MonteCarloDTCMN/ullGameMarkovStatistics.PNG?raw=true)
Figure 34: Shows the utilization of snake and ladders.

* **(d) Think - 0pts:** If these games are built entirely on chance, do they require any strategy? Is it really a *game*, would you rather play games of chance or games of strategy?

This is a phylosophical question.  As such is a simple answer.  Why we play a game?  Most people play games for entertainment.  So if it gives you entertainement it provided its purspose wheter it is considered a game or not.


##Part 3 - Discrete Event Simulation - Queue Simulation (30 pts)

This problem will look at queues and commonly used performance measures. For this problem we will look to design a simple airport security check. We will make the following assumptions: (1) there is only one airline - Southwest; (2) passengers' interarrival times are independent and identically distributed (IID) with an exponential distribution with mean 1 / lambda. The service times are also assumed to be IID and exponentially distributed random variables with mean 1 / mu.
<BR>![](images/queue.png?raw=true)<BR>
When a passanger arrives they have to wait in a queue to present their ID and ticket to the gate agent with all the other passengers. Once approved by the agent they will have to pass through a security check. Since this is Orlando, there are only 3 open metal/screening devices open and again passangers have to wait in a queue. After passing through security you again have to wait in a queue to board your plane.

* **(a) - 4pts:** To start create the senario in the figure above in *main.cpp*. Checkin will have a *mu* of 53 and accept new arrivals, the security gates will have a *mu* of 20, and will not accept new arrivials, boarding will have a *mu* of 80. You will have to set up  the appropriate *MM1_Queue* objects to capture the functionality above.

The setup for the scenarion refrence above can be found in the folder C:\RCP\UCF\IDS6938\MyRepository\IDS6938-SimulationTechniques\Homework2\queues in the main.cpp file.

* **(b) - 4pts:** You want to add a check that your process is within an error range *is_within_error_range(float)* where the error range will be 0.002. You also want to process the next event, and add an external arrival where marked.

This as well is located in mm1_queue.cpp in MM1_Queue:: initialize() function located in C:\RCP\UCF\IDS6938\MyRepository\IDS6938-SimulationTechniques\Homework2\queues/.

* **(c) - 3pts:** in *mm1_queue.cpp* : add code to caculate the expected results for: 
  *  expected_server_utilization 
  *    expected idle prob
  *   expected queue length 
  *  expected number customers 
  * expected waiting time
  * expected response time 

The code implementation for this section was added to 

*  **(d) - 4pts:** Write code to call the functions to output and generate data from the airport senario. Plot and analyze the useful statistics/results in the program of your choice.  (Hint -  basically call  *.output();* on the MM1_Queue objects you create. Hint2 - two other use functions are *get_current_time()* and  *plot_results_output()* call intially on your intial MM1_Queue object.) 


* **(e) - 15pts:** Download the personal edition of **[Anylogic](http://www.anylogic.com/)**, read through the [documentation](http://www.anylogic.com/learn-simulation) as needed, and set up the same type of simulation discussed above.

The analogic model file can be found in C:\RCP\UCF\IDS6938\MyRepository\IDS6938-SimulationTechniques\Homework2\HW2Data\Part3\AnyLogicModel\Airport Checking in file Airport Checking.alp.

##Part 4 - Implementing Extra Features (10 pts)
Implementing 2 features on the extra features list. Pick any feature on the "*extra features*" list below to customize your assignment to fit your interests. Please document this in your writeup. (*Note: These should total 10pts. You could successfully implement a feature worth 10pts or greater. This also fulfills this requirement. The features are assigned points based on difficulty. The 5pt features are more straightforward.*)

##Part 5 - Final Report (10 pts)
Write up the results to the previous sections in the main *readme.md* in your forked repository. Turn in the URL for your fork in webcourses. Be visual. The report should contain the graphs and analysis requested. I have high expectations for the documentation here and you should allot the proper time to compose the writeup.


##Extra Features (Extra Credit - 25pts)
You have to implement two features from this list for Part 4. You may choose any two features you wish from this list. (Please explicitly note them in your *Readme.md*)

If you feel like going beyond the scope of the assignment, you should consider implementing more of the following extra features. *Get the assignment working without them first.* You can get a maximum of 25 points in extra credit. Simply implementing these things doesn't guarantee you a 25; you really need to go above and beyond to get the full amount. (*The instructor reserves the right to hand out extra credit as his he sees fit.*)

* **(5 Points)** - Implement and compare Halton, Hammersley, (Or another quasi method) Quasi sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement different distributions inside the Quasi random sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement and compare another (advanced) psedo random sequences and add them to your analysis for all subparts of Part 1 (Examples include: [PCG](http://www.pcg-random.org/), or [Random123](https://github.com/DEShawResearch/Random123-Boost)).
* **(20 Points)** - Complete Part 2 with a different board game. Construct the game's transition matrix, simulate the game, and analyze the results (Run the game past the instructor).
* **(20 Points)** - Complete Part 2 with a 3D version of Snakes and Ladders. Construct the game's transition matrix, simulate the game, and analyze the results.
* **(10 Points)** - Provide code in (Python, R, Matlab...) that demonstrates an animation of the board itself evolving overtime for Snakes in Ladder for part 2. 
* **(10 Points)** - Add a 2D visualization to AnyLogic for Part 3.
* **(10 Points)** - Add a 3D visualization to AnyLogic for Part 3.
* **(5 Points)** - Pick a research problem (from your dissertation, Energy Microgrids, Missle Defence...). Compare and contrast different software packages (AnyLogic, Simio, Simulu8, Arena etc). Convince me as your "manager/advisor" what advantages, weaknesses, and costs each program has. Come to a conclusion. Roughly sketch out how you would formulate the problem in the framework.
* **(10 Points)** - Create an Anylogic simulation for Part 2 - Snakes and Ladders.
* **(10 Points)** - Setup another resource allocation / queueing problem related to your research in Anylogic with a basic visualization
* **(10 Points)** - Setup up SmartGrid or a Microgrid System that creates resources of power from wind, solar, and electric grid. Set up various devices in your house to draw power. [Reference 1](http://www.sciencedirect.com/science/article/pii/S1877050916301740),   [Reference 2](http://www.tandfonline.com/doi/full/10.1080/19401493.2013.866695?src=recsys&).
* **(25 Points)** - Set up a discrete simulation of your choice that uses an approved real-time data source and visualizes the results. (See instructor for approval).
* **(N Points)** - You are welcome to make suggestions for a feature of your own choosing, but they must be approved by instructor before implementing.

** Citations: **
Chapter 2 RANDOM NUMBERS. (n.d.). Retrieved March 11, 2017, from https://www.usna.edu/Users/math/dphillip/sa421.s16/chapter02.pdf

Citation needed for shoots and ladders.


More than 95% (cold be even higher)of the code use for this project has been provided by Dr. Kider.

Support provided by students in IDS6938. You all have my thanks.

