#include "Tank.hpp"
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



ShermanTank::ShermanTank()
{
    setTankName("M4 Sherman");
    setTankMass(34);
    setTankCrewNumber(5);
    setArmorThickness(75);
}


PantherTank::PantherTank()
{
    setTankName("Panther");
    setTankMass(45);
    setTankCrewNumber(5);
    setArmorThickness(100);
}


TigerTank::TigerTank()
{
    setTankName("Tiger I");
    setTankMass(54);
    setTankCrewNumber(5);
    setArmorThickness(120);
}