#include <stdio.h>
#include <stdbool.h>

int sum_two_dimensional_array(int n, int m, int[n][m]);
void test(int a[], int size);

bool isPrime(int num)
{
    int divisor;

    if (num <= 1)
        return false;
    for (divisor = 2; divisor * divisor <= num; divisor++) {
        if (num % divisor == 0)
            return true;
    }

    return false;
}

int main(void)
{
    // int num;
    // printf("Enter a number: ");
    // scanf("%d", &num);
    // if (isPrime(num))
    //     printf("Not prime\n");
    // else printf("Prime\n");


    // int ar[2][2] = {{1, 2}, {3, 4}};
    // printf("Sum is %d\n", sum_two_dimensional_array(2, 2, ar));

    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(int);
    test(a, size);

}

int sum_two_dimensional_array(int n, int m, int array[n][m])
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            sum += array[i][j];
    }
    return sum;
}

//compound literal function((int []){1,2,3}, 3)

void test(int a[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d", a[i]);
    }
}



