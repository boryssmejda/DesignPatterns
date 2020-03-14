#include <iostream>

#include "AbstractFactory.hpp"
#include "AmericanEquipment.hpp"

int main()
{
 	std::unique_ptr<MilitaryEquipmentFactory> factory = MilitaryEquipmentFactory::createFactory(MilitaryEquipmentFactory::EquipmentFactory::AMERICAN);
	std::cout << factory->getPlane("mustang")->getName() << '\n';
	std::cout << factory->getPlane("wildcat")->getName() << '\n';

	std::cout << factory->getTank("sherman")->getName() << '\n';
	std::cout << factory->getTank("stuart")->getName() << '\n';

	factory = MilitaryEquipmentFactory::createFactory(MilitaryEquipmentFactory::EquipmentFactory::BRITISH);
	auto spitfire = factory->getPlane("spitfire");
	std::cout << spitfire->getName() << '\n';

	auto churchillTank = factory->getTank("churchill");
	std::cout << churchillTank->getName() << '\n';

	factory = MilitaryEquipmentFactory::createFactory(MilitaryEquipmentFactory::EquipmentFactory::GERMAN);
	auto tiger = factory->getTank("tiger");
	std::cout << tiger->getName() << '\n';

	auto panther = factory->getTank("panther");
	std::cout << panther->getName() << '\n';


	return 0;
}