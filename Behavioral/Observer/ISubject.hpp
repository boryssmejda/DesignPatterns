#ifndef I_SUBJECT_HPP
#define I_SUBJECT_HPP

#include <vector>
#include "IObserver.hpp"
using std::vector;

class ISubject
{
    public:
        virtual ~ISubject(){}
        virtual void attach(IObserver* t_io) = 0;
        virtual void detach(IObserver* t_io) = 0;
        virtual void notify() = 0;
};

#endif