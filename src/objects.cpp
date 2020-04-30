#include <cmath>
#include <iostream>

#include "../src/Vec3.cpp"
#include "objects.hpp"

bool Sphere::intersect(const Vec3f &rayorig, const Vec3f &raydir, Vec3f *point_hit = NULL) const{
	Vec3f l = pos - rayorig;
	float facing = raydir.dot(l);
	if(facing <= 0){
		return false;
	}
	
	Vec3f distv = (rayorig - pos) - raydir*(raydir.dot(rayorig-pos));
	if(distv.lenght() > radius){
		return false;
	}

	float alpha = sqrt(radius - distv.lenght()*distv.lenght() + 2.0f*raydir.dot(distv));
	//std::cout << alpha << "\n";
	
	if(point_hit != NULL){
		*point_hit = pos + distv - raydir*alpha;
	}

	return true;
}

Vec3f Sphere::normal(const Vec3f &point) const{
	return (point - pos).normalize();
}

bool InfinitePlane::intersect(const Vec3f &rayorig, const Vec3f &raydir, Vec3f *point_hit = NULL) const{
	if(raydir.dot(normalDirection) >= 0){
		return false;
	}
	
	float d = ((pos - rayorig).dot(normalDirection))/(normalDirection.dot(raydir));

	if(point_hit != NULL){
		*point_hit = rayorig + raydir*d; 
	}
	return true;

}

Vec3f InfinitePlane::normal(const Vec3f &point) const{
	return normalDirection;
}
