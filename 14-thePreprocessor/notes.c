#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ECHO(x) \
        do {    \
            scanf("%s", x); \
            puts(x); \
        } while(0)

#define test(condition, ...) ((condition)? \
        printf("passed test: %s", #condition): \
        printf(__VA_ARGS__))

int main(void)
{
    printf("this program was compiled on %s", __DATE__);
    char string[30];
    ECHO(string);

    test(true, "passed test: %s", "failed");
}