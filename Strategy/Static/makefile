StrategyTest: main.cpp Helicopter.o FighterJet.o
	g++ $^ -o $@

Helicopter.o: Helicopter.cpp Helicopter.hpp FlyingObject.hpp
	g++ Helicopter.cpp -c

FighterJet.o: FighterJet.cpp FighterJet.hpp FlyingObject.hpp
	g++ FighterJet.cpp -c

clean:
	rm *.o
