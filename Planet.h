#ifndef PLANET_DW
#define PLANET_DW
#include <list>
#include <string>
#include <iostream>
class Planet{
public:
	std::string id;
	long x;
	long y;
	long z;
	Planet(std::string, long , long , long);
	std::string getName();
	long getXCoor();
	long getYCoor();
	long getZCoor();
	std::list<Planet *> getAdjacent();
	std::list<Planet *> adjacents;
	double distanceBetween(Planet * p1);
};
#endif
