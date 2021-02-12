#ifndef RAY_H
#define RAY_H

#include "vec.h"

typedef struct Ray {
  Vec3 origin;
  Vec3 direction;
} Ray;

Vec3 travelRay(Ray r, double distance){
  return addVec3s(r.origin,scalarMultVec3(distance,r.direction));
};

#endif
