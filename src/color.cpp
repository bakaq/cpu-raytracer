#include <iostream>

#include "../src/Vec3.cpp"
#include "color.hpp"

Color Color::operator*(const float &f) const{
	unsigned char rr = std::min(255, (int)(r*f));
	unsigned char gg = std::min(255, (int)(g*f));
	unsigned char bb = std::min(255, (int)(b*f));
	return Color(rr, gg, bb);
}

Color Color::operator*(const Color &c) const{
	unsigned char rr = std::min(255, (int)(r*c.r));
	unsigned char gg = std::min(255, (int)(g*c.g));
	unsigned char bb = std::min(255, (int)(b*c.b));
	return Color(rr, gg, bb);	
}

Color Color::operator*(const Vec3f &v) const{
	unsigned char rr = std::min(255, (int)(r*v.x));
	unsigned char gg = std::min(255, (int)(g*v.y));
	unsigned char bb = std::min(255, (int)(b*v.z));
	return Color(rr, gg, bb);
}

Color Color::operator+(const Color &c){
	unsigned char rr = std::min(255, (int)(r+c.r));
	unsigned char gg = std::min(255, (int)(g+c.g));
	unsigned char bb = std::min(255, (int)(b+c.b));
	return Color(rr, gg, bb);
}

Color& Color::operator+=(const Color &c){
	int rr = r + c.r;
	int gg = r + c.g;
	int bb = r + c.b;
	r = std::min(255, rr);
	g = std::min(255, gg);
	b = std::min(255, bb);
	return *this;
}

bool Color::operator!=(const Color &c){
	if(r!=c.r || g!=c.g || b!=c.b){
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream &os, const Color &c){
	os << "(" << (int)c.r << " " << (int)c.g << " " << (int)c.b << ")";
	return os;
}

