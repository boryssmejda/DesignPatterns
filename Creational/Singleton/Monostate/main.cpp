#include "monostate.hpp"
#include <iostream>

int main()
{
    using namespace Monostate;
    BossMonostate ceo;
    ceo.setName("Elon");
    ceo.setSurname("Musk");
    ceo.setSalary(1.0_million);

    BossMonostate ceo2;
    std::cout << ceo << ceo2;

    ceo2.setName("Jeff");
    std::cout << ceo << ceo2;
}
