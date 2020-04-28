#pragma once

#include "../src/Vec3.cpp"
#include "objects.hpp"

Color trace(const std::vector<Object*> &objs, const Vec3f &rayorig, const Vec3f &raydir, int depth = 0);
void render(const std::vector<Object*> &objs);
