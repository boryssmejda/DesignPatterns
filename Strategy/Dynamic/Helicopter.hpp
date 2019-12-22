#ifndef HELICOPTER_HPP
#define HELICOPTER_HPP

#include "FlyingObject.hpp"

class Helicopter : public FlyingObject
{   
    public:
    Helicopter(double t_wingspan, int t_mass, int t_topSpeed, std::string t_model): 
        FlyingObject(t_wingspan, t_mass, t_topSpeed, t_model)
    {}

    void display() override;
};

#endif