#include "TankFactory.hpp"
#include <iostream>

Tank* TankFactory::createTank(Tank_Model t_model)
{
    Tank* tank {nullptr};

    switch (t_model)
    {
    case Tank_Model::Sherman:
            tank = new ShermanTank();
        break;
    case Tank_Model::Tiger:
            tank = new TigerTank();
        break;
    case Tank_Model::Panther:
            tank = new PantherTank();
        break;
    default:
        std::cout << "Unknown type!\n";
        return nullptr;
    }

    return tank;
}