//May 23, 2021

#include <stdio.h>

#define MAX 80

int main(void)
{
    char string[MAX + 1] = "hello world";

    printf("%c", string[0]);
    scanf("%s", string);
    puts(string);

    printf("%s", string);

    int a[5] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    printf("%d", size);

    char *planets[] = {"mercury", "venus", "earth", "mars", "Jupiter", "Saturn", "Uranus"};
    for (int i = 0; i < 7; i++)
        if (planets[i][0] == 'm')
            printf("%s begins with M\n", planets[i]); //planets[i] is the value
    printf("%s", *(planets+1)); //planets is the address so needs indirectional operator

    
}