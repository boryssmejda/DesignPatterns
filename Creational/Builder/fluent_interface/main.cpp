#include <iostream>
#include "Customer.hpp"

int main()
{

    Customer c = Customer::make().setName("Borys")
                                 .setSurname("Smejda")
                                 .bornOn("20-12-2000")
                                 .setZipCode("92-040")
                                 .atTown("Warszawa")
                                 .street("Marszalkowska")
                                 .atNumber(34)
                                 .withMoneyOnAccount(520.50);

    std::cout << c;

    return 0;
}