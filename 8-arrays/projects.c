#include <stdio.h>

void repdigit(void);

int main(void)
{
    repdigit();
    return 0;
}

void repdigit(void)
{
    int num, digit;
    int repeated[10] = {0};
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num > 0) {
        digit = num % 10;
        repeated[digit] = repeated[digit] + 1;
        num /= 10;
    }

    printf("Digit:      ");
    for (int i = 0; i < 10; i++) {
        printf("%4d", i);
    }

    printf("\n");

    printf("Occurances: ");
    for (int i = 0; i < 10; i++) {
        printf("%4d", (repeated[i]));
    }
    printf("\n");


}