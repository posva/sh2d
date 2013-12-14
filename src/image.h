#include <stdint.h>
#include "color.h"

#define RGB2X(r,g,b) (((r) << 16) | ((g) << 8) | (b))
#define X2R(x) (((x) & 0xff0000) >> 16)
#define X2G(x) (((x) & 0xff00) >> 8)
#define X2B(x) ((x) & 0xff)

typedef struct {
        color_t *pixels; // 1 dim pixels
        uint32_t width, height;
} image_t;

void imgLoadFromFile(image_t *img, const char* file);
void imgFree(image_t *img);

void initHashColors();
void freeHashColors();

