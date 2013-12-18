#ifndef __SH_UTILS_H__
#define __SH_UTILS_H__
/*******************************************************************************
 *  sh_utils                                                                   *
 *  Wed Dec 18 CET 2013                                                        *
 *  Copyright Eduardo San Martin Morote                                        *
 *  eduardo.san-martin-morote@ensimag.fr                                       *
 *  http://posva.net                                                           *
 ******************************************************************************/

#include <stdint.h>

#define SQUARED(x) ((x)*(x))
#define RGB2X(r,g,b) (((r) << 16) | ((g) << 8) | (b))
#define X2R(x) (((x) & 0xff0000) >> 16)
#define X2G(x) (((x) & 0xff00) >> 8)
#define X2B(x) ((x) & 0xff)

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS
#endif

uint32_t terminal_columns();

#endif
