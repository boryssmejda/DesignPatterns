#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <string>
#include <vector>
#include <map>

class SingletonDatabase
{
    public:
        static SingletonDatabase& getInstance()
        {
            static SingletonDatabase s_dbConnection;
            return s_dbConnection;
        }

        double getCountryPopulation(const std::string& t_country);

    private:
        SingletonDatabase();
        ~SingletonDatabase() = default;
        SingletonDatabase(const SingletonDatabase&)            = delete;
        SingletonDatabase& operator=(const SingletonDatabase&) = delete;

        std::map<std::string, double> m_countriesPopulation;
};

struct DatabaseRecordFinder{
    double getTotalPopulation(const std::vector<std::string>& t_countries);
};

#endif