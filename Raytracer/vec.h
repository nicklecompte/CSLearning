#ifndef VEC_H
#define VEC_H

#include<math.h>

typedef struct Vec2 {
  double x;
  double y;
} Vec2;

typedef struct Vec3 {
  double x;
  double y;
  double z;
} Vec3;

Vec2 addVec2s(Vec2 a, Vec2 b) {
  return (Vec2) {.x=a.x+b.x,.y=a.y+b.y};  
}

Vec2 scalarMultVec2(double f, Vec2 v) {
  return (Vec2) {.x=f*v.x,.y=f*v.y};
}

Vec2 negVec2(Vec2 v) {
  return (Vec2) {.x=-v.x,.y=-v.y};
}

double lengthSqVec2(Vec2 v) {
  return v.x*v.x + v.y*v.y;
}

double lengthVec2(Vec2 v){
  return sqrt(lengthSqVec2(v));
}

Vec2 normalizeVec2(Vec2 v) {
  double l = lengthVec2(v);
  return (Vec2) {.x=v.x/l,.y=v.y/l};
}

double dotProductVec2(Vec2 v1, Vec2 v2) {
  return (v1.x * v2.x) + (v1.y * v2.y);
}

Vec3 origin() {
  return (Vec3) {.x=0,.y=0,.z=0};
}

Vec3 addVec3s(Vec3 a, Vec3 b) {
  return (Vec3) {.x=a.x+b.x,.y=a.y+b.y,.z=a.z+b.z};  
}

Vec3 scalarMultVec3(double f, Vec3 v) {
  return (Vec3) {.x=f*v.x,.y=f*v.y,.z=f*v.z};
}

double dotProductVec3(Vec3 v1, Vec3 v2) {
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vec3 crossProductVec3(Vec3 v1, Vec3 v2) {
  return (Vec3) {  .x = v1.y * v2.z - v1.z * v2.y,
                   .y = v1.z * v2.x - v1.x * v2.z,
		   .z = v1.x * v2.y - v1.y * v2.x};
}

Vec3 negateVec3(Vec3 v) {
  return (Vec3) {.x=-v.x,.y=-v.y,.z=-v.z};
}

double lengthSqVec3(Vec3 v) {
  return (v.x*v.x) + (v.y*v.y) + (v.z*v.z);
}

double lengthVec3(Vec3 v) {
  return sqrt(lengthSqVec3(v));
}

Vec3 normalizeVec3(Vec3 v) {
  double l = lengthVec3(v);
  return (Vec3) {.x = v.x/l,.y=v.y/l,.z=v.z/l};
}

#endif
