#pragma once

#include <iostream>
#include <cmath>

template<typename T>
class Vec3{
public:
	// Components
	T x, y, z;
	
	// Constructors
	Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(T xx) : x(xx), y(xx), z(xx) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
	
	// Operators
	Vec3<T> operator*(const T &f) const;
	Vec3<T> operator*(const Vec3<T> &v) const;
	Vec3<T> operator+(const Vec3<T> &v) const;
	Vec3<T> operator-(const Vec3<T> &v) const;
	Vec3<T>& operator+=(const Vec3<T> &v) const;
	Vec3<T>& operator*=(const Vec3<T> &v) const;
	Vec3<T> operator-() const;

	bool operator!=(const Vec3<T> &v) const;

	T dot(const Vec3<T> &v) const;
	//Vec3<T> cross(const Vec3<T> &v) const;
	
	// Methods
	Vec3<T>& normalize();
	T lenght() const;
	
	template<typename U>
	friend std::ostream& operator<<(std::ostream &os, const Vec3<U> &v);
};

typedef Vec3<float> Vec3f;
