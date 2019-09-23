#include "Planet.h"
#include <list>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

Planet::Planet(std::string str, long xc, long yc, long zc){
	id = str;
	x=xc;
	y=yc;
	z=zc;
}

string Planet::getName(){
	return this->id;
}

long Planet::getXCoor(){
	return this->x;
}

long Planet::getYCoor(){
	return this->y;
}

long Planet::getZCoor(){
	return this->z;
}

list<Planet *> Planet::getAdjacent(){
	return adjacents;
}
double Planet::distanceBetween(Planet * p1){
	long zd  = (p1->z - this->z)*(p1->z - this->z);
	long yd  = (p1->y - this->y)*(p1->y - this->y);
	long xd  = (p1->x - this->x)*(p1->x - this->x);
	long tot = zd+yd+xd;
	//cout << tot << endl;
	double ret = sqrt(tot);
	//cout << ret << endl;
	return ret;
}
