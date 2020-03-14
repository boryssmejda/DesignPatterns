#ifndef AMERICAN_EQUIPMENT_HPP
#define AMERICAN_EQUIPMENT_HPP

#include "AbstractFactory.hpp"

/*================  TANKS  ===================*/
class Sherman : public ITank
{
public:
	virtual std::string getName() override;
};

class Stuart : public ITank
{
public:
	virtual std::string getName() override;
};

/*================  PLANES  ================== */
class Mustang : public IPlane
{
public:
	virtual std::string getName() override;
};

class Wildcat : public IPlane
{
public:
	virtual std::string getName() override;
};

class AmericanFactory : public MilitaryEquipmentFactory
{
public:
	virtual std::unique_ptr<IPlane> getPlane(std::string t_planeName) override;
	virtual std::unique_ptr<ITank> getTank(std::string t_tankName) override;
};

#endif // !AMERICAN_EQUIPMENT_HPP
