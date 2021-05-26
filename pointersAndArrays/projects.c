#include <stdio.h>

#define MAXLENGTH 100

int main(void)
{
    int i;
    char msg[MAXLENGTH], ch;

    printf("Enter a message: ");
    for (i = 0;i < MAXLENGTH; i++) {
        ch = getchar();
        if (ch == '\n')
            break; 
        msg[i] = ch;
    }

    printf("Reverse:");
    for (; i >= 0; i--) {
        printf("%c", msg[i]);
    }
    putchar('\n');

    return 0;
}