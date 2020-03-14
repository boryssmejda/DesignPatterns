#include "BritishEquipment.hpp"

std::string Spitfire::getName()
{
	return "Supermarine Spitfire";
}

std::string Hurricane::getName()
{
	return "Hawker Hurricane";
}

std::string CruiserTankCrusader::getName()
{
	return "Crusader";
}

std::string ChurchillTankCrocodile::getName()
{
	return "Mk IV Churchill";
}

std::unique_ptr<IPlane> BritishFactory::getPlane(std::string t_planeName)
{
	if (t_planeName == "spitfire")
		return std::make_unique<Spitfire>();
	else if (t_planeName == "hurricane")
		return std::make_unique<Hurricane>();
	
	return nullptr;
}

std::unique_ptr<ITank> BritishFactory::getTank(std::string t_tankName)
{
	if (t_tankName == "churchill")
		return std::make_unique<ChurchillTankCrocodile>();
	else if (t_tankName == "crusader")
		return std::make_unique<CruiserTankCrusader>();

	return nullptr;
}
