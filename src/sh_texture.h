#ifndef __SH_TEXTURE_H__
#define __SH_TEXTURE_H__
/*******************************************************************************
 *  sh_texture                                                                 *
 *  Sat Dec 21 CET 2013                                                        *
 *  Copyright Eduardo San Martin Morote                                        *
 *  eduardo.san-martin-morote@ensimag.fr                                       *
 *  http://posva.net                                                           *
 ******************************************************************************/

#include "sh_image.h"

typedef struct {
        image_t *original; /**< This is the original picture without resize */
        image_t *img; /**< Actual texture adapted to the current terminal */
} texture_t;

#endif
