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
        Tank() = default;

        void setTankName(string_view t_name);
        void setTankMass(int t_mass);
        void setTankCrewNumber(int t_crew);
        void setArmorThickness(double t_thickness);
        void display();
};


class TankBuilder
{
    protected:
        Tank m_tank;
    public:
        virtual ~TankBuilder(){}
        virtual void buildTankName() = 0;
        virtual void buildTankMass() = 0;
        virtual void buildTankCrew() = 0;
        virtual void buildArmorThickness() = 0;
        Tank getTank(){return m_tank;}
};

class ShermanTankBuilder : public TankBuilder
{
    public:
    virtual void buildTankName() override;
    virtual void buildTankMass() override;
    virtual void buildTankCrew() override;
    virtual void buildArmorThickness() override;
};

class TigerTankBuilder : public TankBuilder
{
    public:
    virtual void buildTankName() override;
    virtual void buildTankMass() override;
    virtual void buildTankCrew() override;
    virtual void buildArmorThickness() override;
};

// Director
class TankManufacturer
{
    private:
        std::unique_ptr<TankBuilder> m_tankBuilder;

    public:
        void setTankBuilder(std::unique_ptr<TankBuilder> t_tankBuilder);
        Tank getTank();
        void makeTank();
};
