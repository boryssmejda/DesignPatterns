#include "Journalism.hpp"
#include <algorithm>
#include <iostream>

void Journalist::attach(IObserver* t_io)
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


void Journalist::detach(IObserver* t_io)
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

void Journalist::notify()
{
    auto update = [&](auto& obs)
                {
                    obs->update(message);
                };

    std::for_each(observers.begin(), observers.end(), update);
}

void Journalist::setMessage(std::string_view t_message)
{
    if(this->message == t_message)
        return;

    this->message = t_message;
    notify();
}


std::string_view Journalist::getMessage() const
{
    return message;
}


 void Newspaper::update(const std::string_view& message)
 {
     m_message = message;
     printMessage();
 }


void Newspaper::printMessage()
{
    std::cout << m_newspaperName << ": " << m_message << "\n";
}