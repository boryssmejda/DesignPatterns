#include "Customer.hpp"

#include <iostream>
#include <utility>

CustomerBuilder Customer::make()
{
    return CustomerBuilder();
}


CustomerBuilder::operator Customer&& ()
{
    return std::move(m_customer);
}


CustomerBuilder& CustomerBuilder::setName(const string_view& t_name)
{   
    m_customer.m_name = t_name;
    return *this;
}


CustomerBuilder& CustomerBuilder::setSurname(const string_view& t_surname)
{
    m_customer.m_surname = t_surname;
    return *this;
}


CustomerBuilder& CustomerBuilder::bornOn(const string_view& t_date)
{
    m_customer.m_dateOfBirth = t_date;
    return *this;
}


CustomerBuilder& CustomerBuilder::setZipCode(const string_view& t_code)
{
    m_customer.m_zipCode = t_code;
    return *this;
}


CustomerBuilder& CustomerBuilder::street(const string_view& t_street)
{
    m_customer.m_street = t_street;
    return *this;
}


CustomerBuilder& CustomerBuilder::atTown(const string_view& t_town)
{
    m_customer.m_town = t_town;
    return *this;
}


CustomerBuilder& CustomerBuilder::atNumber(const int t_number)
{
    m_customer.m_homeNumber = t_number;
    return *this;
}


CustomerBuilder& CustomerBuilder::withMoneyOnAccount(const double t_sum)
{
    this->m_customer.m_accountBalance = t_sum;
    return *this;
}


std::ostream& operator <<(std::ostream& stream, const Customer& t_customer)
{
    stream << "Name: " << t_customer.m_name << "\n"
        << "Surname: " << t_customer.m_surname << "\n"
        << "Born: " << t_customer.m_dateOfBirth << "\n"
        << "Zip Code: " << t_customer.m_zipCode << "\n"
        << "Town: " << t_customer.m_town << "\n"
        << "Street: " << t_customer.m_street << "\n"
        << "Home Number: " << t_customer.m_homeNumber << "\n"
        << "Account Balance: " << t_customer.m_accountBalance << "\n";
    return stream;
}