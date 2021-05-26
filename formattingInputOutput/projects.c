#include <stdio.h>

int book_number(void);
void addfrac(void);

int main(void)
{
    // book_number();
    addfrac();
}

int book_number(void)
{
    int prefix, identifier, publisher, itemNum, checkDigit;
    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d", &prefix, &identifier, &publisher, &itemNum, &checkDigit);
    printf("GSI prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", prefix, identifier, publisher, itemNum, checkDigit);
    return 0;
}

void addfrac(void)
{
    int numOne, denomOne, numTwo, denomTwo, numNew, denomNew;
    printf("Enter two fractions seperated by a plus sign: ");
    scanf("%d /%d +%d /%d", &numOne, &denomOne, &numTwo, &denomTwo);
    numNew = numOne * denomTwo + numTwo * denomOne;
    denomNew = denomOne * denomTwo;
    printf("The sum is %d/%d\n", numNew, denomNew);
}