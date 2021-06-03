#include <stdio.h>
#include "readline.h"
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int part_number;
    char part_name[NAME_LEN + 1];
    int quantity_on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void)
{
    char operation_code, part_name[NAME_LEN];
    int part_num;

    for (; ;) {
        printf("Enter operation code: ");
        scanf(" %c", &operation_code);
        while (getchar() != '\n')
            ;
        switch (operation_code) {
            case 'i': insert(); break;
            case 's': search(); break;
            case 'u': update(); break;
            case 'p': print(); break;
            case 'q': return 0; 
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

//determines whether the part exists based on the part number
int find_part(int number) 
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].part_number == number)
            return i; //returns the point in the array where the number was found
    return -1;
}


void insert(void)
{
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Database if full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {//if the part already is in the database
        printf("Part already exists. \n");
        return;
    }
    inventory[num_parts].part_number = part_number;

    printf("Enter part name: ");
    read_line(inventory[num_parts].part_name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].quantity_on_hand);
    num_parts++;
    return;
}

void search(void)
{
    int part_number, i;
    printf("Enter part number: ");
    scanf("%d", &part_number);
    i = find_part(part_number);
    if (i >= 0) {
            printf("Part name: %s\n", inventory[i].part_name);
            printf("Quantity on hand: %d", inventory[i].quantity_on_hand);
    }
    else printf("that product is not in the inventory\n");
    return;
}

void update(void)
{
    int part_num, i, change;
    printf("Enter part number: ");
    scanf("%d", &part_num);
    i = find_part(part_num);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].quantity_on_hand = change;
    }
    else printf("Part not found.\n");
}

void print(void)
{
    printf("Part number     Part Name             Quantity on Hand\n");
    for (int i = 0; i < num_parts; i++) {
        printf("%7d         %-25s%11d\n", inventory[i].part_number, inventory[i].part_name, inventory[i].quantity_on_hand);
    }
}