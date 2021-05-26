//May 14, 2021

#include <stdio.h>
#include <stdbool.h>

void whileLoop(void);
void square(void);
void doLoop(void);
void numDigits(void);
void forLoop(void);
void continueStatement(void);
int checking(void);
int exercises(void);

int main(void)
{
    // whileLoop();
    // square();
    // doLoop();
    // numDigits();
    // forLoop();
    // continueStatement();
    // checking();
    exercises();
}

void whileLoop(void)
{
    int i = 10;
    while (i > 0){
        printf("%d\n", i--); //the while statement continues until there is a zero-value for  the expression
    }
}

void square(void)
{
    int i;
    int n = 1;
    printf("Enter a number of entires in table: ");
    scanf("%d", &i);

    while (n <= i){
        printf("%10d%10d\n", n, n*n); //use %10d because it is right justified
        n++;
    }
}

void doLoop(void) //do statement just checks the controlling expression after each execution of the loop body
{
    int i = 10;
    do {
        printf("%d\n", i);
        i--;
    } while (i > 0);
}

void numDigits(void)
{
    int number;
    int i = 0;
    printf("Enter a nonnegative integer: ");
    scanf("%d", &number);

    do { // a do loop is better for this program because if number is 0 then the output will say that there are 0 digits
        i++;
        number /= 10;
    } while (number > 0);

    printf("The number has %d digit(s)\n", i);
}

void forLoop(void)
{
    int i = 10; // you need to declare the variable first if you want to access it after the loop
    for (; i >= 0; i--)
        printf("%d\n", i);
    
    printf("i = %d\n", i);
}

void continueStatement(void)
{
    int n = 0;
    int sum = 0;
    int i;
    while (n < 2) {
        scanf("%d", &i);
        if (i == 0)
            continue;
        sum += i;
        n++;

        /* continue jumps to here */
    }

    printf("The sum is %d\n", sum);
}

int checking(void)
{
    int command;
    float balance = 0.0f, credit, debit;

    while (1){
        printf("Enter command: ");
        scanf("%d", &command);
        
        switch(command){
            case 0: balance = 0.0f; break;
            case 1: printf("Enter amount of credit: ");
                    scanf("%f", &credit);
                    balance += credit;
                    break;
            case 2: printf("Enter amount of debit: ");
                    scanf("%f", &debit);
                    balance -= debit;
                    break;
            case 3: printf("Current balance: $ %.2f\n", balance);
                    break;
            case 4: return 0; //causes the function to return to the main function
            default: printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");
                    break;
                }
    }
}

int exercises(void)
{
    int i, j;
    for (i = 5, j = i-1; i > 0, j > 0; --i, j = i-1) // the comma just seperates mutliple conditions
        printf("%d ", i);
    
    i = 1;
    for(; i <=128; ){
        printf("%d ", i);
        i *=2;
    }

    // for (i=10; i >= 1; i /= 2) //creates an infinite print of 1
    //     printf("%d ", i++);

    // i = 10;
    // while (i >=1){
    //     printf("%d ", i++);
    //     i /= 2;
    // }

    for (int k = 0; k<10; k++) {
        if (k % 2 == 0)
            continue;
        printf("Not divisible by 2 --- %d\n", k);
    }

    printf("\n");

    for (int k = 0; k < 10; k++) {
        if (k % 2 == 0)
            goto done;
        printf("not divisible by 2 --- %d\n", k);
        done:
            ; //null statement because we don't want to print anything after the goto
    }
    
}