#include <iostream>
#include <string>
#include "FlyingObject.hpp"

using std::string;
using std::cout;

FlyingObject::~FlyingObject(){cout << "Flying object destroyed!\n";}

void FlyingObject::setStartingBehaviour(std::unique_ptr<StartBehaviour> t_startBeh)
{
    this->m_startBehaviour = std::move(t_startBeh);
}


void FlyingObject::setAttackingBehaviour(std::unique_ptr<AttackBehaviour> t_attackBeh)
{
    this->m_attackBehaviour = std::move(t_attackBeh);
}


void FlyingObject::start()
{
    m_startBehaviour->beginStartingProcedure();
}


void FlyingObject::attack()
{
    m_attackBehaviour->performAttack();
}


void FlyingObject::display()
{

}
