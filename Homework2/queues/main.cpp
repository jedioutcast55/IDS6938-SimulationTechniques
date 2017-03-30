/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}



int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)
   {
      
	   //TODO Create MM1_Queue objects to capture the airport senario.

	   //************************************************************  
	   // First Queue - Represents ID and ticket check at the airport.
	   MM1_Queue IDGateQueue;
	   IDGateQueue.set_file_names("01_IDGateQueue_log.txt", "01_IDGateQueue_wait.txt", "01_IDGateQueue_service.txt");
	   IDGateQueue.set_lambda(6);  // for this assignement this is set to a variable from the for loop.
	   IDGateQueue.set_mu(53);
	   //IDGateQueue.autogenerate_new_arrivals(true);
	   IDGateQueue.initialize();
	   IDGateQueue.set_seed(1, rd());  // I set the fisrt one for testing, the others you should use two random seeds (rd(), rd())

	   // Second Queue - Represents The first station of metal screening at the airport
	   MM1_Queue MetalScreening_1_Queue;
	   MetalScreening_1_Queue.set_file_names("01_MetalScreening_1_Queue_log.txt", "01_MetalScreening_1_Queue_wait.txt", "01_MetalScreening_1_Queue_service.txt");
	   MetalScreening_1_Queue.set_lambda(6);  // for this assignement this is set to a variable from the for loop.
	   MetalScreening_1_Queue.set_mu(20);
	   MetalScreening_1_Queue.autogenerate_new_arrivals(false);
	   MetalScreening_1_Queue.initialize();
	   MetalScreening_1_Queue.set_seed(rd(), rd());  // I set the fisrt one for testing, the others you should use two random seeds (rd(), rd())

	   // Third Queue - Represents The second station of metal screening at the airport
	   MM1_Queue MetalScreening_2_Queue;
	   MetalScreening_2_Queue.set_file_names("02_MetalScreening_2_Queue_log.txt", "02_MetalScreening_2_Queue_wait.txt", "02_MetalScreening_2_Queue_service.txt");
	   MetalScreening_2_Queue.set_lambda(6);  // for this assignement this is set to a variable from the for loop.
	   MetalScreening_2_Queue.set_mu(20);
	   MetalScreening_2_Queue.autogenerate_new_arrivals(false);
	   MetalScreening_2_Queue.initialize();
	   MetalScreening_2_Queue.set_seed(rd(), rd());  // I set the fisrt one for testing, the others you should use two random seeds (rd(), rd())

	   // Fourth Queue - Represents The third station of metal screening at the airport
	   MM1_Queue MetalScreening_3_Queue;
	   MetalScreening_3_Queue.set_file_names("03_MetalScreening_3_Queue_log.txt", "03_MetalScreening_3_Queue_wait.txt", "03_MetalScreening_3_Queue_service.txt");
	   MetalScreening_3_Queue.set_lambda(6);  // for this assignement this is set to a variable from the for loop.
	   MetalScreening_3_Queue.set_mu(20);
	   MetalScreening_3_Queue.autogenerate_new_arrivals(false);
	   MetalScreening_3_Queue.initialize();
	   MetalScreening_3_Queue.set_seed(rd(), rd());  // I set the fisrt one for testing, the others you should use two random seeds (rd(), rd())

	   // Fifth Queue - Represents The boarding the airplane queue
	   MM1_Queue Boarding_Queue;
	   Boarding_Queue.set_file_names("01_Boarding_Queue_log.txt", "01_Boarding_Queue_wait.txt", "01_Boarding_Queue_service.txt");
	   Boarding_Queue.set_lambda(6);  // for this assignement this is set to a variable from the for loop.
	   Boarding_Queue.set_mu(80);
	   //Boarding_Queue.autogenerate_new_arrivals(false);
	   Boarding_Queue.initialize();
	   Boarding_Queue.set_seed(rd(), rd());  // I set the fisrt one for testing, the others you should use two random seeds (rd(), rd())

	   /*std::cout << std::endl;
	   std::cout << "IDGate within confidence Interval: " << IDGateQueue.is_within_confidence_interval() << endl;
	   std::cout << "MetalScreening_1_Queue within confidence Interval: " << MetalScreening_1_Queue.is_within_confidence_interval() << endl;
	   std::cout << "MetalScreening_2_Queue within confidence Interval: " << MetalScreening_2_Queue.is_within_confidence_interval() << endl;
	   std::cout << "MetalScreening_3_Queue within confidence Interval: " << MetalScreening_3_Queue.is_within_confidence_interval() << endl;
	   std::cout << "Boarding_Queue within confidence Interval: " << Boarding_Queue.is_within_confidence_interval() << endl;
	   std::cout << "IDGate within error range: " << IDGateQueue.is_within_error_range(0.002) << endl;
	   std::cout << "MetalScreening_1_Queue within error range: " << MetalScreening_1_Queue.is_within_error_range(0.002) << endl;
	   std::cout << "MetalScreening_2_Queue within error range: " << MetalScreening_2_Queue.is_within_error_range(0.002) << endl;
	   std::cout << "MetalScreening_3_Queue within error range: " << MetalScreening_3_Queue.is_within_error_range(0.002) << endl;
	   std::cout << "Boarding_Queue within error range: " << Boarding_Queue.is_within_error_range(0.002) << endl;
	   std::cout << std::endl;*/


   for (; 
		!IDGateQueue.is_within_error_range(0.002) || !MetalScreening_1_Queue.is_within_error_range(0.002) || !MetalScreening_2_Queue.is_within_error_range(0.002)
	   || !MetalScreening_3_Queue.is_within_error_range(0.002) || !Boarding_Queue.is_within_error_range(0.002) //TODO: add is_within_error_range check
       ;)
   {
	   Customer cust = IDGateQueue.process_next_event();    // =  TODO: process next event;
	   Customer cust2 = MetalScreening_1_Queue.process_next_event();   // =  TODO: process next event;
	   Customer cust3 = MetalScreening_2_Queue.process_next_event();   // =  TODO: process next event;
	   Customer cust4 = MetalScreening_3_Queue.process_next_event();   // =  TODO: process next event;
	   Customer cust5 = Boarding_Queue.process_next_event();
	   //TODO: one more process_next_event for the last object.

       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for your security gates;
				MetalScreening_1_Queue.add_external_arrival();
                 break;
            case 1:
				//TODO add_external_arrival() for your security gates;
				MetalScreening_2_Queue.add_external_arrival();
                 break;
            case 2:
                //TODO add_external_arrival() for your security gates;
				MetalScreening_3_Queue.add_external_arrival();
                 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   Boarding_Queue.add_external_arrival();
       }
   }



   //TODO Output statistics airport senario.
   IDGateQueue.get_current_time();
   IDGateQueue.output();
   IDGateQueue.plot_results_output();


   MetalScreening_1_Queue.output(); cout << "***************" << endl;
   MetalScreening_2_Queue.output(); cout << "***************" << endl;
   MetalScreening_3_Queue.output(); cout << "***************" << endl;
   Boarding_Queue.output(); cout << "***************" << endl;




   //**************************************************************************



   }

   return(0);
}

