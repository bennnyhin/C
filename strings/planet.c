#include <stdio.h>
#include <string.h>

#define NUMPLANETS 9

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    int i, j;
    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUMPLANETS; j++)
            if (strcmp(planets[j], argv[i]) == 0)
                printf("%s is planet %d\n", argv[i], j+1);
                break;
        if (j == NUMPLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0; 
    
}

