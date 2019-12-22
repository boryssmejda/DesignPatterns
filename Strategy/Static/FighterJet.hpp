#ifndef FIGHTER_JET_HPP
#define FIGHTER_JET_HPP

#include "FlyingObject.hpp"

class FighterJet : public FlyingObject<RocketAttack, HorizontalStart>
{
    public:
    FighterJet(double t_wingspan, int t_mass, int t_topSpeed, std::string t_model): 
        FlyingObject(t_wingspan, t_mass, t_topSpeed, t_model)
    {}

    void display() override;
};

#endif