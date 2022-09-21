#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
int main(){
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("forest.jpeg", &width, &height, &bpp, 3);

    printf("Width: %d, Height: %d, BPP: %d, Array Size: %d\n", width, height, bpp, width*height*3);

    int red_count = 1;
    for(int i = 0; i < width*height*3; i++){
        // printf("%d-%d|", i, rgb_image[i]);
        if(red_count == 3){
            red_count = 0;
            rgb_image[i] *= 0.55;
        }
        red_count++;
    }

    stbi_write_png("forest_written.png", width, height, 3, rgb_image, width*3);

    stbi_image_free(rgb_image);

    printf("Hello\n");
    return 0;
}