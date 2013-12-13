#include <stdio.h>
#include "image.h"

int main(void)
{
        printf("\e[31mLol\e[0m\n");
        image_t img;
        imgLoadFromFile(&img, "data/yoshi.png");
        uint32_t w = 0;
        for (uint32_t i = 0; i < img.width*img.height; i++) {
                if (img.pixels[i].a == 0) {
                        printf("\e[0m  ");
                } else {
                        uint32_t col;
                        if (img.pixels[i].r == img.pixels[i].g && img.pixels[i].g == img.pixels[i].b)
                                col = (uint32_t)(232.f + img.pixels[i].r*(23.f/255.f));
                        else
                                col = (uint32_t)(16.f + img.pixels[i].r*(5.f/255.f)*36.f
                                                + img.pixels[i].g*(5.f/255.f)*6.f
                                                + img.pixels[i].b*(5.f/255.f));

                        printf("\e[48;5;%um  ", col);
                }
                w++;
                if (w >= img.width) {
                        w = 0;
                        printf("\e[0m  \n");
                }
        }
        imgFree(&img);
        return 0;
}

