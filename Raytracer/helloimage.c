#include<stdio.h>

#include "color.h"

int main() {

  Vec2 myVec2 = addVec2s((Vec2) {.x=0.0,.y=-.0},(Vec2) {.x=1.0,.y=1.0});

  const int image_width = 256;
  const int image_height = 256;
  

  printf("P3\n%i %i\n255\n", image_width, image_height);

  for(int j = image_height-1; j>=0;j--) {
    if (j % 50 == 0) {
      fprintf(stderr,"Scanlines remaining: %i\n",j);
    }
    for(int i = 0; i < image_width; i++) {
      Color cur = (Color) {.x = (double) i/(image_width-1),
			   .y = (double) j/(image_height-1),
			   .z = 0.25,};
      write_color(stdout,cur);
    }
  }
  
};
