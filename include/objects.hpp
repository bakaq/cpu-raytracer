#pragma once

#include <../src/Vec3.cpp>
#include <color.hpp>

// Base object class
class Object{
public:
	// Standard parameters
	Vec3f pos;
	Color surfaceColor;
	Vec3f emissionColor;

	// Standard Constructor
	Object(
		const Vec3f &p = Vec3f(0),
		const Color &sc = Color(0),
		const Vec3f &ec = Vec3f(0)
	) : pos(p), surfaceColor(sc), emissionColor(ec) {}
	
	// Intersection virtual function
	virtual bool intersect(const Vec3f &rayorig, const Vec3f &raydir, Vec3f *point_hit = NULL) const{(void)rayorig;(void)raydir;(void)point_hit;return false;}
	virtual Vec3f normal(const Vec3f &point) const{(void)point;return Vec3f(0);}
};

class Sphere: public Object{
public:
	float radius;
	Sphere(
		const Vec3f &p = Vec3f(0),
		const float &r = 1,
		const Color &sc = Color(0),
		const Vec3f &ec = Vec3f(0)
	) : Object(p, sc, ec), radius(r) {}
	bool intersect(const Vec3f &rayorig, const Vec3f &raydir, Vec3f *point_hit) const;
	Vec3f normal(const Vec3f &point) const;
};
