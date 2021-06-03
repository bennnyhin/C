#include <stdio.h>
#include <string.h>

union test {
    int i;
    double j;
} testing, testing2;

struct test1 {
    double price;
    union {
        struct {
            char name[50];
            char color[50];
        } bear;
        struct {
            char team[50];
        } hat;
    } item;
};

int main(void)
{
    struct part{
        int number; 
        char name[50];
        int on_hand;
    };

    struct part part1 = {.number = 10, .name = "printer cable", .on_hand = 5};
    printf("%d\n", part1.on_hand);

    typedef struct {
        char name[50];
        int reviews;
        long watches;
    } movies;

    movies mulan = {.name = "mulan", .reviews = 4, .watches = 50000};
    printf("%ld\n", mulan.watches);

    testing.i = 32;
    testing2.j = 23.0;

    struct test1 abc;
    strcpy(abc.item.bear.name, "bob");
    printf("%s", abc.item.bear.name);

    typedef enum {HEART = 1, CLUB = 2, DIAMOND, SPADE} card;
    card blah = HEART;
    printf("%d", blah);

    enum foo {YES, NO};
    enum foo multiple_choice;
    
}