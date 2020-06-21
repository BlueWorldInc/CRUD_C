#include "fnc.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putstr(char *str)
{
    if (str != NULL) {
        write(1, str, my_strlen(str));
    }
}

