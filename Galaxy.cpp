#include "Galaxy.h"
#include "Planet.h"
#include <string>
#include <string.h>
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cfloat>
#include <limits>
#include <queue>

using namespace std;

Galaxy::Galaxy(string filename){
	ifstream inFile;
	inFile.open(filename);
	if(!inFile.is_open()){
		cout << "file could not be opened" << endl;
	}
	else{
		string id;
		long x;
		long y;
		long z;
		while(!inFile.eof() && !inFile.fail()){
			inFile >> id;
			cout << id << endl;
			inFile >> x;
			inFile >> y;
			inFile >> z;
			if(strcmp(id.c_str(),filename.c_str())==0){
			}
			else if(!inFile.fail()){
				inFile.ignore(1000, '\n');
				Planet * p = new Planet(id,x,y,z);
				planets.push_back((p));
			}
		}
		inFile.clear();
	}
	inFile.close();

	galsize = planets.size();


	 //unsigned double maxdist = -1;
	for(int i = 0 ; i < planets.size(); i++){
		Planet * curr = planets[i];
		Planet * adj[4];
		for(int i = 0 ; i < 4 ; i++){
			adj[i]=nullptr;
		}	//changed to pointer
		for(int j = 0 ; j < planets.size() ; j++){
			double maxdist = 0;
			cout << i << endl;
			cout << j << endl;
			if(strcmp(planets[j]->getName().c_str(), planets[i]->getName().c_str()) == 0) {
				cout << "nope" << endl;
				//empty
			}
			else{
				//if(curr->distanceBetween(planets[j]) < maxdist){
					if(adj[0] == nullptr) adj[0] = planets[j];
					else if(adj[1] == nullptr) adj[1] = planets[j];
					else if(adj[2] == nullptr) adj[2] = planets[j];
					else if(adj[3] == nullptr) adj[3] = planets[j];
					else{
						for(int k = 0; k < 4; k++) {
							if(adj[k]->distanceBetween(planets[i]) > maxdist) maxdist = adj[k]->distanceBetween(planets[i]);
						}
						if(planets[i]->distanceBetween(planets[j])<maxdist){
							for(int q = 0 ; q < 4 ; q++){
								if(adj[q]->distanceBetween(planets[i])==maxdist){
									adj[q]=planets[j];
								}
							}
						}
					}
				//}

			}
		}
		for(int q = 0 ; q < 4 ; q++){
			planets[i]->adjacents.push_back(adj[q]);
		}
	}
}

// double Galaxy::distanceBetween(Planet * p1 , Planet * p2){
// 	long zd  = (p1->z - p2->z)*(p1->z - p2->z);
// 	long yd  = (p1->y - p2->y)*(p1->y - p2->y);
// 	long xd  = (p1->x - p2->x)*(p1->x - p2->x);
// 	long tot = zd+yd+xd;
// 	double ret = sqrt(tot);
// 	return ret;
// }
vector<Planet *> Galaxy::shortestPath(Planet * start, Planet * dest){
	queue<Planet *> q;
	vector<double> dist;
	vector<Planet *> op;
	for(int i = 0 ; i < planets.size() ; i++){
		dist.push_back(DBL_MAX);
		op.push_back(nullptr);
	}
	int index = 0;
	for(int i = 0 ; i < planets.size() ; i++){
		q.push(planets[i]);
		if(planets[i]==start){
			index = i;
		}
	}
	for(auto i = start->adjacents.begin() ; i != start->adjacents.end() ; i++){
		for(int j = 0 ; j < planets.size() ; j++){
			if(*i == planets[j]){
				if((*i)->distanceBetween(start) < dist[j]){
					dist[j] = (*i)->distanceBetween(start);
					op[j] = *i;
				}
			}
		}
	}
}

double Galaxy::pathDistance(Planet * start, Planet * dest){

}
unsigned int Galaxy::size() {
	return galsize;
}

Planet * Galaxy::findByName(std::string planetName) {
	for(int i = 0; i < planets.size(); i++) {
		if(strcmp(planets[i]->getName().c_str(), planetName.c_str()) == 0) return planets[i];
	}
	return nullptr;
}

void Galaxy::printPlanets() {
	for(int i = 0; i < planets.size(); i++) {
		cout << "Planet Name: " << planets[i]->getName() << endl;
		cout << "Adjacents: ";
		list<Planet*> p1 = planets[i]->getAdjacent();
		for(auto it = p1.begin(); it != p1.end(); ++it) {
			cout << (*it)->getName() << endl;
		}
		cout << "_________________________________________________" << endl;
	}
}
