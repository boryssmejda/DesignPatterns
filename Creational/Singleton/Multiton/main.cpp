#include "multiton.hpp"
#include <iostream>

int main()
{
    typedef Multiton<CompanyBoss, Corporations> mt;

    auto amazon = mt::get(Corporations::AMAZON);
    auto microsoft = mt::get(Corporations::MICROSOFT);
    auto google = mt::get(Corporations::GOOGLE);
    auto amazon2 = mt::get(Corporations::AMAZON);

    (amazon == amazon2 ? std::cout << "They are the same!\n" : std::cout << "Completely different!\n");
}
