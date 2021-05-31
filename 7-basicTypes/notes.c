#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

void sumSeries(void);
void tests(void);
void messageLength(void);
void testing(void);

typedef int Dollars;
typedef int8_t Int8;
typedef int16_t Int16;

int main(void)
{
    // sumSeries();
    // tests();
    // messageLength();
    testing();
}

void sumSeries(void)
{
    long n, total = 0;
    printf("The program sums a series of integers\nEnter Integers (0 to terminate): ");
    
    scanf("%ld", &n);
    while (n != 0) {
        total += n;
        scanf("%ld", &n);
    }

    printf("The sum is: %ld\n", total);
}

void tests(void)
{
    int i = 0;
    char k;
    for (k = 'a'; k <= 'z'; k++, i++){ //C treats chars as integers so you can go through them
        printf("%d\n", i);
        printf("%c\n", k);
    } 

    scanf(" %c", &k); // putp a space before the %c to force white space to be skipped 
    printf("%c", k);

    do {
        scanf("%c", &k);
        printf("%c", k);
    } while (k != '\n'); //reads the char then stops the loop
}

void messageLength (void)
{
    char ch;
    int count = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n') {
        count ++;
    }

    printf("the message was %d characer(s) long\n", count);
}

void testing(void)
{
    // putchar('c');
    // char ch = getchar();
    // putchar(ch);

    Dollars initial = 0;
    Dollars final = 100;
    printf("initial money: %d, final money: %d\n", initial, final);

    printf("Size of int: %lu\n", (unsigned long) sizeof(int));

    printf("%f\n", 010E2); //octal can only go from 0-7

    printf("Hello\x0AWorld"); //escape sequence
    printf("Hello\12world");

    char c = '\1';
    short s = 2;
    int i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;
    
    printf("%d", c * i); //char is converter to integer (=1)
    printf("%f", f/c); //char is converted to flooat
}