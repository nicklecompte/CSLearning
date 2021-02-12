#ifndef SPHERE_H
#define SPHERE_H

#include<math.h>
#include "hittable.h"
#include "ray.h"
#include "vec.h"

typedef struct Sphere {
  Vec3 center;
  double radius;
} Sphere;
	       
bool hitSphere(Sphere s, const Ray *r, double t_min, double t_max, HitRecord *rec) {
  Vec3 offset = addVec3s(r->origin,negateVec3(s.center));
  double a = lengthSqVec3(r->direction);
  double half_b = dotProductVec3(offset,r->direction);
  double c = lengthSqVec3(offset) - s.radius*s.radius;

  double discriminant = half_b * half_b - a*c;
  if (discriminant < 0) return false;
  double sqrtd = sqrt(discriminant);

  // Find the nearest root that lies in acceptable range
  double root = (-half_b - sqrtd) / a;
  if (root < t_min || t_max < root) {
    root = (-half_b + sqrtd) / a;
    if (root < t_min || t_max > root) {
      return false;
    }
  }
  rec->t = root;
  rec->point = travelRay(*r,root);
  Vec3 outwardNormal = scalarMultVec3(1/s.radius,addVec3s(rec->point,negateVec3(s.center)));
  setFaceNormal(r,&outwardNormal,rec);
  
  return true;  
  
}

#endif
