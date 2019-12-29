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

Tank Tank::createTank(int t_mass, double t_armor, string_view t_name, int t_crew)
{
    return {t_mass, t_armor, t_name, t_crew};
    
}

Tank::Tank(const int t_mass, const double t_armor, const string_view t_name, const int t_crew)
{
    m_mass = t_mass;
    m_armor = t_armor;
    m_name = t_name;
    m_crew = t_crew;
}





