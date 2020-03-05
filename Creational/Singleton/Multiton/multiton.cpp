#include "multiton.hpp"

CompanyBoss::CompanyBoss(Name t_name, Surname t_surname, Salary t_salary)
{
    m_name = t_name.get();
    m_surname = t_surname.get();
    m_salary = t_salary.get();
}

void CompanyBoss::setName(std::string t_name)
{
    m_name = t_name;
}

std::string CompanyBoss::getName() const noexcept
{
    return m_name;
}

void CompanyBoss::setSurname(std::string t_surname)
{
    m_surname = t_surname;
}

std::string CompanyBoss::getSurname() const noexcept
{
    return m_surname;
}

void CompanyBoss::setSalary(double t_salary)
{
    if(t_salary < 0)
        throw std::runtime_error("Salary cannot be negative!");

    m_salary = t_salary;
}

double CompanyBoss::getSalary() const noexcept
{
    return m_salary;
}
