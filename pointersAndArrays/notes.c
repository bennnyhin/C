#include <stdio.h>

#define N 10

//prototypes
void reverse(void);
void zeros(void);
void multidimensional(void);
void multidimensional2(void);

int main(void)
{
    /*
    int a[5] = {1, 2, 3, 4, 5}, *p, sum = 0;
    for (p = a; p < a+5; p++)
        sum += *p;
    printf("Sum: %d\n", sum);

    for (p = &a[0]; p < &a[5]; p++)
        printf("testing");
    */
//    reverse();
    //zeros();    
    multidimensional();
    multidimensional2();
}

void reverse(void)
{
    int a[N], *p;
    printf("Enter a series of 10 numbers to reverse: ");
    for (p = a; p < a + N; p++)
        scanf("%d", p);
    
    for (p = a + N - 1; p >= a; p--)
        printf("%d ", *p);
}

void zeros(void)
{
    int a[10][10], *p;
    for (p = &a[0][0]; p < &a[10][10]; p++)
        *p = 0;
}

void multidimensional(void) //makes one row all zeros
{
    int a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, *p, i = 1;

    for (p = a[i]; p < a[i] + 3; p++)
        *p = 0;
    
    for (p = a[0]; p < a[0] + 9; p++)
        printf("%d ", *p);
    printf("\n");
}

void multidimensional2(void)
{
    int b[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}}, (*p)[3], i = 1, *q;

    for (p = b; p < b + 3; p++)
        (*p)[i] = 0;
    
    for (q = b[0]; q < b[0] + 9; q++)
        printf("%d ", *q);
    printf("\n");
}