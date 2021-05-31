//May 21, 2021
#include <stdio.h>

//prototypes
void max_min (int a[], int n, int *max, int *min);
void avg_sum(double a[], int n, double *avg, double *sum);
void swap(int *p, int *q);
void split_time(long total_sec, int *hr, int *min, int *sec);
int *find_largest(int a[], int n);

int *p, largest;

int main(void)
{
    //pointer intro
    /*
    int *p, i;
    p = &i;
    i = 5;
    *p = 10;
    printf("%d", i);
    printf("%d", *p); //indirection operator
    return 0;
    */

   //big small in notes
   /*
   int N, big, small;
   printf("Enter quantity of numbers you want to enter: ");
   scanf("%d", &N);

   int b[N];
   printf("Enter array of %d numbers: ", N);
   for (int i = 0; i < N; i++) {
       scanf("%d", &b[i]);
   }

   max_min(b, N, &big, &small);
   
   printf("Largest: %d\n", big);
   printf("Smallest: %d\n", small);
   */

    //exercise 3
    /*
    int N = 5;
    double sum, average;
    double b[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    avg_sum(b, N, &average, &sum);
    printf("Sum: %.2lf\n", sum);
    printf("Average: %.2lf\n", average);
  */

    //exercise 4 - swap values
    /*
    int p = 4, q = 5;
    swap(&p, &q);
    printf("P: %d\nQ: %d\n", p, q);
    */

   //exercise 5
   /*
   int hours, min, sec;
   split_time(40000, &hours, &min, &sec);
   printf("Hours: %d \nmin: %d \nseconds: %d\n", hours, min, sec);
   */

  //exercise 8
  /*
    int *q;
    q = find_largest((int []){1, 2, 100, 4, 5}, 5);
    printf("%d\n", *q);
    */
}

void max_min (int a[], int n, int *max, int *min)
{
    *max = *min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > *max)
            *max = a[i];
        else if (a[i] < *min)
            *min = a[i];
    }
}

void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;
    *sum = 0.0;
    for (i =0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}

void swap(int *p, int *q) 
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    *min = (total_sec % 3600) / 60;
    *sec = ((total_sec % 3600) % 60);
}

int *find_largest(int a[], int n)
{
    p = &largest;
    *p = 0;
    for (int i = 0; i < n; i++){
        if (*p < a[i])
            *p = a[i];
    }
    return p;
}