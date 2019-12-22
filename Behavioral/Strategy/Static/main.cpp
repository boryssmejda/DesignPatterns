#include "FlyingObject.hpp"
#include "Helicopter.hpp"
#include "FighterJet.hpp"
#include <memory>
#include <iostream>

int main(void)
{

    Helicopter helicopter(5.5, 11000, 350, "AH-64 Apache"); 
    helicopter.start();
    helicopter.attack();
   
    FighterJet fighterJet(20.4, 16500 , 2200, "F35");
    fighterJet.start();
    fighterJet.attack();

}