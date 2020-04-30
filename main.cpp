#include <iostream>
#include <vector>

#include "../src/Vec3.cpp"
#include "objects.hpp"
#include "raytracer.hpp"


int main(){
	std::vector<Object*> objs;
	// Ground
	objs.push_back(new InfinitePlane(Vec3f(0,-1,0), Vec3f(0,1,0), Color(250)));

	// Spheres
	objs.push_back(new Sphere(Vec3f(-0.5,0,-3), 0.25, Color(60, 13, 100)));
	objs.push_back(new Sphere(Vec3f(0,0,-5), 1, Color(100, 100, 100), Vec3f(0), 0.6));

	// Lights
	objs.push_back(new Sphere(Vec3f(0,5,-2), 1, Color(255), Vec3f(3)));
	
	render(objs);

	for(unsigned i = 0; i < objs.size(); ++i){
		delete objs[i];
	}
}
