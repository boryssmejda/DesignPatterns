#include "AbstractFactory.hpp"
#include "AmericanEquipment.hpp"
#include "BritishEquipment.hpp"
#include "GermanEquipment.hpp"
#include <stdexcept>

std::unique_ptr<MilitaryEquipmentFactory> MilitaryEquipmentFactory::createFactory(EquipmentFactory t_factory)
{

	switch (t_factory)
	{
	case EquipmentFactory::AMERICAN:
		return std::make_unique<AmericanFactory>();
		break;
	case EquipmentFactory::BRITISH:
		return std::make_unique<BritishFactory>();
		break;
	case EquipmentFactory::GERMAN:
		return std::make_unique<GermanFactory>();
		break;
	default:
		throw std::runtime_error("Type not supported!");
	}
}
