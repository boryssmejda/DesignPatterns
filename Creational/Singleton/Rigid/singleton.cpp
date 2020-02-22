#include "singleton.hpp"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <stdexcept>
#include <string_view>

SingletonDatabase::SingletonDatabase()
{
    std::cout << "Initializing database" << std::endl;

    std::ifstream inputData("../populations.txt");
    if (!inputData) 
    {
        std::cerr << "Unable to open file populations.txt\n";
        throw std::runtime_error("File populations.txt could not be opened\n");
    }

    std::string countryName{""}, populationInCountry{""};
    while(getline(inputData, countryName))
    {
        getline(inputData, populationInCountry);
        double populationNum = boost::lexical_cast<double>(populationInCountry);
        m_countriesPopulation[countryName] = populationNum;
    }
}

double SingletonDatabase::getCountryPopulation(const std::string& t_country)
{
    return m_countriesPopulation.at(t_country);
}



double DatabaseRecordFinder::getTotalPopulation(const std::vector<std::string>& t_countries)
{
    double totalPopulation{0.0};
    for(const auto& country: t_countries)
        totalPopulation += SingletonDatabase::getInstance().getCountryPopulation(country);

    return totalPopulation;
}