#include <stdio.h>
#include <ctype.h>
#include <math.h>

void square(void);
void scrabble(void);
void size(void);
void vowels(void);
void squareRoot(void);

int main(void)
{
    // scrabble();
    // square();
    // size();
    // vowels();
    squareRoot();
}

void square(void)
{
    int i, n;
    char ch;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    ch = getchar();
    /* dispose of new-line character following number of entries */
    /* could simply be getchar(); */

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            ch = getchar();   /* or simply getchar(); */
        }
    }
}

void scrabble(void)
{
    char ch;
    int sum = 0;
    printf("Enter a word: ");
    while ((ch = getchar()) != '\n') {
        switch (toupper(ch)) {
            case 'Q': case 'Z': sum += 10; break;
            case 'J': case 'X': sum += 8; break;
            case 'K': sum += 5; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y': sum += 4; break;
            case 'D': case 'G': sum += 2;
            case 'B': case 'C': case 'M': case 'P': sum += 3;
            default: sum++; break;
        }
    }
    printf("Scrabble value: %d\n", sum);
}

void size(void)
{
    printf("%d\n", (int) sizeof(char)); //casting
    printf("%d\n", (int) sizeof(int));
    printf("%d\n", (int) sizeof(double));
}

void vowels(void)
{
    char ch;
    int numVowels = 0;
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n'){
        switch(toupper(ch)){
            case 'A': case 'E': case 'I': case 'O': case 'U': numVowels++; break;
        }
    }
    printf("Your sentence contains %d vowels\n", numVowels);
}

void squareRoot(void) //using Newton's method with an initial guess of 1
{
    int x;
    double y1 = 1., xy1, yxy1, y2, xy2, yxy2;
    printf("Enter a positive number: ");
    scanf("%d", &x);

    xy1 = x/y1;
    yxy1 = (y1 + xy1) / 2;
    y2 = yxy1;
    xy2 = x/y2;
    yxy2 = (y2 + xy2) / 2;

    while (fabs(y2-y1) > (0.00001 * y2)){
        y1 = y2;
        xy1 = xy2;
        yxy1 = yxy2;

        y2 = yxy1;
        xy2 = x/y2;
        yxy2 = (y2 + xy2) / 2;

    }

    printf("Square root: %g\n", yxy2);

}