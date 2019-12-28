#include <iostream>
#include "Builder.hpp"

int main()
{
    std::unique_ptr<ShermanTankBuilder> shermanBuilder(std::make_unique<ShermanTankBuilder>());
    TankManufacturer tankManufacturer;

    tankManufacturer.setTankBuilder(std::move(shermanBuilder));
    tankManufacturer.makeTank();
    Tank tank = tankManufacturer.getTank();
    tank.display();

    tankManufacturer.setTankBuilder(std::make_unique<TigerTankBuilder>());
    tankManufacturer.makeTank();
    tank = tankManufacturer.getTank();
    tank.display();

    return 0;
}