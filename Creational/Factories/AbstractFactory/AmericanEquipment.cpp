#include "AmericanEquipment.hpp"
#include <stdexcept>

std::unique_ptr<IPlane> AmericanFactory::getPlane(std::string t_planeName)
{
	if (t_planeName == "mustang")
		return std::make_unique<Mustang>();
	else if (t_planeName == "wildcat")
		return std::make_unique<Wildcat>();
	else
		throw std::runtime_error("Invalid plane name!");
}

std::unique_ptr<ITank> AmericanFactory::getTank(std::string t_tankName)
{
	if (t_tankName == "sherman")
		return std::make_unique<Sherman>();
	else if (t_tankName == "stuart")
		return std::make_unique<Stuart>();
	else
		throw std::runtime_error("Invalid plane name!");
}

/*============  PLANES  ==================*/
std::string Mustang::getName()
{
	return "North American P-51 Mustang";
}

std::string Wildcat::getName()
{
	return "Grumman F4F Wildcat";
}


/*============  TANKS  ======================*/
std::string Sherman::getName()
{
	return "M4 Sherman";
}

std::string Stuart::getName()
{
	return "M3 Stuart";
}
