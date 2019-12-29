#pragma once
#include <string_view>
#include <memory>

using std::string_view;

class Tank
{
    private:
        string_view m_name;
        int m_mass;
        int m_crew;
        double m_armor;
        

    public:
        void setTankName(string_view t_name);
        void setTankMass(int t_mass);
        void setTankCrewNumber(int t_crew);
        void setArmorThickness(double t_thickness);
        void display();
        Tank() = default;
};


class ShermanTank : public Tank
{
    public:
        ShermanTank();
};


class TigerTank : public Tank
{
    public:
        TigerTank();
};


class PantherTank : public Tank
{
    public:
        PantherTank();
};