#include <iostream>
#include "init.h"
#include <unistd.h> // usleep() posix
#include <time.h>  // srand( time() ) seeding

int main()
{
	Map::getLaby().setLaby(); // configuring class (singleton) members values 
	Car *car1 = new Car(Map::getLaby()); // creating a car object
	int ct=0; // this will count car's move number

		// main loop : till car reaches the finish point
	while(!car1->isFinish(Map::getLaby().get_end_loc())){
		srand(time(0));
		car1->push(Map::getLaby()); // it pushes car to aynwhere
		car1->getMap(Map::getLaby()).Render(car1->getLocale()).show_map().clean_map();
		usleep(100000);
		ct++;
		cls();
		std::cout << "Move count : " << ct <<"\n";
		std::cout << "Location : " << car1->getLocale()[0] << " - " << car1->getLocale()[1] << "\n";
	}
	car1->getMap(Map::getLaby()).Render(car1->getLocale()).show_map().clean_map();
	std::cout << "Hello world!" << std::endl;
	delete car1;
	std::cout << "Car Shushified ...\n";
	std::cin.get();
}