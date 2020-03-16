#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include <string_view>
#include <string>

void* operator new(size_t size)
{
	void * p = malloc(size); 
	return p;
}

void operator delete(void* p)
{
	free(p);
}

class MoveBehaviour
{
public:
	virtual void move() = 0;
	virtual ~MoveBehaviour() = default;
};

class Flying : public MoveBehaviour
{
public:
	virtual void move() override
	{
		std::cout << "Flying high in the skies\n";
	}
};

class Swimming : public MoveBehaviour
{
public:
	virtual void move() override
	{
		std::cout << "Swim through the oceans\n";
	}
};

class Driving : public MoveBehaviour
{
public:
	virtual void move() override
	{
		std::cout << "Driving fast on highways\n";
	}
};

class Vehicle
{
protected:
	std::string_view m_name;
	MoveBehaviour* m_moveBehaviour;
	Vehicle(std::string_view t_name, MoveBehaviour* t_behaviour) : 
		m_name{ t_name }, 
		m_moveBehaviour{ t_behaviour }
	{}
public:
	virtual void moveMe() = 0;
	virtual ~Vehicle()
	{
		if (m_moveBehaviour)
			delete m_moveBehaviour;
	}
};

class Car : public Vehicle
{
public:
	Car(std::string_view t_name, MoveBehaviour* t_behaviour) : 
		Vehicle(t_name, t_behaviour){}
	
	virtual void moveMe() override 
	{
		m_moveBehaviour->move();
	}
};

class Plane : public Vehicle
{
public:
	Plane(std::string_view t_name, MoveBehaviour* t_behaviour) :
		Vehicle(t_name, t_behaviour) {}

	virtual void moveMe() override
	{
		m_moveBehaviour->move();
	}
};

class Ship : public Vehicle
{
public:
	Ship(std::string_view t_name, MoveBehaviour* t_behaviour) :
		Vehicle(t_name, t_behaviour) {}

	virtual void moveMe() override
	{
		m_moveBehaviour->move();
	}
};

int main()
{

	Vehicle* car = new Car("Ferrari", new Driving);
	car->moveMe();

	Vehicle* ship = new Ship("Aircraft carrier", new Swimming);
	ship->moveMe();

	Vehicle* plane = new Plane("Boeing", new Flying);
	plane->moveMe();

	delete car;
	delete ship;
	delete plane;

	_CrtDumpMemoryLeaks();
}
