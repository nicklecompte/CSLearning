#ifndef COLOR_H
#define COLOR_H

#include "vec.h"
#include<stdio.h>

typedef Vec3 Color;

void write_color(FILE *out, Color pixel_color) {
  int ir = (int) 255.999*(pixel_color.x);
  int ig = (int) 255.999*(pixel_color.y);
  int ib = (int) 255.999*(pixel_color.z);
  fprintf(out,"%i %i %i\n", ir,ig,ib);
}

#endif
