#include <stdint.h>
#include "color.h"

typedef struct {
        color_t *pixels; // 1 dim pixels
        uint32_t width, height;
} image_t;

void imgLoadFromFile(image_t *img, const char* file);
void imgFree(image_t *img);
