#include<stdio.h>

#include "color.h"
#include "ray.h"
#include "vec.h"

Vec3 rayColor(const Ray *r) {
  Vec3 dir = normalizeVec3(r->direction);
  double p =  0.5 * (dir.y + 1.0);
  Vec3 ret = addVec3s(
		      scalarMultVec3(1.0-p,(Vec3){.x=1.0,.y=1.0,.z=1.0}),
		      scalarMultVec3(p,(Vec3){.x=0.5,.y=0.7,.z=1.0}));
  return ret;
}

int main() {
  Vec3 testVec = (Vec3) {.x=1.0,.y=3.0,.z=5.0};
  fprintf(stderr,"%f\n",lengthVec3(testVec));
  fprintf(stderr,"%f\n",lengthVec3(normalizeVec3(testVec)));
  const double aspect_ratio = 16.0/9.0;
  const int width = 400;
  const int height = (int) ( (double) width / aspect_ratio);

  const double viewport_height = 2.0;
  const double viewport_width = aspect_ratio * viewport_height;
  const double focal_length = 1.0;

  Vec3 o = origin();
  Vec3 horiz = (Vec3) {.x=viewport_width,.y=0.0,.z=0.0};
  Vec3 vert = (Vec3) {.x=0.0,.y=viewport_height,.z=0.0};
  Vec3 back = (Vec3) {.x=0.0,.y=0.0,.z=-focal_length};
  Vec3 lower_left_corner =
    addVec3s(
     addVec3s(
       addVec3s(o,scalarMultVec3(-0.5,horiz)),
       scalarMultVec3(-0.5,vert)),
     back);

  printf("P3\n%i %i\n255\n",width,height);
  for (int j = (height - 1); j >= 0 ; --j) {
    if (j % 50 == 0) {
      fprintf(stderr,"Scanlines remaining: %i\n",j);
    }
    for (int i = 0; i < width; i++) {
      double u = (double) i / (width-1);
      double v = (double) j / (height - 1);
      Vec3 dir = addVec3s(
			  addVec3s(lower_left_corner,scalarMultVec3(u,horiz)),
			  addVec3s(scalarMultVec3(v,vert),negateVec3(o)));
      Ray r = (Ray) {.origin=0,.direction=dir};
      Color c = rayColor(&r);
      write_color(stdout,c);
    }
  }
  return 0;
}
