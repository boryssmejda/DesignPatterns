#ifndef MONOSTATE_HPP
#define MONOSTATE_HPP

#include <string>
#include <iostream>

namespace Monostate
{
    class BossMonostate;
    long double operator"" _million(long double t_salary);
}

class Monostate::BossMonostate
{
    static std::string m_name, m_surname;
    static double m_salary;

public:
    std::string getName() const noexcept;
    void setName(const std::string& t_name);

    std::string getSurname() const noexcept;
    void setSurname(const std::string& t_surname);

    double getSalary() const noexcept;
    void setSalary(double t_salary);

    friend std::ostream& operator<<(std::ostream& os, const BossMonostate& t_boss);
};

#endif