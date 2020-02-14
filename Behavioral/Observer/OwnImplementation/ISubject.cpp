#include "ISubject.hpp"

#include <algorithm>
#include <iostream>

void ISubject::attach(IObserver* t_io)
{
    auto result = std::find(observers.begin(), observers.end(), t_io);

    if (result == std::end(observers))
    {    
        observers.push_back(t_io);
        std::cout << "No such object in collection\n";
    }
    else
    {
        std::cout << "Object already subscribes!\n";
    }
}


void ISubject::detach(IObserver* t_io)
{
    auto result = std::find(observers.begin(), observers.end(), t_io);

    if (result != std::end(observers))
    {    
        observers.erase(result);
        std::cout << "Object erased\n";
    }
    else
    {
        std::cout << "No such subscriber exists!\n";
    }
}

void ISubject::notify()
{
    auto update = [](auto& obs)
                {
                    obs->update();
                };

    std::for_each(observers.begin(), observers.end(), update);
}
