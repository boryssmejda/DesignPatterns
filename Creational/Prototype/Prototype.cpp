#include "Prototype.hpp"

using namespace Prototype;

std::map<Prototype::TankModel, std::unique_ptr<AbstractTank>> Prototype::TankFactory::m_prototypes;

void Prototype::TankFactory::initalize()
{
	m_prototypes[TankModel::TIGER] = std::make_unique<Tiger>();
	m_prototypes[TankModel::SHERMAN] = std::make_unique<Sherman>();
	m_prototypes[TankModel::PANTHER] = std::make_unique<Panther>();
}


[[nodiscard]] std::unique_ptr<Prototype::AbstractTank> Prototype::TankFactory::makeTank(Prototype::TankModel t_model)
{
	using Prototype::TankModel;
	switch (t_model)
	{
	case TankModel::TIGER:
		return m_prototypes[TankModel::TIGER]->clone();
		break;
	case TankModel::SHERMAN:
		return m_prototypes[TankModel::SHERMAN]->clone();
		break;
	case TankModel::PANTHER:
		return m_prototypes[TankModel::PANTHER]->clone();
		break;
	}
}

Prototype::Tiger::Tiger()
{
	m_tankModelName = "Tiger";
	m_weight = 68.5;
}

Prototype::Sherman::Sherman()
{
	m_tankModelName = "Sherman" ;
	m_weight = 32.5;
}

Prototype::Panther::Panther()
{
	m_tankModelName = "Panther";
	m_weight = 45.2;
}


std::unique_ptr<Prototype::AbstractTank> Prototype::Tiger::clone() const
{
	return std::make_unique<Tiger>(*this);
}

std::unique_ptr<AbstractTank> Prototype::Panther::clone() const
{
	return std::make_unique<Panther>(*this);
}

std::unique_ptr<AbstractTank> Prototype::Sherman::clone() const
{
	return std::make_unique<Sherman>();
}
