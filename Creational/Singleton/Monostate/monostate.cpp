#include "monostate.hpp"

using namespace Monostate;

std::string BossMonostate::m_name = "";
std::string BossMonostate::m_surname = "";
double BossMonostate::m_salary = 0;

long double Monostate::operator"" _million(long double t_salary)
{
    return t_salary * 1000000;
}

std::string BossMonostate::getName() const noexcept
{
    return m_name;
}

void BossMonostate::setName(const std::string& t_name)
{
    m_name = t_name;
}

std::string BossMonostate::getSurname() const noexcept
{
    return m_surname;
}

void BossMonostate::setSurname(const std::string& t_surname)
{
    m_surname = t_surname;
}

double BossMonostate::getSalary() const noexcept
{
    return m_salary;
}

void BossMonostate::setSalary(double t_salary)
{
    m_salary = (t_salary < 0 ? m_salary : t_salary);
}

std::ostream& Monostate::operator<<(std::ostream& os, const BossMonostate& t_boss)
{
    os << t_boss.getName() << ' ' << t_boss.getSurname() << ' ' << t_boss.getSalary() << '\n';
    return os;
}