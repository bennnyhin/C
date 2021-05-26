//May 13, 2021

#include <stdio.h>
#include <stdbool.h> //neccessary to provide a macro for _Bool
#define MAXLINES 10

void logicalExpressions(void);
void ifStatement(void);
void broker(void);
void conditionalExpression(void);
void switchStatement(void);
void date(void);
void exercises(void);
void projects(void);

int main(void)
{
    // logicalExpressions();
    // ifStatement();
    //broker();
    // conditionalExpression();
    // switchStatement();
    // date();
    // exercises();
    projects();
}

void logicalExpressions(void)
{
    int i=1, j=3;
    printf("%d\n", i>j); //1 is printed if the statement is true and 0 if it is false

}

void ifStatement(void)
{
    if (12<MAXLINES)
        printf("Correct\n"); //if 8 < maxlines, 1 is returned
    else    
        printf("false\n");
}

void broker(void)
{
    float value, commission;
    printf("Enter value of trade: ");
    scanf("%f", &value);
    
    if (value < 2500.00f)
        commission = 30.0f + 0.017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + 0.0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + 0.0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + 0.0011f * value;
    else    
        commission = 255.00f + 0.0009f * value;
    
    //minimum commission check
    if (commission < 39.00f)
        commission = 39.00f;

    printf("Comission: $%.2f\n", commission);

}

void conditionalExpression(void)
{
    int i =1, k=2, l;
    l = (i > 2 ? 10 : 20);
    printf("%d\n", l);

}

void switchStatement(void)
{
    int grade;
    printf("Enter a number: ");
    scanf("%d", &grade);
    switch (grade) {
        case 1: printf("you got a 10");
        case 2: printf("you got a 20");
        case 3: printf("You got a 30");
        case 4: printf("you got a 40");
        default: printf("invalid number");
    }
}

void date(void)
{
    int month, day, year;
    printf("Enter date (mm/dd/yy): ");
    scanf("%d / %d / %d", &month, &day, &year);
    printf("Dated this %d", day);

    switch(day){
        case 1: case 21: case 31:
            printf("st"); break;
        case 2: case 22:
            printf("nd"); break;
        case 3: case 23:
            printf("rd"); break;
        default:
            printf("th"); break;
    }

    printf(" day of ");

    switch(month) {
        case 1: printf("January"); break;
        case 2: printf("February"); break;
        case 3: printf("March"); break;
        case 4: printf("April"); break;
        case 5: printf("May"); break;
        case 6: printf("June"); break;
        case 7: printf("July"); break;
        case 8: printf("August"); break;
        case 9: printf("September"); break;
        case 10: printf("October"); break;
        case 11: printf("November"); break;
        case 12: printf("Decmeber"); break;
    }

    printf(", 20%.2d\n", year);
}

void exercises(void)
{
    int i = 2;
    int j = 3;
    int k;

    // k = 2 * 0 = 0 --> is actually 1 because the * is before the ==
    k = i * j == 6;
    printf("%d\n", k);

    // 1 because 0 < 10
    printf("%d\n", 1 > 5 < 10);

    // 0 because 3+3 is not less than 5
    printf("%d\n", 3 % 4 + 3 < 5);

    printf("%d\n", !5);

    printf("%d\n", 3 < 2 || 5); //if either of the values are non-zero then the output will be 1

    i = 3 ; j = 4 ; k = 5;
    printf( "%d\n", i < j || ++j < k); //becaues i < j is true, the second part isn't even looked at so j doesn't change
    printf("%d %d %d\n", i, j, k);

    // i = 2, j = 1, k = 1
    i = 1; j = 1; k = 1;
    printf("%d\n", ++i || ++j && ++k);
    printf("%d %d %d\n", i, j, k);

    printf("%d\n", (i < j) - (i > j)); //if i and j are the same then = 0, if i > j = -1 if i < j = 1;

    i=-17;
    printf("%d\n", i>=0 ? i: -i);

    int age;
    bool teenager;

    if (age <=19)
        teenager = true;
    else   
        teenager = false;

    int areaCode;
    printf("Area code: ");
    scanf("%d", &areaCode);
    switch (areaCode){
        case 229: printf("Albany"); break;
        case 404: printf("Atlanta"); break;
        case 470: printf("Macon"); break;
        default: printf("No area code"); break;
    }
}



