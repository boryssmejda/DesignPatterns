#include <iostream>
#include "Prototype.hpp"

int main()
{
	Prototype::TankFactory::initalize();
	while (true)
	{
		std::cout << "(0) Exit, (1) Tiger, (2) Sherman, (3) Panther\n";
		int choice;
		std::cin >> choice;

		enum Prototype::TankModel model;
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			model = Prototype::TankModel::TIGER;
			break;
		case 2:
			model = Prototype::TankModel::SHERMAN;
			break;
		case 3:
			model = Prototype::TankModel::PANTHER;
			break;
		default:
			exit(0);
		}

		auto tank = Prototype::TankFactory::makeTank(model);
		tank->displayInfo();
		std::cout << "============================================\n";
	}
	return 0;
}