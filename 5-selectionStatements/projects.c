#include <stdio.h>
#include <stdbool.h>

void digits(void);
void beaufortScale(void);
int gradeConvert(void);

int main(void)
{
    // digits();
    // beaufortScale();
    gradeConvert();
}

void digits(void)
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number / 100 >= 1)
        printf("The number %d has 3 digits\n", number);
    else if (number / 10 >= 1)
        printf("The number %d has 2 digits\n", number);
    else   
        printf("The number %d has 1 digit\n", number);
}

void beaufortScale(void)
{
    float windSpeed;
    printf("Wind speed (in knots): ");
    scanf("%f", &windSpeed);

    if (windSpeed < 1.00f)
        printf("Calm\n");
    else if (windSpeed < 3.00f)
        printf("Light air\n");
    else if (windSpeed < 27.00f)
        printf("Breeze\n");
    else
        printf("Storm\n");
}

int gradeConvert(void)
{
    int grade, firstDigit, secondDigit;
    printf("Enter a numerical grade: ");
    scanf("%d", &grade);
    secondDigit = grade % 10;
    firstDigit = grade / 10;

    if (grade == 100)
        printf("letter grade: A");
    else
        switch (firstDigit){
            case 9: printf("Letter grade: A\n"); break;
            case 8: printf("letter grade B\n"); break;
            case 7: printf("letter grade: C\n"); break;
            case 6: printf("letter grade: D\n"); break;
            case 5: printf("letter grade: F\n"); break;
            default: printf("letter grade: F\n");
    }



}



