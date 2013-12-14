#include <stdint.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS
#endif

typedef struct {
        uint8_t r, g, b, a;
} color_t;

uint32_t color_map[247];

uint32_t terminalGetColumns();

