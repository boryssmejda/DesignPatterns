#include "GermanEquipment.hpp"

std::unique_ptr<IPlane> GermanFactory::getPlane(std::string t_planeName)
{
	if (t_planeName == "messerschmitt")
		return std::make_unique<Messerschmitt>();
	else if (t_planeName == "dornier")
		return std::make_unique<Dornier>();

	return nullptr;
}

std::unique_ptr<ITank> GermanFactory::getTank(std::string t_tankName)
{
	if (t_tankName == "tiger")
		return std::make_unique<Tiger>();
	else if (t_tankName == "panther")
		return std::make_unique<Panther>();

	return nullptr;
}

std::string Tiger::getName()
{
	return "Tiger";
}

std::string Messerschmitt::getName()
{
	return "Messerschmitt Bf 109";
}

std::string Panther::getName()
{
	return "Panther";
}

std::string Dornier::getName()
{
	return "Dornier Do 17";
}
