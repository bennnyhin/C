//May 17, 2021
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define STARTINGAMOUNT 100
#define NUMRATES 5

void reverse(void);
void extra(void);
void repeatedDigits();
void interest(void);
void interestSolution(void);
void reverse2(void);
void exercises(void);

int main(void)
{
    // reverse();
    // extra();
    // repeatedDigits();
    // interest();
    // interestSolution();
    // reverse2();
    exercises();
}

void reverse(void)
{   
    int num[N], rev[N], i, k;
    printf("Enter 10 number: ");
    
    for (i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    printf("In reverse order: ");
    for (k = N - 1; k >= 0; k--) {
        printf("%d ", num[k]);
    }
}

void extra(void)
{
    int a[10] = {[2] = 5, [9] = 6}; //disignated initiatlizers
    //the length of an array is determined by the largest designated initilizer
    int b[] = {[5] = 10, [23] = 13}; //in this example, the array will have length 24 because of the [23]
}

void repeatedDigits(void)
{
    bool digitsSeen[9] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digitsSeen[digit])
            break;
        digitsSeen[digit] = true;
        n /= 10;
    }

    if (n > 0)
        printf("Repeated digit\n");
    else 
        printf("No repeated digit\n");
        

}

void interest(void)
{


    float prevYear[5], interestRate;
    int years, interest;
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    printf("Years");

    for (int j = 0; j < NUMRATES; j++) {
        printf("%6.0f%%", interestRate);
        interest++;
    }
    printf("\n");

    for (int i = 1; i <= years; i++) { //loop for the years
        printf("%-5d", i);
        for (int k = 0; k < NUMRATES; k++) {
            prevYear[k] += (interestRate + k) / 100.0 * prevYear[k];
            printf("%7.2f", prevYear[k]);
        }
        printf("\n");
    }
}

void interestSolution(void)
{
    int i, lowRate, numYears, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &lowRate);
    printf("Enter number of years: ");
    scanf("%d", &numYears);

    printf("\n Years");
    for (i = 0; i < NUMRATES; i++) {
        printf("%6d%%", lowRate + i);
        value[i] = STARTINGAMOUNT;
    }
    
    printf("\n");

    for (year = 1; year <= numYears; year++){
        printf("%3d    ", year);
        for (i = 0; i < NUMRATES; i++) {
            value [i] += (lowRate + i) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
    printf("\n");
    }
}

void reverse2(void)
{
    int n, i;
    printf("How many numbers do you want to reverse?");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (i = n - 1; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }
}

void exercises(void)
{
    //exercise 4
    bool weekend[7] = {[0] = true, [6] = true};
    for (int i = 0; i < 7; i++)
        printf("%d", weekend[i]);
    printf("\n\n");

    //Fibonacci numbers - exercise 5
    int fib_numbers[40] = {[0] = 0, [1] = 1}, num1 = 0, num2 = 1;
    for (int k = 2; k < 40; k++)
        fib_numbers[k] = fib_numbers[k-1] + fib_numbers[k-2];
    for (int i = 0; i < 40; i++)
        printf("%d ", fib_numbers[i]);
    printf("\n\n");

    //exercise 8 and 9
    #define DAYSINMONTH 30
    int temperature_readings[DAYSINMONTH][24], day, hour;
    float sum = 0;
    for (day = 0; day < DAYSINMONTH; day++) {
        for (hour = 0; hour < 24; hour++)
            sum += temperature_readings[day][hour];
    }

    //exercise 10
    // char chess_board[8][8] = {
    //     {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    //     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    //     {' ', ''}....
    //}

    //exercise 11
    int row, column;
    char checker_board[8][8];
    for (row = 0; row < 8; row++) {
        for (column = 0; column < 8; column++)
            checker_board[row][column] = ((row + column) % 2) ? 'B' : 'R';
    }

    for (row = 0; row < 8; row++) {
        for (column = 0; column < 8; column++)
            printf("%c ", checker_board[row][column]);
        printf("\n");
    }
}