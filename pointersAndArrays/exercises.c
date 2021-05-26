#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define ROW 5
#define COL 5
#define LEN 5

int sum_array(int a[], int n);
bool search(int a[], int n, int key);
double inner_product(double *a, double *b, int n);
bool search2(int temperatures[7][24], int key);
void temperatures(int temperatures[7][24]);
int sum_two_dimensional_array(int a[][LEN], int n);


int main(void)
{
    // int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    // int *p = &a[1], *q = &a[5];
    // printf("%d\n", *(p+3));

    // printf("%d\n", p < q);
    // printf("%d\n", *p < *q);

    // int *middle, *low, *high;

    
    // middle = low + (high - low) / 2;

    // int sum = sum_array((int []){1, 2, 3, 5}, 4);
    // printf("%d", sum);

    // if (search((int []){1, 2, 3, 4, 5}, 5, 10))
    //     printf("true\n");
    // else printf("false\n");

    // double a1[] = {1, 2, 3}, a2[] = {4, 5, 6};
    // double *a = a1, *b = a2;
    // printf("Sum %.2lf", inner_product(a, b, 3));

    // int temp[7][24] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24},{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}};
    // temperatures(temp);

    int a[][LEN] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    int sum = sum_two_dimensional_array(a, 2);
    printf("%d\n", sum);


}

int sum_array(int a[], int n)
{
    int *p = a, sum = 0;
    while (p < a + n)
        sum += *p++;
    return sum;
}

bool search(int a[], int n, int key)
{
    int *p = a;
    while (p < a + n) {
        if (key == *p++)
            return true;
    }
    return false;
}

void store_zeros(int a[], int n)
{
    int *p = a;
    while (p < a + n)
        *p++ = 0;
}

double inner_product(double *a, double *b, int n)
{
    double sum = 0.0;
    double *p = a, *q = b;
    while (p < a + n) {
        sum += (*p++) * (*q++);
    }
    return sum;

}

int find_largest(int *a, int n)
{
    int *p = a;
    int largest = *a;
    while (p++ < a + n) {
        if (largest < *p)
            largest = *p;
    }
    return largest;

}

void find_two_largest(int *a, int n, int *largest, int *second_largest)
{
    int *p = a;
    *second_largest = *a;
    *largest = *a;
    while (p++ < a + n) {
        if (*largest < *p)
            *largest = *p;
    }

    p = a;
    while (p++ < a+ n) {
        if (*second_largest > *p && *second_largest < *largest)
            second_largest = p;
    }
        
}

void matrix(void)
{
    double ident[10][10];
    double *p;
    int numZeros = 0;
    for (p = &ident[0][0]; p < &ident[9][9]; p++)
        if (numZeros == 10)
            *p = 1.0;
        else {
            *p = 0;
            numZeros++;
        }
        
}

bool search2(int temperatures[7][24], int key)
{
    int *p;
    for (p = &temperatures[0][0]; p < &temperatures[7-1][24-1]; p++) {
        if (key == *p)
            return true;
    }
    return false;

}

void temperatures(int temperatures[7][24])
{
    int *p;
    for (p = &temperatures[0][0]; p < &temperatures[7-1][24-1]; p++) {
        printf("%d ", *p);
    }
}

int sum_two_dimensional_array(int a[][LEN], int n)
{
    int *p, sum = 0;
    for (p = a[0]; p < a[n]; p++)
        sum += *p;
    return sum;
}