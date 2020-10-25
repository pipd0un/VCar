#include <iostream>
#include "init.h"
#include <unistd.h> // usleep() posix
#include <time.h>  // srand( time() ) seeding
#include <fstream>


int 
main()
{
	std::fstream fout;
	Map::getLaby().setLaby(); // configuring class (singleton) members values 
	Car *car1 = new Car(Map::getLaby()); // creating a car object
	int ct=0; // this will count car's move number

		// main loop : till car reaches the finish point
	while(!car1->isFinish(Map::getLaby().get_end_loc())){

		#ifdef _WIN32
		SetCursorPosition(0,0);
		#elif _linux_
		SetCursorPosition(0,0);
		#endif
		std::cout << "Move count : " << ct <<"    \n";
		car1->show_move();
		srand(time(0));
		car1->push(Map::getLaby()); // it pushes car to aynwhere
		Map::getLaby().Render(car1->getLocale()).clean_map();
		//Map::getLaby().Render(car1->getLocale()).show_map().clean_map(); // show_map() recommended but not needed.
		//usleep(100000);													// Also after Render(), using clean_map() is mandatory.
		ct++;														   // If remove show_map() and usleep() the car should get
																	  // finish immediately without showing you the process .
		Lub::Io::CSV::create()->seek(ct,car1->getLocale(),car1->get_move());
	}																  
	std::cout << "Hello world! \n";
	delete car1;
	std::cout << "Car Shushified ...\n";
	Lub::Io::CSV::create()->clean();
	std::cin.get();

}