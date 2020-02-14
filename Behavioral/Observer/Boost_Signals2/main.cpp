#include <iostream>
#include "Journalism.hpp"


int main()
{
  Journalist professional;
  Newspaper fakt("Fakt");
  Newspaper rzeczpospolita("Rzeczpospolita");
  Newspaper wSieci("wSieci");
  Newspaper republika("Republika");
  Newspaper niezalezna("Niezalezna");

  professional.subscribe(fakt);
  professional.subscribe(rzeczpospolita);
  professional.subscribe(wSieci);
  professional.subscribe(republika);

  professional.setMessage("Hello Guys!");
  std::cout << "-------------------------\n";

  professional.unsubscribe(fakt);
  professional.subscribe(niezalezna);

  professional.setMessage("Boost is nice!");
}