#include "init.h"

int main()
{
	//initial build (works)
	/*
	{
		system("cls");
		std::string name;
		name = "car1";
		Map::getLaby()->setLaby();				   // configuring class (singleton) members values
		Car *car1 = new Car(Map::getLaby(), name); // creating a car object
		int ct = 0;								   // this will count car's move number

		Io::File::getFile()->set_path(name);
		// main loop : till car reaches the finish point
		while (!car1->isFinish(Map::getLaby()->get_end_loc()))
		{
			#ifdef _WIN32
			SetCursorPosition(0, 0);
			#elif _linux_
			SetCursorPosition(0, 0);
			#endif

			std::cout << "Move count : " << ct << "    \n";
			car1->show_move();
			car1->push(Map::getLaby()); // it pushes car to aynwhere
			Map::getLaby()->Render(car1->getLocale())->clean_map();
			//Map::getLaby()->Render(car1->getLocale())->show_map()->clean_map(); // show_map() recommended but not needed.
			//usleep(100000); // Also after Render(), using clean_map() is mandatory.
			ct++; // If remove show_map() and usleep() the car should get
				  // finish immediately without showing you the process .
			Io::File::getFile()->seek(ct, car1->getLocale(), car1->get_move());
		}
		std::cout << "Hello world! \n";
		std::cout << "Car Shushified ...\n";
		Memory::Rotation *rot = new Memory::Rotation(Io::File::getFile()->bring_line2mem(), name);

		rot->create();
		rot->get(); // recommended but not needed , just for seeing the non-optimised rotation
		rot->optimise();

		delete car1;
		delete rot;

		std::cin.get();
		return 0;
	}
	*/

	//test2  #generating by hand test (works)
	/*
	{
		system("cls");
		std::string name;
		name = "car1";
		Map::getLaby()->generateLab(); // configuring class (singleton) members values
		Map::getLaby()->show_xmap();
		Map::getLaby()->config_manual(Io::ask_config());
		system("pause");
		// Its done whenever its done
		Car *car1 = new Car(Map::getLaby(), name); // creating a car object
		int ct = 0;								   // this will count car's move number

		Io::File::getFile()->set_path(name);
		Io::File::getFile()->generateScheme(Map::getLaby()->get_map(),Map::getLaby()->getSize());
		
		// main loop : till car reaches the finish point
		system("cls");
		while (!car1->isFinish(Map::getLaby()->get_end_loc()))
		{
			#ifdef _WIN32
						SetCursorPosition(0, 0);
			#elif _linux_
						SetCursorPosition(0, 0);
			#endif

			std::cout << "Move count : " << ct << "           \n";
			car1->show_move();
			car1->_push(Map::getLaby()); // it pushes car to aynwhere
			Map::getLaby()->show_xmap(car1->getLocale()); // show_map() recommended but not needed.
			ct++;														// If remove show_map() and usleep() the car should get
																		// finish immediately without showing you the process .
			Io::File::getFile()->seek(ct, car1->getLocale(), car1->get_move());
			//system("pause");
		}
		std::cout << "Hello world! \n";
		std::cout << "Car Shushified ...\n";
		Memory::Rotation *rot = new Memory::Rotation(Io::File::getFile()->bring_line2mem(), name);

		rot->create();
		rot->get(); // recommended but not needed , just for seeing the non-optimised rotation
		rot->optimise();
		system("pause");
		Io::File::getFile()->cleanScheme();
		delete car1;
		delete rot;
	}
	*/
	
	//test3  #generating labyrinth from scheme (works)
	/*
	{
		system("cls");
		std::string name;
		name = "car1";
		Map::getLaby()->setLabyFromScheme();
		Map::getLaby()->show_xmap();

	}
	*/

	//test4 last test 
	
	{
		system("cls");
		std::string name;
		name = "car1";
		Map::getLaby()->setLabyFromScheme();
		Car *car1 = new Car(Map::getLaby(), name); // creating a car object
		int ct = 0;								   // this will count car's move number

		Io::File::getFile()->set_path(name);
		// main loop : till car reaches the finish point
		system("cls");
		while (!car1->isFinish(Map::getLaby()->get_end_loc()))
		{
			#ifdef _WIN32
						SetCursorPosition(0, 0);
			#elif _linux_
						SetCursorPosition(0, 0);
			#endif

			std::cout << "Move count : " << ct << "           \n";
			car1->show_move();
			car1->_push(Map::getLaby()); // it pushes car to aynwhere
			Map::getLaby()->show_xmap(car1->getLocale()); // show_map() recommended but not needed.
			ct++;														// If remove show_map() and usleep() the car should get
																		// finish immediately without showing you the process .
			Io::File::getFile()->seek(ct, car1->getLocale(), car1->get_move());
		}
		std::cout << "Hello world! \n";
		std::cout << "Car Shushified ...\n";
		Memory::Rotation *rot = new Memory::Rotation(Io::File::getFile()->bring_line2mem(), name);

		rot->create();
		rot->get(); // recommended but not needed , just for seeing the non-optimised rotation
		rot->optimise();
		//Io::File::getFile()->cleanScheme();
		delete car1;
		delete rot;
	}
	
	
	system("pause");
}