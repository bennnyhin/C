//May 10 2021

#include <stdio.h>
#define INCHES_PER_POUND 166

int main(void)
{
    int height, length, width, volume, weight;
    
    height = 8;
    length = 12;
    width = 10;
    volume = height * length * width;
    weight = (volume + 165) / INCHES_PER_POUND;
    printf("dimensions: %dx%dx%d\n", length, width, height);
    printf("dimensional weight (pounds): %d\n", weight);
    return 0;

}