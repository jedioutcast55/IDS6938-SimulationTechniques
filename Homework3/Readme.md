# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
Student: Roberto Cabrera

This is the framework for homework #3. 

The assignment is due: **Monday, April  24 at 11:59PM (EST)**

Dr. Kyder has added 24 Hrs. Now the assignment is due on  ** Tuesday, April, 25 at 11:59PM (EST)**

# Introduction
The goal of this assignment is to enable the behavioral animation of vehicle-like walking agents. 

You will be expected to compose a *final report* which demonstrates your understanding on the material in each section of the assignment. Be visual! - Pictures say a thousand words so you do not have to. Show off your different configurations and really explore the assignment.


### Part 1: Behaviors

The goal of this assignment is to enable the steering behavioral animation of agents.

We represent an agent as a two-dimensional disk with mass (**m**) and moment-of-inertia (**I**) that is capable of generating a force **F** along body x-axis with a torque about the z-axis. For this assignment assume that the agent only translates in the world x-y plane and rotates about the body z-axis.

![](images/behavior.png?raw=true)

**(a) - 10 points** : Compute derivative vector given input and state vectors. Implement the function *SIMAgent::FindDeriv()*. This function sets derive vector to appropriate values after being called.

Description of agent state vector and input vector:  
* state[0] is the position of the agent in local body coordinates (almost useless in this project);  
* state[1] is the orientation angle of the agent with respect to world (i.e. global) coordinates;  
* state[2] is the velocity of the agent  in local body coordinates.  
* state[3] is the angular velocity of the agent in world coordinates. 
* input[0] is the force in local body coordinates;  
* input[1] is the torque in local body coordinates

You will need to set deriv[0], deriv[1], deriv[2], deriv[3]. Compute derivative vector given input and state vectors. This function sets derive vector to appropriate values after being called. 
* deriv[0] is the velocity of the agent in local body coordinates
* deriv[1] is the angular velocity of the agent in world coordinates
* deriv[2] is the force in local body coordinates divided by the mass.
* deriv[3] is the torque in local body coordinates divided by the inertia.
 
  The computation of the derivative vectors given input and state vectors are define within the method SIMAgent::FindDeriv().  The SIMAgent::FindDeriv() method is found in Agent.cpp on the following path: \IDS6938-SimulationTechniques\Homework3\BehaviorSimFramework\src.

You also must implement *SIMAgent::InitValues()*: Try to figure out appropriate values for control and behavior settings. You need to find out appropriate values for: *SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
SIMAgent::KNoise,	SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood, SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.*

  The control behavior setting are implemented on the method SIMAgent::InitValues() of the Agent.cpp file.  When the program is first run, the values are display on the right Graphic Unit Interface (GUI) panel.
  
![](HW3Data/Part1/BehaviorAndControlSettings.PNG?raw=true)
Figure 1: Control and Behavior setting values.


**(b) - 20 points**: In this part of the assignment you will need to implement 6 types of individual behaviors and 5 types of group behaviors. Create the following behaviors through appropriate computation of V<sub> d</sub>  and θ<sub>d</sub>  commands:
* Seek
* Flee
* Arrival
* Departure
* Wander
* Obstacle Avoidance

I have implemented 6 types of individual agent behaviors in the Agent.cpp file.  They can be found in the clarification of vec2 SIMAgent::Seek(), vec2 SIMAgent::Flee(), vec2 SIMAgent::Arrival(), vec2 SIMAgent::Departure(), vec2 SIMAgent::Wander(), vec2 SIMAgent::Avoid().

The following video will show the six different behaviors with one individual, ten individuals, and 50 individuals.  The video will show the behaviors in the following order:
1.	Seek
![](HW3Data/Part1/IndividualBehavior/SeekImage.PNG?raw=true)
Figure 2: Video Access to Agent Individual Behavior: Seek. With the number of Agents from 1, 10, and  50.

2.	Flee
![](HW3Data/Part1/IndividualBehavior/FleeImage.PNG?raw=true)
Figure 3: Video Access to Agent Individual Behavior: Flee. With the number of Agents from 1, 10, and  50.

3.	Arrival 
![](HW3Data/Part1/IndividualBehavior/ArrivalImage.PNG?raw=true)
Figure 4: Video Access to Agent Individual Behavior: Arrival. With the number of Agents from 1, 10, and  50.

4.	Departure
![](HW3Data/Part1/IndividualBehavior/DepartureImage.PNG?raw=true)
Figure 5: Video Access to Agent Individual Behavior: Departure. With the number of Agents from 1, 10, and  50.

5.	Wander
![](HW3Data/Part1/IndividualBehavior/WanderImage.PNG?raw=true)
Figure 6: Video Access to Agent Individual Behavior: Wonder. With the number of Agents from 1, 10, and  50.

6.	Avoid
![](HW3Data/Part1/IndividualBehavior/AvoidImage.PNG?raw=true)
Figure 7: Video Access to Agent Individual Behavior: Avoid. With the number of Agents from 1, 10, and  50.


**(c) - 20 points**: Implement the functions for the following group behaviors: 
* Seperation
![](HW3Data/Part1/GroupBehavior/SeparationImage.PNG?raw=true)
Figure 8: Video Access to Agent Group Behavior: Separation. With the number of Agents from 10 and  50.

* Cohesion 
![](HW3Data/Part1/GroupBehavior/AlignmentImage.PNG?raw=true)
Figure 9: Video Access to Agent Group Behavior: Alignment. With the number of Agents from 10 and  50.

* Alignment 
![](HW3Data/Part1/GroupBehavior/CohesionImage.PNG?raw=true)
Figure 10: Video Access to Agent Group Behavior: Cohesion. With the number of Agents from 10 and  50.

* Flocking
![](HW3Data/Part1/GroupBehavior/FlockingImage.PNG?raw=true)
Figure 11: Video Access to Agent Group Behavior: Flocking. With the number of Agents from 10 and  50.

* Leader Following
![](HW3Data/Part1/GroupBehavior/LeaderImage.PNG?raw=true)
Figure 12: Video Access to Agent Group Behavior: Leader. With the number of Agents from 10 and  50.

# Part 2 - Simulating a simple pedestrian flow

The goal of this part of the assigment is to simulate the pedestrain flow for various configurations. Pedestrian traffic simulation is an important, sometimes required, stage for certain construction projects such as shopping centers, airports, railway stations, or stadiums. hese analyses can be used by architects in the design stage, by facilities owners contemplating changes, by city planners to evaluate rush hours, or even by civil authorities to simulate evacuations or other emergencies. 

![](images/flow.png?raw=true)

**(a) - 0 points**: Follow the Anylogic example for the [Subway Entrance example](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/tutorial/Subway_Entrance.html). Create the appropriate [boundaries and walls](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/markup/Wall.html), and the display ther pedestrian density map, [statistics](https://help.anylogic.com/index.jsp?nav=/4_1_5), [2D and 3D animations](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Animation.html).

![](images/density.png?raw=true)

**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.

**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.



