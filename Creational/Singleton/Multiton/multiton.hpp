#ifndef MULTITON_HPP
#define MULTITON_HPP

#include <map>
#include <memory>
#include <string>

enum class Corporations
{
    AMAZON,
    GOOGLE,
    MICROSOFT
};

template<typename T, typename Key = std::string>
class Multiton
{
    private:
        Multiton() = default;
        Multiton(const Multiton& t_corporations) = delete;
        Multiton& operator=(const Multiton& t_corporations) = delete;
        static std::map<Key, std::shared_ptr<T>> m_instances;

    public:
        static std::shared_ptr<T> get(const Key& t_key)
        {
            
            if(auto it = m_instances.find(t_key);
                it != m_instances.end())
            {
                return it->second;
            }
            
            auto element = std::make_shared<T>();
            m_instances[t_key] = element;
            return element;
        }
    protected:
         ~Multiton() = default;
};

template<typename T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::m_instances;


template <typename T, typename Parameter>
class NamedType
{
public:
    explicit NamedType(T const& t_value) : m_value(t_value) {}
    explicit NamedType(T&& t_value) : m_value(std::move(t_value)) {}
    T& get() { return m_value; }
    T const& get() const {return m_value; }
private:
    T m_value;
};

using Name = NamedType<std::string, struct NameParameter>;
using Surname = NamedType<std::string, struct SurnameParameter>;
using Salary = NamedType<double, struct SalaryParameter>;


class CompanyBoss
{
    public:
        CompanyBoss(Name t_name, Surname t_surname, Salary t_salary);
        CompanyBoss() = default;

        void setName(std::string t_name);
        std::string getName() const noexcept;

        void setSurname(std::string t_surname);
        std::string getSurname() const noexcept;

        void setSalary(double t_salary);
        double getSalary() const noexcept;


    private:
        std::string m_name, m_surname;
        double m_salary;
};

#endif