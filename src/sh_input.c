#include "sh_input.h"

#include <unistd.h>
#include <termios.h>
#include <string.h>

extern void perror(const char *s);
static struct termios old;

void init_input()
{
        memset(&old, 0, sizeof(struct termios));
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
}

void close_input()
{
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
}

char getch() {
        char buf = 0;
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        return (buf);
}
