#include "AbstractFactory.hpp"

class GermanFactory : public MilitaryEquipmentFactory
{
public:
	virtual std::unique_ptr<IPlane> getPlane(std::string t_planeName) override;
	virtual std::unique_ptr<ITank> getTank(std::string t_tankName) override;
};

class Tiger : public ITank
{
public:
	virtual std::string getName() override;
};

class Panther : public ITank
{
public:
	virtual std::string getName() override;
};

class Messerschmitt : public IPlane
{
public:
	virtual std::string getName() override;
};

class Dornier : public IPlane
{
public:
	virtual std::string getName() override;
};