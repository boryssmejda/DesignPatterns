#include "FlyingObject.hpp"
#include "Helicopter.hpp"
#include "FighterJet.hpp"
#include <memory>
#include <iostream>

int main(void)
{

    std::unique_ptr<Helicopter> helicopter = std::make_unique<Helicopter>(5.5, 11000, 350, "AH-64 Apache");
    helicopter->setStartingBehaviour(std::make_unique<VerticalStart>());
    helicopter->setAttackingBehaviour(std::make_unique<ChemicalAttack>());

    helicopter->start();
    helicopter->attack();

    helicopter->setAttackingBehaviour(std::make_unique<MachineGunAttack>());
    helicopter->attack();

   
    std::unique_ptr<FlyingObject> fighterJet = std::make_unique<FighterJet>(20.4, 16500 , 2200, "F35");
    fighterJet->setStartingBehaviour(std::make_unique<HorizontalStart>());
    fighterJet->setAttackingBehaviour(std::make_unique<RocketAttack>());

    fighterJet->start();
    fighterJet->attack();

    fighterJet->setStartingBehaviour(std::make_unique<VerticalStart>());
    fighterJet->start();

}