#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP

#include <memory>
#include <string>
#include <map>
#include <iostream>

namespace Prototype {

	class AbstractTank;
	class TankFactory;
	enum class TankModel;

	class Tiger;
	class Sherman;
	class Panther;
}
class Prototype::AbstractTank
{
protected:
	std::string m_tankModelName;
	double m_weight;

public:
	virtual std::unique_ptr<AbstractTank> clone() const = 0;
	virtual ~AbstractTank() = default;
	void displayInfo()
	{
		std::cout << m_tankModelName << " weights " << m_weight << " tons\n";
	}
};

class Prototype::Tiger : public Prototype::AbstractTank
{
public:
	Tiger();
	std::unique_ptr<AbstractTank> clone() const override;
};

class Prototype::Panther : public Prototype::AbstractTank
{
public:
	Panther();
	std::unique_ptr<AbstractTank> clone() const override;
};


class Prototype::Sherman : public Prototype::AbstractTank
{
public:
	Sherman();
	std::unique_ptr<AbstractTank> clone() const override;
};

enum class Prototype::TankModel
{
	TIGER,
	SHERMAN,
	PANTHER
};

class Prototype::TankFactory
{
	static std::map<Prototype::TankModel, std::unique_ptr<AbstractTank>> m_prototypes;
public:
	static void initalize();
	static std::unique_ptr<Prototype::AbstractTank> makeTank(Prototype::TankModel t_model);

};

#endif // !PROTOTYPE_HPP
