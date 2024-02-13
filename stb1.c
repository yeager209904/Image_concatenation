#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
//reading image
#define STB_IMAGE_IMPLEMENTATION
#include "C:\Users\aneru\OneDrive\Desktop\AMRITA\PROBLEM SOLVING AND C PROGRAMMING\stb-master/stb_image.h"

//writing image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "C:\Users\aneru\OneDrive\Desktop\AMRITA\PROBLEM SOLVING AND C PROGRAMMING\stb-master/stb_image_write.h"
int main(void) {
  int x,y,n;
  int width1, height1, channels1;
  int width2, height2, channels2;

  unsigned char *img1 = stbi_load("val1.png", &width1, &height1, &channels1, 0);
  unsigned char *img2 = stbi_load("ff1.png", &width2, &height2, &channels2, 0);

  int width = width1 + width2;
  int height = height1 > height2 ? height1 : height2;
  int channels = channels1 > channels2 ? channels1 : channels2;
  unsigned char *output_image = (unsigned char *)malloc(width * height * channels);

  // Copy first image to output image
  for (y = 0; y < height1; y++) {
    for (x = 0; x < width1; x++) {
      for (n = 0; n < channels1; n++) {
        output_image[y * width * channels + x * channels + n] =
            img1[y * width1 * channels1 + x * channels1 + n];
      }
    }
  }

  // Copy second image to output image
  for (y = 0; y < height2; y++) {
    for (x = 0; x < width2; x++) {
      for (n = 0; n < channels2; n++) {
        output_image[y * width * channels + (x + width1) * channels + n] =
            img2[y * width2 * channels2 + x * channels2 + n];
      }
    }
  }

  stbi_write_png("output.png", width, height, channels, output_image, width * channels);

  stbi_image_free(img1);
  stbi_image_free(img2);
  free(output_image);

  return 0;
}
