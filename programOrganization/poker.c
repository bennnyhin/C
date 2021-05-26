#include <stdio.h>

#define MAXCARDS 5

char cards[MAXCARDS][2];

void read_cards(void); // reads cards into two dimensional array
void analyze_hand(void); // determines whether the ahnd contains a straight, a flush, four of a kind, and or three of a kind
void print_result(void); //uses the external variable to notify user of results

int main(void)
{
    read_cards();
    for (int i = 0; i < MAXCARDS; i++)
        printf("%c%c", cards[i][0], cards[i][1]);
}

/*
void read_cards(void)
{
    char rank, suit;
    for (int i = 0; i < MAXCARDS; i++) { //indexes to get new cards
        repeat:
        printf("Enter a card: ");
        if (getchar() == '\n')
            scanf("%c %c", &rank, &suit);
        else scanf("%c %c", &rank, &suit);
        for (int j = 0; j < MAXCARDS; j++) { //indexes through old cards to see if duplicate
            if (rank == cards[j][0] && suit == cards[j][1]) {
                printf("duplicate\n");
                goto repeat;
            }
        }
        cards[i][0] = rank; //assigns card to array
        cards[i][1] = suit;
    }
    return;
}
*/

void read_cards(void)
{

}
