#ifndef GALAXY_DW
#define GALAXY_DW
#include <string>
#include <vector>
#include "Planet.h"
class Galaxy{
public:
	unsigned int galsize;
	std::vector<Planet *> planets;
	Galaxy(std::string filename);
	~Galaxy();
	unsigned int size();
	Planet * findByName(std::string planetName);
	void printPlanets();
	std::vector<Planet *> shortestPath(Planet *, Planet *);
	double pathDistance(Planet *, Planet *);
	//double distanceBetween(Planet* , Planet*);
};
#endif
