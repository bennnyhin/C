//May 10, 2021

#include <stdio.h>

int main(void)
{
    /*
    1)
    printf("        *\n");
    printf("       *\n");
    printf("      *\n");
    printf("*    *\n");
    printf(" *  *\n");
    printf("  *\n");
    */

   float price;
   printf("Enter an amount: ");
   scanf("%f", &price);
   float newPrice = price*1.05;
   printf("With tax added: %.2f\n", newPrice);
   


}