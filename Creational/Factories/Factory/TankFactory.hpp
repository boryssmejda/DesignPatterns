#include "Tank.hpp"


enum class Tank_Model
{
    Sherman, Tiger, Panther
};

class TankFactory
{
    private:
        TankFactory() = default;
    public:
        static Tank* createTank(Tank_Model t_model);
};