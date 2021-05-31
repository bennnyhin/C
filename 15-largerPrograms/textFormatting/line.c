#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60
char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) //clears the current line
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(char *word) //adds word to the end of the current line. If this is not the first word on the line, puts one space before word
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}


int space_remaining(void) //returns the number of characters remaining in the current line
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void) //writes the current line with justification
{
    int extra_spaces, spaces_to_insert, i , j;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void) //writes the current line without justification
{
    if (line_len > 0)
        puts(line);
}