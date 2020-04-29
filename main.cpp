#include <iostream>
#include <vector>

#include "../src/Vec3.cpp"
#include "objects.hpp"
#include "raytracer.hpp"


int main(){
	std::vector<Object*> objs;
	// Spheres
	objs.push_back(new Sphere(Vec3f(-0.3,0,-1), 0.25, Color(60, 13, 100)));
	objs.push_back(new Sphere(Vec3f(0,0,-3), 1, Color(100, 100, 100), Vec3f(0), 0.6));

	// Lights
	objs.push_back(new Sphere(Vec3f(-0.3,5,-1), 1, Color(255), Vec3f(3)));
	
	render(objs);

	for(unsigned i = 0; i < objs.size(); ++i){
		delete objs[i];
	}
}
