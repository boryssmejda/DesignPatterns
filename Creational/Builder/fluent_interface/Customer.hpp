#include <string_view>
#include <utility>
#include <iostream>
using std::string_view;

class CustomerBuilder;

class Customer
{
    private:
        string_view m_name;
        string_view m_surname;
        string_view m_dateOfBirth;
        string_view m_zipCode;
        string_view m_street;
        string_view m_town;
        int m_homeNumber;
        double m_accountBalance;

        Customer() = default;
        friend CustomerBuilder;
    public:
        static CustomerBuilder make();
        friend std::ostream& operator <<(std::ostream& stream, const Customer& email);
};


class CustomerBuilder
{
    private:
        Customer m_customer;

    public:
        operator Customer&& ();
        CustomerBuilder& setName(const string_view& t_name);
        CustomerBuilder& setSurname(const string_view& t_surname);
        CustomerBuilder& bornOn(const string_view& t_date);
        CustomerBuilder& setZipCode(const string_view& t_code);
        CustomerBuilder& street(const string_view& t_street);
        CustomerBuilder& atTown(const string_view& t_town);
        CustomerBuilder& atNumber(const int t_number);
        CustomerBuilder& withMoneyOnAccount(const double t_sum);
};