#include "singleton.hpp"
#include <iostream>

int main()
{
    DatabaseRecordFinder datRecFinder;
    
    double canadaPopulation = datRecFinder.getTotalPopulation({"Canada"});
    std::cout << "Canada's population: " << canadaPopulation << '\n';

    double polandPopulation = datRecFinder.getTotalPopulation({"Poland"});
    std::cout << "Poland's population: " << polandPopulation << '\n';

    double europeanPopulation = datRecFinder.getTotalPopulation({"Poland", "Russia", "United Kingdom", "France"});
    std::cout << "Europe's population: " << europeanPopulation << '\n';
}
