//May 23, 2021
#include <stdio.h>
#include <string.h>

//Macro definitions
#define MAX_REMIND 50
#define MSGLEN 60

//prototypes
int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSGLEN];
    char day_str[2+1], msg_str[MSGLEN + 1];
    int num_reminders = 0, day, i, j;

    for (; ;) {
        if (num_reminders > MAX_REMIND) {
            printf("No more space for reminders\n");
            break;
        }
        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSGLEN);

        for (i = 0; i < num_reminders; i++)
            if (strcmp(day_str, reminders[i]) < 0) 
                break;
        for (j = num_reminders; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        num_reminders++;
    }
    
    printf("\nDay Reminder\n");
    for (i = 0; i < num_reminders; i++)
        printf("%s\n", reminders[i]);
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n'){
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;

}