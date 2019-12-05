#ifndef FLYING_OBJECT_HPP
#define FLYING_OBJECT_HPP

#include "AttackBehaviour.hpp"
#include "StartBehaviour.hpp"
#include <memory>

using std::string;
using std::cout;

class FlyingObject{

    
    protected:
        double m_wingspan;
        int m_mass;
        int m_maxSpeed;
        std::string m_modelName;
        std::unique_ptr<AttackBehaviour> m_attackBehaviour;
        std::unique_ptr<StartBehaviour> m_startBehaviour;

    public:
        FlyingObject(double t_wingspan = 0.0, int t_mass = 0.0 , int t_topSpeed = 0.0, string t_model = "Flying Object")
            :m_wingspan{t_wingspan},
            m_mass{t_mass},
            m_maxSpeed{t_topSpeed}
        {cout << "Flying object was constructed!\n";}
       virtual ~FlyingObject();

        virtual void start();
        virtual void attack();

        virtual void display();

        void setStartingBehaviour(std::unique_ptr<StartBehaviour> t_startBeh);
        void setAttackingBehaviour(std::unique_ptr<AttackBehaviour> t_attackBeh);
};

#endif