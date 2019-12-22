#ifndef FLYING_OBJECT_HPP
#define FLYING_OBJECT_HPP

#include "AttackBehaviour.hpp"
#include "StartBehaviour.hpp"
#include <memory>

using std::string;
using std::cout;

template<typename Attack_B, typename Start_B>
class FlyingObject{

    
    protected:
        double m_wingspan;
        int m_mass;
        int m_maxSpeed;
        std::string m_modelName;
        Attack_B m_attackBehaviour;
        Start_B m_startBehaviour;

    public:
        FlyingObject(double t_wingspan = 0.0, int t_mass = 0.0 , int t_topSpeed = 0.0, string t_model = "Flying Object")
            :m_wingspan{t_wingspan},
            m_mass{t_mass},
            m_maxSpeed{t_topSpeed}
        {cout << "Flying object was constructed!\n";}
       virtual ~FlyingObject(){cout << "Flying object destroyed!";}

        void start()
        {
            m_startBehaviour.beginStartingProcedure();
        }
        virtual void attack()
        {
            m_attackBehaviour.performAttack();
        }

        virtual void display() = 0;

};

#endif