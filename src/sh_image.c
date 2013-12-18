#include "sh_image.h"
#include "stb_image.h"
#include <stdlib.h>


void imgLoadFromFile(image_t *img, const char* file)
{
        int channels, w, h;
        unsigned char* ptr = stbi_load(file, &w, &h, &channels, STBI_rgb_alpha);

        if (ptr && w && h) {
                img->width = w;
                img->height = h;

                if (!(img->pixels = malloc(sizeof(color_t)*w*h))) {
                        perror("malloc error\n");
                        exit(1);
                }

                // fill the array
                for (int i = 0, j = 0; j < w*h; i += 4, j++) {
                        img->pixels[j].r = ptr[i];
                        img->pixels[j].g = ptr[i+1];
                        img->pixels[j].b = ptr[i+2];
                        img->pixels[j].a = ptr[i+3];
                        convert_color(&(img->pixels[j]));
                }

                stbi_image_free(ptr);
        } else {
                perror("stb_image error");
        }
}

void imgFree(image_t *img)
{
        free(img->pixels);
}



