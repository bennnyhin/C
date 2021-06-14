#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

void dynamic_memory_alloction(void) ;
struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list,  int n);
void deletingNode(void);
void pointer_to_pointers(void);
void add_to_list2(struct node **list, int n);

int main(void)
{
    //dynamic_memory_alloction();
    /*
    struct node *first = NULL;
    struct node *second;
    second = malloc(sizeof(struct node));
    (*second).value = 50;
    first = second;

    first = add_to_list(first, 10);
    first = add_to_list(first, 20);

    struct node *p;
    p = search_list(first, 20);
    printf("%d", p->value);
    */

//    deletingNode();
   pointer_to_pointers();

}

void dynamic_memory_alloction(void) 
{
    char *names[5];
    char name[50];
    for (int i = 0; i < 5; i++) {
        printf("Enter a name: ");
        scanf("%s", name);
        names[i] = malloc(strlen(name) + 1);
        if (names[i] == NULL) {
            printf("no space left\n");
            break;
        }
        else strcpy(names[i], name);
    }
    for (int j = 0; j < 5; j++) {
        printf("%s\n", names[j]);
        free(names[j]);
    }   

}

struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return list;
}

struct node *search_list(struct node *list,  int n) 
{
    struct node *p;

    for (p = list; p != NULL; p = p->next) {
        if (p->value == n)
            return p;
    }
    return NULL;
}

void deletingNode(void)
{
    struct node *first = NULL;
    struct node *new_node;
    int deleted_num;
    
    for (int i = 0; i < 5; i++) {
        printf("Enter a number: ");
        new_node = malloc(sizeof(struct node));
        scanf("%d", &new_node->value);
        new_node->next = first;
        first = new_node;
    }

    printf("Enter number that you want deleted: ");
    scanf("%d", &deleted_num);
    struct node *cur, *prev;
    for (cur = first, prev = NULL; cur != NULL && cur->value != deleted_num; prev = cur, cur = cur->next)
        ;
    putchar('\n');
    if (cur == NULL)
        printf("Couldn't find number\n");
    if (prev == NULL)
        printf("n is the first node\n");
    else {
        prev->next = cur->next;
        printf("Number removed\n");
        free(cur);
    }

    printf("New list: \n");
    for (struct node *p = first; p != NULL; p = p->next)
        printf("%d", p->value);
    printf("\n");

}


void pointer_to_pointers(void)
{
    struct node *first = NULL;
    add_to_list2(&first, 10);
    add_to_list2(&first, 20);

    struct node *p;
    for (; first != NULL; first = first->next) {
        printf("%d\n", first->value);
    }
    
}

void add_to_list2(struct node **list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Not enough memory for malloc\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;

    *list = new_node;
}