#include "image.h"
#include "stb_image.h"
#include "khash.h"
#include <stdlib.h>

#define RGB2X(r,g,b) (((r) << 16) & ((g) << 8) & (b))
#define X2R(x) (((x) & 0xff0000) >> 16)
#define X2G(x) (((x) & 0xff00) >> 8)
#define X2B(x) ((x) & 0xff)

void convertColor(color_t *col);

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
                        convertColor(&(img->pixels[i]));
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

// convert color to the terminal 256 colors
// if it have been already converted, fond it in the map
// First convert to XYZ, then to *L*a*b
// finnally find the closest color in the map and
// store it
KHASH_MAP_INIT_INT(uint32_t, uint32_t)
khash_t(uint32_t) *hash_colors;
void initHashColors()
{
        hash_colors = kh_init(uint32_t);
        int ret;
        khiter_t k;
        for (int i = 0; i < 247; i++) {
                k = kh_put(uint32_t, hash_colors, color_map[i], &ret);
                /*if (!ret) kh_del(uint32_t, hash_colors, k);*/
                kh_value(hash_colors, k) = color_map[i];
        }
}

void freeHashColors()
{
        kh_destroy(uint32_t, hash_colors);
}

void convertColor(color_t *col) {
        if (col->a == 0)
                return; // we don't care about this color
        int32_t r = col->r, g = col->g, b = col->b;
        /*double x,y,z;*/
        /*x = 0.412453*r + 0.357580*g + 0.180423*b;*/
        /*y = 0.212671*r + 0.715160*g + 0.072169*b;*/
        /*z = 0.019334*r + 0.119193*g + 0.950227*b;*/
        double y,u,v;
        y = 0.299*r + 0.587*g + 0.114*b;
        u = -0.14713*r + -0.28886*g + 0.436*b;
        v = 0.615*r + -0.51499*g + -0.10001*b;

        khiter_t k;
        k = kh_get(uint32_t, hash_colors, RGB2X(col->r, col->g, col->b));
        if (k == kh_end(hash_colors)) { // it doesn't exist
        } else {
                uint32_t xcol = kh_value(hash_colors, k);
                col->r = X2R(xcol);
                col->g = X2G(xcol);
                col->b = X2B(xcol);
        }
}

