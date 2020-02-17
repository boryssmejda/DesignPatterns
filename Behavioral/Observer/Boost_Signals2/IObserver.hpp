#ifndef I_OBSERVER_HPP
#define I_OBSERVER_HPP

#include <string_view>

class IObserver
{
    public:
        virtual ~IObserver(){}
        virtual void update(const std::string_view& message) = 0;
};

#endif
