#include <stdio.h>
#include <stdlib.h>
#include "sh_image.h"

int main(int argc, char *argv[])
{
        initHashColors();
        image_t img;
        char* file;
        if (argc > 1)
                file = argv[1];
        else {
                perror("No args");
                return 1;
        }
        imgLoadFromFile(&img, file);
        printf("Loaded %s: %ux%u. Console width: %u\n", file, img.width, img.height, terminalGetColumns());
        uint32_t w = 0;
        for (uint32_t i = 0; i < img.width*img.height; i++) {
                if (img.pixels[i].a == 0) {
                        printf("\e[0m  ");
                } else {
                        uint32_t col;
                        if (img.pixels[i].r == img.pixels[i].g && img.pixels[i].g == img.pixels[i].b)
                                col = (uint32_t)(232.f + img.pixels[i].r*(23.f/255.f));
                        else
                                col = (16 + ((img.pixels[i].r*5)/255)*36
                                                + ((img.pixels[i].g*5)/255)*6
                                                + (img.pixels[i].b*5)/255);

                        /*printf("(%u,%u,%u)", img.pixels[i].r, img.pixels[i].g, img.pixels[i].b);*/
                        printf("\e[48;5;%um  ", col);
                }
                w++;
                if (w >= img.width) {
                        w = 0;
                        printf("\e[0m\n");
                }
        }
        imgFree(&img);
        freeHashColors();
        return 0;
}
