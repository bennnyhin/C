//May 19, 2021

#include <stdio.h>

int check(int x, int y, int n);
int day_of_year(int month, int day, int year);
int digit(int n, int k);
int largestValue(int n, int a[n]);
double product_of_two_arrays(double a[], double b[], int);
double median(double, double, double);
int gcd(int, int);

int main(void)
{
    //exercise 2:
    /*
    int x, y, n;
    printf("This program takes 3 arguments and determines if the first two fall between 0 and third value");
    printf("\nEnter 3 values: ");
    scanf("%d %d %d", &x, &y, &n);
    if (check(x, y, n))
        printf("The values are less than 0 and n-1\n");
    else printf("The values are not between 0 and n-1\n");
    */

   //exercise 6:
   /*
   int n, k;
   printf("Enter a number and the digit that you want from the right: ");
   scanf("%d %d", &n, &k);
   printf("%d\n", digit(n, k));
   */

  //exercise 10(a)
  /*
    int numInts;
    printf("Enter an an array of integers: ");
    scanf("%d", &numInts);

    int a[numInts];
    printf("Enter %d integers: ", numInts);
    for (int i = 0; i < numInts; i++) 
        scanf("%d", &a[i]);
    printf("Largest int is %d\n", largestValue(numInts, a));
    */

   //exercise 12
   /*
   double a[] = {1.23, 1.5, 67.4};
   double b[] = {98.32, 32.12, 23.1};
   printf("The sum of the product of each element is %.2lf\n", product_of_two_arrays(a, b, 3));
   */

    //exercise 15
    //printf("The median of the three numbers is %.2lf\n", median(23.3, 553.32, 12.3));

    printf("%d\n", gcd(342, 5422));
}

//exercise 2:
int check(int x, int y, int n)
{
    if (0 > x || x > n || 0 > y || y > n)
        return 0;
    return 1;
}

//exercise 4:
int day_of_year(int month, int day, int year)
{
    int sum = 0;
    int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < month; i++)
        sum += numDays[i];

    return sum + day;
}

//exercise 6:
int digit(int n, int k)
{
    int digits;
    for (int i = 0; i < k; i++) {
        digits = n % 10;
        n /= 10;
    }

    return digits;
}

//exercise 10(a)
int largestValue(int n, int a[n])
{
    int largestNum = 0;
    for (int i = 0; i < n; i++) {
        if (largestNum < a[i])
            largestNum = a[i];
    }
    return largestNum;
}

//exercise 11
double product_of_two_arrays(double a[], double b[], int n)
{
    double sum = 0.;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    return sum;
}

//exercise 15
double median(double x, double y, double z)
{
    double feedback;
    if (x <= z)
        if (x >= y) feedback = x;
        else if (z <= y) feedback = z;
        else feedback = y;
    if (z <= y) feedback = y;
    if (x <= z) feedback = x;
    return feedback;
}

//exercise 18
int gcd (int m, int n)
{
    if (n == 0)
        return m;
    gcd(n, m % n);
}