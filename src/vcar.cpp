#include "init.h"

int main()
{
	Map::getLaby()->generateLab();
	Map *instance = Map::getLaby();

	Car *car1 = new Car(Map::getLaby(), "car1", 'K'); // creating a car object
	Car *car2 = new Car(Map::getLaby(), "car2", 'V');
	Car *car3 = new Car(Map::getLaby(), "car2", 'L');

	Car *cars[1];
	cars[0] = car1;
	cars[1] = car2;
	cars[2] = car3;

	while (!instance->isAnyOneFinishes())
	{
		SetCursorPosition(0, 0);
		car1->_push(instance);
		car2->_push(instance);
		car3->_push(instance);
		instance->show_race(cars, 2); // join to input how many cars you wanna see on map
	}

	delete car1;
	delete car2;
	delete car3;
	
	std::cin.get();
}