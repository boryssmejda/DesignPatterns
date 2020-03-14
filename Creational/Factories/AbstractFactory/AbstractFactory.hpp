#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>
#include <string>
#include <iostream>

class IPlane
{
public:
	virtual std::string getName() = 0;
	virtual ~IPlane() { std::cout << "IPlane destroyed\n"; }
};

class ITank
{
public:
	virtual std::string getName() = 0;
	virtual ~ITank() { std::cout << "ITank destroyed\n"; }
};


class MilitaryEquipmentFactory
{
public:
	enum class EquipmentFactory
	{
		GERMAN, AMERICAN, BRITISH
	};

	virtual std::unique_ptr<IPlane> getPlane(std::string t_planeName) = 0;
	virtual std::unique_ptr<ITank> getTank(std::string t_tankName) = 0;
	virtual ~MilitaryEquipmentFactory() { std::cout << "Factory destroyed\n"; };
	
	static std::unique_ptr<MilitaryEquipmentFactory> createFactory(EquipmentFactory t_factory);
};

#endif // !ABSTRACT_FACTORY_HPP
