#include "Builder.hpp"
#include <iostream>

void Tank::setTankName(string_view t_name)
{
    this->m_name = t_name;
}


void Tank::setTankMass(int t_mass)
{
    this->m_mass = t_mass;
}


void Tank::setTankCrewNumber(int t_crew)
{
    this->m_crew = t_crew;
}


void Tank::setArmorThickness(double t_thickness)
{
    this->m_armor = t_thickness;
}


void Tank::display()
{
    std::cout << "Name: " << m_name << "\n"
            << "Mass: " << m_mass << "\n"
            << "Armor: " << m_armor << "\n"
            << "Crew: " << m_crew << "\n";
}


// SHERMAN TANK BUILDER 
void ShermanTankBuilder::buildTankName()
{
    m_tank.setTankName("M4 Sherman");
}
void ShermanTankBuilder::buildTankMass()
{
    m_tank.setTankMass(34);
}
void ShermanTankBuilder::buildTankCrew()
{
    m_tank.setTankCrewNumber(5);
}
void ShermanTankBuilder::buildArmorThickness()
{
    m_tank.setArmorThickness(75);
}


// Tiger Tank Builder
void TigerTankBuilder::buildTankName()
{
    m_tank.setTankName("Tiger I");
}
void TigerTankBuilder::buildTankMass()
{
    m_tank.setTankMass(54);
}
void TigerTankBuilder::buildTankCrew()
{
    m_tank.setTankCrewNumber(5);
}
void TigerTankBuilder::buildArmorThickness()
{
    m_tank.setArmorThickness(120);
}


void TankManufacturer::setTankBuilder(std::unique_ptr<TankBuilder> t_tankBuilder)
{
    this->m_tankBuilder = std::move(t_tankBuilder);
}

Tank TankManufacturer::getTank()
{
    return this->m_tankBuilder->getTank();
}

void TankManufacturer::makeTank()
{
    m_tankBuilder->buildTankName();
    m_tankBuilder->buildTankMass();
    m_tankBuilder->buildTankCrew();
    m_tankBuilder->buildArmorThickness();
}