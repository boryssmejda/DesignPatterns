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
        Tank(const int t_mass, const double t_armor, const string_view t_name, const int t_crew);
        Tank() = default;

    public:
        void setTankName(string_view t_name);
        void setTankMass(int t_mass);
        void setTankCrewNumber(int t_crew);
        void setArmorThickness(double t_thickness);
        void display();
        static Tank createTank(int t_mass, double t_armor, string_view t_name, int t_crew);
};
