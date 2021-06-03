#include "readline.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int read_line(char *string, int len)
{
    char ch, *p = string;
    int count = 0;
    while (isspace(ch = getchar()))
        ;
    while(ch != '\n' && ch != EOF) {
        if (count > len)
            return count;
        *p++ = ch;
        ch = getchar();
    }
    *p = '\0';
    return count;
}