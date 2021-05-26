#include <stdio.h>

int main(void)
{
    int num, den, num2, den2, result_num, result_denom;

    printf("Enter the first fraction: ");
    scanf("%d /%d", &num, &den);
    printf("Enter the second fraction: ");
    scanf("%d /%d", &num2, &den2);
    result_num = num*den2 + num2*den;
    result_denom = den*den2;
    printf("The sum is %d / %d\n", result_num, result_denom);
    return 0;
    
}