#include "Journalism.hpp"
#include <algorithm>
#include <iostream>


void Journalist::setMessage(std::string_view t_message)
{
    if(this->message == t_message)
        return;

    this->message = t_message;
    m_sig(t_message);
}


std::string_view Journalist::getMessage() const
{
    return message;
}


void Journalist::subscribe(Newspaper& t_newspaper)
{ 
   m_sig.connect(boost::bind(&Newspaper::update, &t_newspaper , _1)); 
}


void Journalist::unsubscribe(Newspaper& t_newspaper)
{ 
    m_sig.disconnect(boost::bind(&Newspaper::update, &t_newspaper , _1)); 
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
