#pragma once

#include <iostream>

#include "../src/Vec3.cpp"

// Color Channel
typedef unsigned char colorch;

class Color{
public:
	colorch r, g, b;
	// Constructors
	Color() : r(0), g(0), b(0) {}
	Color(colorch gg) : r(gg), g(gg), b(gg) {}
	Color(colorch rr, colorch gg, colorch bb) : r(rr), g(gg), b(bb) {}

	// Operators
	Color operator*(const float &f) const;
	Color operator*(const Color &c) const;
	Color operator*(const Vec3f &v) const;
	Color operator+(const Color &c);
	Color& operator+=(const Color &c);
	
	bool operator!=(const Color &c);
	
	// Methods
	friend std::ostream& operator<<(std::ostream &os, const Color &c);
};
