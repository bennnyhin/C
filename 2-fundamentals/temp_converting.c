//May 5, 2021

#include <stdio.h>
#define SCALE_FACTOR (5.0f / 9.0f)n

int main(void)
{
    float user_input, converted_temp;
    printf("Enter Fahrenheight temperature: ");
    scanf("%f", &user_input);
    converted_temp = (user_input - 32.0f) * (SCALE_FACTOR);
    printf("Celcius: %.2f", converted_temp);


}
