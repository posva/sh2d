#include <stdio.h>
#include <stdlib.h>
#include "sh_input.h"

int main(int argc, char *argv[])
{
    init_input();
    char c;
    while ((c = getchar()) != '\n'){
        printf("char read(%d): %c.\n", c, c);
    }
    close_input();
    return 0;
}

