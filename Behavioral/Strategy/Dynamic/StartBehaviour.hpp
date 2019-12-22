#include <iostream>

class StartBehaviour
{
    public:
        virtual ~StartBehaviour(){std::cout << "Start behaviour neutralised!\n";};
        virtual void beginStartingProcedure() = 0;
};

class VerticalStart: public StartBehaviour
{
    public:
        virtual void beginStartingProcedure() final
        {
            std::cout << "Preparing for vertical takeoff!\n";
        }
};


class HorizontalStart: public StartBehaviour
{
    public:
        virtual void beginStartingProcedure() final
        {
            std::cout << "Takeoff from long runway!\n";
        }
};