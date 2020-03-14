#include "AbstractFactory.hpp"

/*==================  PLANES  ==================*/
class Spitfire : public IPlane
{
public:
	virtual std::string getName() override;
};

class Hurricane : public IPlane
{
public:
	virtual std::string getName() override;
};


/*=====================  TANKS  ====================*/
class CruiserTankCrusader : public ITank
{
public:
	virtual std::string getName() override;
};

class ChurchillTankCrocodile : public ITank
{
public:
	virtual std::string getName() override;
};


class BritishFactory : public MilitaryEquipmentFactory
{
public:
	virtual std::unique_ptr<IPlane> getPlane(std::string t_planeName) override;
	virtual std::unique_ptr<ITank> getTank(std::string t_tankName) override;
};