#ifndef LINE_H
#define LINE_H

void clear_line(void); //clears the current line

void add_word(char *word); //adds word to the end of the current line. If this is not the first word on the line, puts one space before word

int space_remaining(void); //returns the number of characters remaining in the current line

void write_line(void); //writes the current line with justification

void flush_line(void); //writes the current line without justification

#endif