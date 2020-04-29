#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

#include "../src/Vec3.cpp"
#include "objects.hpp"
#include "color.hpp"

#define MAX_DEPTH 5

const Color BACKGROUND_COLOR(255, 255, 255);

Color trace(
	const std::vector<Object*> &objs, 
	const Vec3f &rayorig,
	const Vec3f &raydir,
	int depth = 0
){
	// Find closest intersection point and object
	Color rayColor(0, 0, 0);
	const Object *obj_hit = NULL;
	Vec3f point_hit(0);
	for(auto obj: objs){
		Vec3f point_hit_tmp;
		if(obj->intersect(rayorig, raydir, &point_hit_tmp)){
			if(obj_hit == NULL || (point_hit_tmp-rayorig).lenght() < (point_hit-rayorig).lenght()){
				obj_hit = obj;
				point_hit = point_hit_tmp;
			}
		}
	}
	
	// If hit nothing color is background
	if(obj_hit == NULL){
		return BACKGROUND_COLOR;
	}
	
	Vec3f normal = obj_hit->normal(point_hit);

	if(depth < MAX_DEPTH && obj_hit->reflectivity > 0){
		// Reflections
		Vec3f in = point_hit - rayorig;
		in.normalize();
		Vec3f out = in - normal*2*(normal.dot(in));
		out.normalize();
		Color outRay = trace(objs, point_hit + normal*1e-6, out, depth+1);
		rayColor += outRay * obj_hit->reflectivity;
	}else if(obj_hit->reflectivity < 1){
		// Cast shadow ray
		for(unsigned i = 0; i < objs.size(); ++i){
			if(objs[i]->emissionColor != Vec3f(0)){
				float transmission = 1;
				Vec3f lightDirection = objs[i]->pos - point_hit;
				lightDirection.normalize();
				for(unsigned j = 0; j < objs.size(); ++j){
					if(i != j){
						if(objs[j]->intersect(point_hit, lightDirection)){
							transmission = 0;
							break;
						}
					}
				}
				//std::cout << "objs[i] * transmission: " << (objs[i]->emissionColor * transmission) << "\n";
				rayColor += obj_hit->surfaceColor * (objs[i]->emissionColor * transmission)
						* std::max(float(0), normal.dot(lightDirection)) * (1-obj_hit->reflectivity);
			}
		}
	}
	return rayColor + (Color(255)*obj_hit->emissionColor);
}


void render(const std::vector<Object*> &objs){
	unsigned width = 640;
	unsigned height = 480;
	Color *image = new Color[width*height];
	Color *pixel = image;
	float invWidth = 1/float(width);
    float invHeight = 1/float(height);
    float fov = 30; 
    float aspectRatio = width/float(height);
    float angle = tan(3.141592653589793* 0.5 * (fov/180.0));
	// Trace rays
	for(unsigned y = 0; y < height; ++y){
		for(unsigned x = 0; x < width; ++x, ++pixel){
			float xx = (2*(x+0.5)*invWidth - 1) * angle * aspectRatio;
			float yy = (1 - 2*(y+0.5)*invHeight) * angle;
			Vec3f raydir(xx, yy, -1);
			raydir.normalize();
			*pixel = trace(objs, Vec3f(0), raydir);
		}
	}
	// Save to PPM
	std::ofstream ofs("./image.ppm", std::ios::out | std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";
	for(unsigned i = 0; i < width*height; ++i){
		ofs << image[i].r << image[i].g << image[i].b;
	//	std::cout << "Motherfucker" << image[i].r << image[i].g << image[i].b; 	
	}
	ofs.close();
	delete [] image;
}	
