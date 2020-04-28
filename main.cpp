#include <iostream>
#include <vector>

#include "../src/Vec3.cpp"
#include "objects.hpp"
#include "raytracer.hpp"


int main(){
	std::vector<Object*> objs;
	// Spheres
	objs.push_back(new Sphere(Vec3f(0,0,-4), 1, Color(60, 13, 100)));

	// Lights
	objs.push_back(new Sphere(Vec3f(0,5,0), 1, Color(255), Vec3f(1)));
	
	render(objs);

	for(unsigned i = 0; i < objs.size(); ++i){
		delete objs[i];
	}
}
