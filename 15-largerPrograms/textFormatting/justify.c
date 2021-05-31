#include <stdio.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAXLEN 20
#define BUFFERLEN 

int main(void)
{
    char word[MAXLEN + 2];
    int word_len;
    clear_line();
    for (; ; ) {
        read_word(word, MAXLEN+1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > MAXLEN)
            word[MAXLEN] = '*';
        if (space_remaining() < (word_len + 1)) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
    printf("hello");
    printf("test");
}

