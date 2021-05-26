//May 12, 2021

#include <stdio.h>

void reverseDigits(void);
void upc_check(void);

int main(void)
{
    // reverseDigits();
    upc_check();
}

void reverseDigits(void)
{
    int number, firstDigit, secondDigit, thirdDigit;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);
    thirdDigit = number % 10;
    number /= 10;
    secondDigit = number % 10;
    firstDigit = number / 10;
    printf("The reversal is: %d%d%d\n", thirdDigit, secondDigit, firstDigit);
}

void upc_check(void)
{
    int number, numbers[12];
    printf("Enter the first 12 digits of an EAN: ");
    scanf("%d", &number);
    for (int i=0; i < 11; i++)
    {
        numbers[i] = number % 10;
        number /= 10; 
        printf("%d", numbers[i]);
    }

}