#include "init.h"
#include <unistd.h> // usleep() posix
#include <time.h>	// srand( time() ) seeding

int main()
{
	std::string name;
	/*
	std::cout << "Set your car's name : ";
	std::cin >> name;
	*/
	name = "car1";
	Map::getLaby().setLaby();				   // configuring class (singleton) members values
	Car *car1 = new Car(Map::getLaby(), name); // creating a car object
	int ct = 0;								   // this will count car's move number

	Io::File::getFile()->set_path(name);
	// main loop : till car reaches the finish point
	while (!car1->isFinish(Map::getLaby().get_end_loc()))
	{
		#ifdef _WIN32
				SetCursorPosition(0, 0);
		#elif _linux_
				SetCursorPosition(0, 0);
		#endif

		std::cout << "Move count : " << ct << "    \n";
		car1->show_move();
		srand(time(0));
		car1->push(Map::getLaby()); // it pushes car to aynwhere
		//Map::getLaby().Render(car1->getLocale()).clean_map();
		Map::getLaby().Render(car1->getLocale()).show_map().clean_map(); // show_map() recommended but not needed.
		usleep(100000); // Also after Render(), using clean_map() is mandatory.
		ct++; // If remove show_map() and usleep() the car should get
			  // finish immediately without showing you the process .
		Io::File::getFile()->seek(ct, car1->getLocale(), car1->get_move());
	}
	std::cout << "Hello world! \n";
	std::cout << "Car Shushified ...\n";

	Memory::Rotation *rot = new Memory::Rotation(Io::File::getFile()->bring_line2mem(), name);

	rot->create();
	rot->get();

	while(!rot->is_optimised()){
		rot->semi_optimise();
	}

	delete car1;
	delete rot;

	std::cin.get();
}