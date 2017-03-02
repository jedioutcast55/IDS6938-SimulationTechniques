#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)
Roberto Cabrera


This is the framework for homework #1. Please first read the [homework writeup](HomeWork%231.pdf).

The assignment is due: Wednesday, March 1,  at 11:59PM (EST)

Dr. Kyder: I am requesting to use one of the three days grace period for this assignment !!!!!!!!!!!!
New deadline should be: Thursday, March 2, 2017 at 11:59PM (EST). Thank you.


| undeformed jello  | deformed jello |
| ------------- | ------------- |
| ![](images/undeformed3.png?raw=true)  | ![](images/deformed3.png?raw=true) |

Part 1: Numberical Analysis of Integrarion Functions:
 (a) Solve for the exact symbolic (analytical solution).


 Shown on below figure from WolframAlpha
| Figure 1: Analytical Solution:

| ![](images/DifferentialEquationSolutionHW1Part1.PNG?raw=true) |


 (b) Translate the mathematical formulas you now have into the df and exact.
       The code can be found in the Lecture6-Solution folder.  Output file can be found in "...Homework1/DocumentaionSupport/NumericalMethodDataFile.txt"

(c)  This is the code that I utilize to run the program to produce
	   RK1, RK2 and RK4, put the following results on a table.
	   Results can be seen in the following table:

	| x |	|y (Euler)|	|y (midpoint)|	|y (RK44)|	  |EXACT|
	|----| |----------|	 |----------|	  |----------|    |----------|
	|0.0|	|0|	        |0|	           |0|	         |0|
	|0.1|	|0.5|		  |0.5090369272|	|0.5040147599|  |0.5040062116|
	|0.2|	|0.9860882804| |0.9418917554|	|0.9299833736|  |0.9299692608|
	|0.3|	|1.336761843|  |1.178280127|	 |1.158938591|   |1.158923832|
	|0.4|	|1.453584287|	|1.136380907|	|1.110627992|	|1.110618385|
	|0.5|	|1.28927035|	|0.7981592984|	|0.7684526188|	|0.7684534442|
	|0.6|	|0.8654303303|	|0.2207680347|	|0.1904774691|	|0.1904920858|
	|0.7|	|0.2742737135|	|-0.470402004|	|-0.4978138899|	|-0.497785095|
	|0.8|	|-0.3378573082|	|-1.107144704|	|-1.129056656|	|-1.129016654|
	|0.9|	|-0.8027530548|	|-1.517667616|	|-1.533117725|	|-1.533072395|
	|1.0|	|-0.971671551|	|-1.570878628|	|-1.581041974|	|-1.580998849|
	|1.1|	|-0.7559488242|	|-1.214747006|	|-1.222913458|	|-1.222879899|
	|1.2|	|-0.1562476992|	|-0.4981410611|	|-0.5091470062|	|-0.5091282324|
	|1.3|	|0.7283561079|	|0.4312735709|	|0.4120685813|	|0.4120711203|
	|1.4|	|1.715934898|	|1.355046339|	|1.323019094|	|1.323008542|
	|1.5|	|2.580464313|	|2.033306318|	|1.985762151|	|1.985745966|
	|1.6|	|3.106136933|	|2.264888984|	|2.20186874|	|2.201857271|
	|1.7|	|3.144749623|	|1.943723238|	|1.868173695|	|1.868177859|
	|1.8|	|2.661568066|	|1.0964239|		|1.013619327|	|1.013647908|
	|1.9|	|1.756533063|	|-0.1106615176|	|-0.1943761998|	|-0.1943189781|
	|2.0|	|0.6527034805|	|-1.399996434|	|-1.478886739|	|-1.4788027|
	|2.1|	|-0.3485024816|	|-2.443310353|	|-2.513966496|	|-2.513863572|
	|2.2|	|-0.9371188681|	|-2.941602204|	|-3.004245902|	|-3.004136603|
	|2.3|	|-0.873976159|	|-2.70594543|	|-2.764948334|	|-2.764846851|
	|2.4|	|-0.05994660124||-1.71816828|	|-1.781566264|	|-1.781484825|
	|2.5|	|1.423979884|	|-0.1535146925|	|-0.2315408363|	|-0.2314861673|
	|2.6|	|3.319281279|	|1.644605198|	|1.54168834|	|1.541717508|
	|2.7|	|5.238969258|	|3.236248676|	|3.100524943|	|3.100538568|
	|2.8|	|6.755270333|	|4.189210793|	|4.01709566|	|4.017110916|
	|2.9|	|7.507190201|	|4.192252154|	|3.985526889|	|3.985564681|
	|3.0|	|7.302089591|	|3.148785464|	|2.914307734|	|2.914387906|
	|3.1|	|6.184236647|	|1.224605964|	|0.972629052|	|0.9727653848|
	|3.2|	|4.449044884|	|-1.167577779|	|-1.426190757|	|-1.425994463|
	|3.3|	|2.593589867|	|-3.449436793|	|-3.706500293|	|-3.706251919|
	|3.4|	|1.209577795|	|-5.009923054|	|-5.262921367|	|-5.262639293|
	|3.5|	|0.8405527212|	|-5.360649903|	|-5.614631006|	|-5.614340022|
	|3.6|	|1.836719894|	|-4.275713547|	|-4.543483006|	|-4.543208093|
	|3.7|	|4.244893938|	|-1.877962749|	|-2.178355567|	|-2.178114923|
	|3.8|	|7.765893459|	|1.356347703|	|1.001862248|	|1.002063203|
	|3.9|	|11.797567|		|4.68431418|		|4.255978576|	|4.256150562|
	|4.0|	|15.56128357|	|7.261608412|	|6.745634215|	|6.745803673|
	|4.1|	|18.28779237|	|8.351461123|	|7.743070647|	|7.743275262|
	|4.2|	|19.42038688|	|7.527669226|	|6.8319912|		|6.832272103|
	|4.3|	|18.78438686|	|4.818214028|	|4.048561713|	|4.048954056|
	|4.4|	|16.67534928|	|0.745902688|	|-0.0804073784|	|-0.07988318583|
	|4.5|	|13.83454839|	|-3.755363171|	|-4.622839038|	|-4.62218308|
	|4.0|	|11.30627052|	|-7.53999892|	|-8.441122943|	|-8.440356708|
	|4.7|	|10.20162853|	|-9.526142511|	|-10.46629701|	|-10.4654587|
	|4.8|	|11.42050818|	|-8.98343453|	|-9.983215155|	|-9.982350011|
	|4.9|	|15.3995765|	|-5.75964435|	|-6.853708459|	|-6.852856091|
	|5.0|	|21.95465336|	|-0.3807817504|	|-1.613192731|	|-1.612374396|
	|5.1|	|30.26839856|	|6.014645055|	|4.597706732|	|4.598497604|
	|5.2|	|39.04184528|	|11.90757696|	|10.26608596|	|10.26688721|
	|5.3|	|46.78766159|	|15.75373022|	|13.86098924|	|13.86186593|
	|5.4|	|52.20384861|	|16.38289019|	|14.22958423|	|14.23061724|
	|5.5|	|54.53922906|	|13.34297777|	|10.93668465|	|10.93795441|
	|5.6|	|53.8548974|	|7.093621803|	|4.453381201|	|4.454949997|
	|5.7|	|51.10278291|	|-1.016917323|	|-3.870136268|	|-3.868238693|
	|5.8|	|47.98174569|	|-9.00825224|	|-12.06319514|	|-12.06097868|
	|5.9|	|46.58531604|	|-14.71564969|	|-17.98179125|	|-17.97930254|
	|6.0|	|48.91085718|	|-16.33276767|	|-19.84783646|	|-19.84514567|
	|6.1|	|56.34331178|	|-12.91820728|	|-16.74997531|	|-16.74715483|
	|6.2|	|69.24521405|	|-4.730353493|	|-8.971708122|	|-8.968807967|
	|6.3|	|86.770879|		|6.71462731|		|1.956659048|	|1.959633321|
	|6.4|	|106.976805|	|18.90583913|	|13.52479088|	|13.52789171|
	|6.5|	|127.2308958|	|28.88713582|	|22.79198022|	|22.79531867|
	|6.6|	|144.845701|	|33.9802905|	|27.1065171|	|27.11024922|
	|6.7|	|157.7947748|	|32.51209943|	|24.82557044|	|24.82987139|
	|6.8|	|165.3348427|	|24.35679009|	|15.84845493|	|15.85348654|
	|6.9|	|168.3623304|	|11.13329012|	|1.804998656|	|1.810878113|
	|7.0|	|169.3838706|	|-4.030216515|	|-14.18624083|	|-14.17946262|
	|7.1|	|172.0681429|	|-17.14871549|	|-28.17228344|	|-28.16462716|
	|7.2|	|180.4518537|	|-24.32396089|	|-36.30581142|	|-36.29735499|
	|7.3|	|197.9702842|	|-22.76449392|	|-35.85664997|	|-35.84749611|
	|7.4|	|226.5464061|	|-11.62486987|	|-26.03915079|	|-26.02938275|
	|7.5|	|265.9819834|	|7.573163658|	|-8.420983343|	|-8.410618979|
	|7.6|	|313.8412016|	|31.09105003|	|13.23698217|	|13.24802651|
	|7.7|	|365.909382|	|53.7164146|	|33.72789984|	|33.73982544|
	|7.8|	|417.1685434|	|69.96783884|	|47.60073669|	|47.61385252|
	|7.9|	|463.0911121|	|75.49676734|	|50.551947|	|50.56663391|
	|8.0|	|500.9495217|	|68.3428104|	|40.66514418|	|40.68180013|
	|8.1|	|530.8035916|	|49.70067888|	|19.16044889|	|19.17942782|
	|8.2|	|555.8758684|	|23.94803368|	|-9.592897427|	|-9.571337455|
	|8.3|	|582.1538542|	|-2.150655369|	|-38.88141649|	|-38.85714093|
	|8.4|	|617.2422193|	|-20.94381739|	|-61.14646828|	|-61.11945935|
	|8.5|	|668.6856376|	|-25.78002003|	|-69.86074193|	|-69.83105503|
	|8.6|	|742.143842|	|-12.83269433|	|-61.33393679|	|-61.30162694|
	|8.7|	|839.8791755|	|17.61878775|	|-35.97067969|	|-35.93571326|
	|8.8|	|959.984196|	|60.84206991|	|1.404009713|	|1.441837177|
	|8.9|	|1096.629577|	|108.4273937|	|42.33439851|	|42.37551737|
	|9.0|	|1241.37688|	|150.1023432|	|76.55081616|	|76.59589429|
	|9.1|	|1385.328763|	|176.2233273|	|94.44915487|	|94.49905918|
	|9.2|	|1521.647688|	|180.3673069|	|89.65808285|	|89.71379662|
	|9.3|	|1647.829303|	|161.3606021|	|61.03567726|	|61.09819136|
	|9.4|	|1767.116099|	|124.1582495|	|13.51631062|	|13.58651544|
	|9.5|	|1888.596144|	|79.22459545|	|-42.53333378|	|-42.45472598|
	|9.6|	|2025.825999|	|40.4187988|	|-93.43846738|	|-93.35094466|
	|9.7|	|2194.184043|	|21.77807556|	|-125.4239703|	|-125.3271744|
	|9.8|	|2407.512568|	|33.91946812|	|-128.1856199|	|-128.0792336|
	|9.9|	|2674.851039|	|80.95594681|	|-97.93441991|	|-97.81800842|
	|10|	|2998.124017|	|158.7831645|	|-39.0670402|	|-38.93988091|




| Figure 2: Graph comparison of Euler, Midpoint and RK4 method with the exact solution:
| -------------
| ![](images/EulerMidpointRK4andExactResults.PNG?raw=true)|


(d) Plot the error percentages for RK1, RK2, and RK4.
     %error = |exact - apporx|/exact


| Figure 3: Error percentage of the  Euler, Midpoint and RK4 method when compared to the exact solution:   
| -------------|
| ![](images/EulerMidpointRK4andExactError.PNG?raw=true)|


(e) Vary the step size h = n, where you define three n valuse for x = <0.0, 10.0>.  I have selected the following values for n.

	 |h = n for n = 0.05|
	 |h = n for n = 0.5 |
	 |h = n for n = 1   |

Program results can be seen in "...Homework1/DocumentaionSupport/NumericalMethodDataFile.txt"

| Figure 4: Graph comparison RK4 method running at different time steps h = 0.05, 0.5, and 1:
| -------------|
| ![](images/RK4atTimeStpes_0.05_0.5_1.PNG?raw=true)|

(f) Analysis of results:

	(1) Describe how varying the integration method changes the accuracy.
	By varying the different integration methods and take the error percentage (|exact – approx.|/ exact) we can
    determine which method is more accurate for a time step h = 0.1.

	(2) What happens as you increase the x value to the accuracy?
	As we can see from the error percentage graph, the error fluctuation increases and become for frequent and
    some have large magnitudes.  It is very obvious on the Euler methods for x <0.0-10.0), less so on the other
    two methods.  But you can still see it on the Midpoint, on the RK4 is very stable (at h=0.1).

	(3) How does varying the step size effect the accuracy?
	When a comparison of the RK4 method was taken with different time steps.  You can see that the higher the
    step (in this case h=1) veers away from the exact solution.  While the smaller the h is (h=0.05) much closer
	to the exact solution. In the graph presented RK4 for h = 0.05 cannot be seen as it is underneath the exact
	curve.

	(4) Which method is the most accurate and why (in particular explain what is taken to account in the solution)?
	The most accurate method is RK4.  RK4 utilizes a higher order differential equation the both the Euler’s and
    Midpoint methods.  RK4 option take into account the error more accurately than the other two methods.

    Part 2: Programming a Jello Cube
	- Forward Euler, midpoint integration, and RK4 - The following functions have been implemented on the jello cube
	  in File jelloMesh.cpp:
      Implemented JelloMesh::Euler()
      Implemented JelloMesh::MidpointIntegration()
      Implemented JelloMesh::RK4Integration()

	-  Particle forces other than gravity:                                                                                      The following function has been implemented on the jello cube in File jelloMesh.cpp:
	   Implemented spring forces in JelloMesh::ComputeForces(ParticleGrid& grid)

	- Collision and penetration detection.
	  The following functions have been implemented on the jello cube                                                           in File jelloMesh.cpp:                                                                                                   Implement JelloMesh::ResolveContacts(ParticleGrid& grid)                                                                 Implement JelloMesh::ResolveCollisions(ParticleGrid& grid)

    - Extra springs.                                                                                                           The following functions have been implemented on the jello cube                                                           in File jelloMesh.cpp:                                                                                                    Modify JelloMesh::InitJelloMesh() to add springs.

	- Implementing 2 features on the extra features list.                                                                       Different and more stable integration methods. Verlet, Velocity Verlet, Leapfrog, or                                     Symplectic. I have decided to implement two new enumeration methods.  These methods can be found in jelloMesh.cpp:       Implemented JelloMesh::Leapfrog()                                                                                         Implemented JelloMesh::VelocityVerlet()                                                                                   Implemented JelloMesh::VelocityVerlet()

    Part 3:                                                                                                                   1) What is the effect of the Ks and Kd parameters on the jello? .                                                         2) What are the benefits and the drawbacks of the collision system used here? What are some different ways in which          it could be improved?
	3) What are some example systems you could model with Mass-spring simulations? Explain
       how you would you construct the model.
    4) Does the jello behave realistically? What integration method did you choose to make the
       Jello stable?
    5) How would you model and simulate water (in terms of a continuous simulation)?
    
    Part 4:
