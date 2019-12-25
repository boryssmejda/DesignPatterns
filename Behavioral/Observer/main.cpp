#include "Journalism.hpp"
#include <iostream>
#include <memory>

void* operator new(std::size_t count){
    std::cout << "   " << count << " bytes" << std::endl;
    return malloc(count);
}


int main()
{
    Journalist professional;

    IObserver* fakt = new Newspaper("Fakt", professional);
    IObserver* rzeczpospolita = new Newspaper("Rzeczpospolita", professional);
    IObserver* wSieci = new Newspaper("wSieci", professional);
    IObserver* republika = new Newspaper("Republika", professional);

    professional.attach(fakt);
    professional.attach(rzeczpospolita);
    professional.attach(wSieci);

    professional.setMessage("Christmas is coming!");

    professional.detach(wSieci);
    professional.attach(republika);

    professional.setMessage("War is over!");

    std::cout << "-----------------------------\n";

    professional.setMessage("Welcome new year 2020!");

    delete fakt;
    delete rzeczpospolita;
    delete wSieci;
    delete republika;

    return 0;
}