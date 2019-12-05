StrategyTest: main.cpp FlyingObject.o Helicopter.o FighterJet.o
	g++ main.cpp FlyingObject.o Helicopter.o FighterJet.o -o StrategyTest

FlyingObject.o: FlyingObject.cpp FlyingObject.hpp
	g++ FlyingObject.cpp -c

Helicopter.o: Helicopter.cpp Helicopter.hpp FlyingObject.hpp
	g++ Helicopter.cpp -c

FighterJet.o: FighterJet.cpp FighterJet.hpp FlyingObject.hpp
	g++ FighterJet.cpp -c