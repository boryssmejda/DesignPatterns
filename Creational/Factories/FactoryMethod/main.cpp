#include <iostream>
#include "Tank.hpp"

int main()
{
    Tank sherman = Tank::createTank(34, 75, "M4 Sherman", 5);
    sherman.display();

    Tank tiger = Tank::createTank(54, 120.0, "Tiger I", 5);
    tiger.display();

    return 0;
}