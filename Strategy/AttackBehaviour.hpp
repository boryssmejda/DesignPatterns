#include <iostream>

class AttackBehaviour
{
    public:
        virtual ~AttackBehaviour(){std::cout << "Attack behaviour neatralsed!\n";}
        virtual void performAttack() = 0;
};

class MachineGunAttack : public AttackBehaviour
{
    public:
        virtual void performAttack() final
        {
            std::cout << "Machine gun attack!!\n";
        }
};

class RocketAttack : public AttackBehaviour
{
    public:
        virtual void performAttack() final
        {
            std::cout << "Setting off the rocket!! Fire!\n";
        }
};

class ChemicalAttack : public AttackBehaviour
{
    public:
        virtual void performAttack() final
        {
            std::cout << "Mustard gas release over the enemy territory!\n";
        }
};