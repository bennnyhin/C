#include <stdio.h>
#include <stdbool.h>

void largest_num(void);
void evenSquares(void);
void calendar(void);
void earliestDate(void);

int main(void)
{
    // largest_num();
    // evenSquares();
    // calendar();
    earliestDate();
}

// project 1
void largest_num(void)
{
    float number1 = 0.f, number2;

    while (true){
        printf("Enter a number: ");
        scanf("%f", &number2);

        if (number2 == 0 || number2 < 0)
            break;

        if (number2 > number1)
            number1 = number2;
    }

    printf("The largest number entered was %.2f\n", number1);
}

//project 6
void evenSquares(void)
{
    int number;
    printf("Enter a numer: ");
    scanf("%d", &number);

    for (int i = 2; (i*i) <= number; i += 2){
        printf("%d\n", i * i);
    }
}

//project 8
void calendar(void)
{
    int monthDays, startingDay;
    printf("Enter number of days in month: ");
    scanf("%d", &monthDays);
    printf("Enter starting day of the week: ");
    scanf("%d", &startingDay);

    for (int k = 1; k < startingDay; k++)
        printf("   ");

    for (int day = 1; day <= monthDays; day++) {
        printf("%3d", day);
        if ((day+startingDay-1) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

//project 10
void earliestDate(void)
{
    int month, day, year, earliestMonth = 1000, earliestDay = 1000, earliestYear = 1000;
    for (; ;)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d / %d / %d", &month, &day, &year);

        if (month == 0 && day == 0 && year == 0)
            break;

        if (year < earliestYear){
            earliestMonth = month;
            earliestDay = day;
            earliestYear = year;
        }

        else if (year == earliestYear && month < earliestMonth){
            earliestMonth = month;
            earliestDay = day;
            earliestYear = year;
        }

        else if (year == earliestYear && month == earliestMonth && day < earliestDay){
            earliestMonth = month;
            earliestDay = day;
            earliestYear = year;
        }

    }

    printf("%d/%d/%.2d is the earliest date\n", earliestMonth, earliestDay, earliestYear);
}