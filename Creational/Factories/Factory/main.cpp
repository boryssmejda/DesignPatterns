#include <iostream>
#include "TankFactory.hpp"

int main()
{
    Tank* tank {nullptr};
    while (true)
    {
        char answer;
        std::cout << "What kind of tank?\n"
            << "Sherman (S):\n"
            << "Tiger (T):\n"
            << "Panther (P):\n"
            << "Answer: ";
        std::cin >> answer;
        switch (answer)
        {
        case 'S':
        case 's':
            tank = TankFactory::createTank(Tank_Model::Sherman);
            break;
        case 'T':
        case 't':
            tank = TankFactory::createTank(Tank_Model::Tiger);
            break;
        case 'P':
        case 'p':
            tank = TankFactory::createTank(Tank_Model::Panther);
            break;
        default:
            break;
        }

        tank->display();
        delete tank;
        tank = nullptr;
    }
    

    return 0;
}