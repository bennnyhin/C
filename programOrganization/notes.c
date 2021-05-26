#include <stdio.h>
#include <stdlib.h>

void guessNumber(int secretNumber);

int main(void)
{
    int playAgain = 1;
    char yesNo;

    while (playAgain == 1) {
        guessNumber(rand() % (5 + 1 - 1) + 1);
        printf("Play again? (Y/N) \n");
        scanf("%c", &yesNo);

        if (yesNo == 'N')
            playAgain = 0; 
    }
    return 0;
}

//guessing a number
void guessNumber(int secretNumber)
{
    int guess, numTries = 0;
    printf("Guess the secret number betwen 1 and 100\n");
    do {
        printf("Enter guess: ");
        scanf("%d", &guess);
        numTries++;
    } while (secretNumber != guess);

    printf("You got it in %d tries!\n", numTries);
    return;
}

void initializeSrand(void)
{
    
}
