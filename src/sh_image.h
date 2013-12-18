#ifndef __SH_IMAGE_H__
#define __SH_IMAGE_H__
/*******************************************************************************
 *  sh_image                                                                   *
 *  Wed Dec 18 CET 2013                                                        *
 *  Copyright Eduardo San Martin Morote                                        *
 *  eduardo.san-martin-morote@ensimag.fr                                       *
 *  http://posva.net                                                           *
 ******************************************************************************/

#include <stdint.h>
#include "sh_color.h"

typedef struct {
        color_t *pixels; // 1 dim pixels
        uint32_t width, height;
} image_t;

void img_load_from_file(image_t *img, const char* file);
void img_free(image_t *img);
void img_resize(image_t *img, float wsc, float hsc);


#endif
