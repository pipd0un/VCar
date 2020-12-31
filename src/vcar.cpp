#include "init.h"

int main()
{
	//test 5 auto_config test
	{
		system("cls");
		Map::getLaby()->generateLab();
		std::string name = "car1";
		
		Car car1 = Car(Map::getLaby(), name,'K'); // creating a car object
		int ct = 0;							  // this will count car's move number

		// main loop : till car reaches the finish point
		system("cls");
		while (!car1.isFinish(Map::getLaby()->get_end_loc()))
		{
			SetCursorPosition(0, 0);
			std::cout << "Move count : " << ct << "           \n";
			car1.show_move();
			car1._push(Map::getLaby());					 // it pushes car to aynwhere
			Map::getLaby()->show_map(car1); 			 // show_map() recommended but not needed.
			ct++;										 // If remove show_map() and usleep() the car should get
														 // finish immediately without showing you the process .
			Io::File::getFile()->seek(ct, car1.getLocale(), car1.get_move(),name);
		}
		std::cout << "Hello world! \n";
		std::cout << "Car " << name << " Shushified ...\n";

		Memory::Rotation rot = Memory::Rotation(Io::File::getFile()->bring_line2mem(name), name);rot.create();
		rot.create();
		rot.get(); // recommended but not needed , just for seeing the non-optimised rotation
		rot.optimise();

		Map::getLaby()->show_xmap();
	}

	system("pause");
}