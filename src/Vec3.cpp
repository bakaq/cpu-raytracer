#pragma once

#include <iostream>

#include <Vec3.hpp>

// Operators
template<typename T>
Vec3<T> Vec3<T>::operator*(const T &f) const{
	return Vec3<T>(x*f, y*f, z*f);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const Vec3<T> &v) const{
	return Vec3<T>(x*v.x, y*v.y, z*v.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Vec3<T> &v) const{
	return Vec3<T>(x+v.x, y+v.y, z+v.z);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Vec3<T> &v) const{
	return Vec3<T>(x-v.x, y-v.y, z-v.z);
}

template<typename T>
Vec3<T>& Vec3<T>::operator+=(const Vec3<T> &v) const{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(const Vec3<T> &v) const{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

template<typename T>
bool Vec3<T>::operator!=(const Vec3<T> &v) const{
    if(v.x!=x || v.y!=y || v.z!=z){
		return true;
	}
	return false;
}


template<typename T>
T Vec3<T>::dot(const Vec3<T> &v) const{
	return x*v.x + y*v.y + z*v.z; 
}

// Methods

template<typename T>
T Vec3<T>::lenght() const{
	return sqrt(x*x + y*y + z*z);
}

template<typename T>
Vec3<T>& Vec3<T>::normalize(){
	T len = lenght();
	x /= len;
	y /= len;
	z /= len;
	return *this;
}

template<typename U>
std::ostream& operator<<(std::ostream &os, const Vec3<U> &v){
	os << "[" << v.x << " " << v.y << " " << v.z << "]";
	return os;
}

