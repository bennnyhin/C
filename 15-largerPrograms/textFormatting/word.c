#include <stdio.h>
#include "word.h"

int read_char(void)
{
    int ch = getchar();
    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len)
{
    char ch, *p = word;
    int wordLen = 0;
    while ((ch = read_char()) == ' ') //removes spaces before word
        ;
    while (ch != ' ' && ch != EOF) {
        if (wordLen < len)
            *p++ = ch;
        ch = read_char();
        wordLen++;
    }
    *p = '\0';
    return;
}