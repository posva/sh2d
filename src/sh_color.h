#ifndef __SH_COLOR_H__
#define __SH_COLOR_H__
/*******************************************************************************
 *  sh_color                                                                   *
 *  Wed Dec 18 CET 2013                                                        *
 *  Copyright Eduardo San Martin Morote                                        *
 *  eduardo.san-martin-morote@ensimag.fr                                       *
 *  http://posva.net                                                           *
 ******************************************************************************/

#include <stdint.h>

typedef struct {
        uint8_t r, g, b, a;
} color_t;

typedef struct {
        float y, u, v;
} color_yuv_t;

// rgb colors
#define N_COLORS 247
uint32_t color_map[N_COLORS];
// yuv equivalents
color_yuv_t yuv_color_map[N_COLORS];


void rgb2yuv(const color_t* rgb, color_yuv_t* yuv);

// squared distance between 2 colors
float col_yuv_distance(const color_yuv_t* a, const color_yuv_t* b);

void convert_color(color_t *col);

void init_hash_colors();
void free_hash_colors();


#endif
