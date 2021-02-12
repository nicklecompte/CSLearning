#ifndef HITTABLE_H
#define HITTABLE_H

#include "vec.h"
#include "ray.h"
#include<stdbool.h>

typedef struct HitRecord {
  Vec3 point;
  Vec3 normal_vec;
  double t;
  bool frontFace;
} HitRecord;

void setFaceNormal(const Ray *r, const Vec3 *outward_normal, HitRecord *hr) {
  hr->frontFace = dotProductVec3(r->direction,*outward_normal) < 0;
  hr->normal_vec = hr->frontFace ? *outward_normal : negateVec3(*outward_normal);
}


#endif


