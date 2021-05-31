//May 12, 2021

#include <stdio.h>

void exercises(void);

int main(void)
{
    exercises();
}


void UPC_check(void)
{
    int a1;
    int first, second, third, fourth;
    printf("enter the first (single) digit: ");
    scanf("%d", &a1);
    printf("enter first group of five digits: ");

}

void exercises(void)
{
    // = 1, 2
    int i = 5;
    int j = 3;
    printf("%d %d\n", i/j, i%j);

    // 1
    i=7; j=8; int k=9;
    printf("%d\n", (i+10) % k / j);

    //1 --> should be 0 because 2/3 has a remainder of 2 
    i=1; j=2; k=3;
    printf("%d\n", (i+5) % (j+2) / k);

    printf("%d\n", -9/4);

    //57 --> should be 63 because *= has lower precedence than +
    i=7; j=8;
    i *= j+1;
    printf("%d %d\n", i, j);

    //3 2 1
    i=j=k=1;
    i += j += k;
    printf("%d %d %d\n", i,j,k);

    //12
    i=6;
    j = i += i;
    printf("%d %d\n", i, j);

    //3
    i=3; j=4; k=5;
    printf("%d\n", i++ - j++ + --k);
    printf("%d %d %d\n", i,j,k);

    // 2 8 --> int is what was declared so i=2 which is then added to 6
    i=7;
    j= 6 + (i = 2.5);
    printf("%d %d\n", i, j);

    //i=6 j=9
    i=2; j=8;
    j = (i=6) + (j=3);
    printf("%d %d\n", i, j);

    //i = 6, j = -7
    i=5;
    j= 3 - 2 * i++;
    printf("%d %d\n", i, j);

    printf("%d\n", 1*2/1);
}