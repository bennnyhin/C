#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct point {int x, y; };
struct rectangle {struct point upper_left, lower_right; };
struct rectangle *p;

struct part {
    int part_number;
    char name[50];
    int on_hand;
};

//5
// struct {
//     union {
//         char a, b;
//         int c;
//     } d;
//     int e[5];
// } f, *p = &f;

//6
struct node {
    int value;
    struct node *next;
};

//macros

//prototypes
void *my_malloc(size_t n);
char *duplicate(char *string);
int *create_array(int n, int initial_value);
int *create_array2(int n, int initial_value);
bool push(struct node **top, int n);
int count_occurrences(struct node *list, int n);
struct node *add_linked_list(struct node *list, int n);
struct node *find_last(struct node *list, int n);
int compare(const void * x, const void * y);
int compare2(const void *x, const void *y);

int main(void)
{
    /*
    //1
    char *string;
    string = my_malloc(sizeof(*string));
    printf("enter a word: ");
    scanf("%s", string);
    printf("%s\n", string);

    //2
    char *copy = duplicate(string);
    printf("%s\n", copy);

    //3
    // int *p = create_array(5, 10);

    int *array = create_array2(10, 2);
    int *a = array;
    for (int count = 0; count < 10; count++)
        printf("%d\n", *a++);

    //4
    // p = (struct rectangle *) malloc(sizeof(struct rectangle));
    // (*p).lower_right = {10, 5};
    // p->lower_right = {20, 15};

    //5
    /*
    a) does not work because it has to be *(p.d.b);
    b) works
    c) works
    d) has to be *p.d.c = 20
    */

   /*
   //8
   struct node *first = NULL;
   if (push(&first, 10))
        printf("success\n");
    else printf("failure\n");

    //11
    struct node *list = NULL;
    int number, occurance_num;
    for (int i = 0; i < 3; i++) {
        printf("Enter a number: ");
        scanf("%d", &number);
        list = add_linked_list(list, number);
    }
    printf("Number you want to see occurances of: ");
    scanf("%d", &occurance_num);
    printf("Occurances of %d: %d\n", occurance_num, count_occurrences(list, occurance_num));

    struct node *match;
    match = find_last(list, occurance_num);
    printf("%d", match->value);
    */

    int values[] = {3, 5, 6, 2, 1, 3, 52, 3, 32, 543, 23, 23, 543, 76, 9, 4, 2};
    for (int i = 0; i < 17; i++)
        printf("%d ", values[i]);
    putchar('\n');
    for (int *p = values; p < &values[17]; p++)
        printf("%d ", *p);
    printf("\n");
    qsort(values, 17, sizeof(int), compare);
    for (int j = 0; j < 17; j++)
        printf("%d ", values[j]);
    putchar('\n');

    int values2[] = {3, 5, 6, 2, 1, 3, 52, 3, 32, 543, 23, 23, 543, 76, 9, 4, 2};
    int *q = &values2[10];
    qsort(q, 7, sizeof(int), compare);
    for (int j = 0; j < 17; j++)
        printf("%d ", values2[j]);

    

}

//1
void *my_malloc(size_t n)
{
    void *test = malloc(n);
    if (test == NULL) {
        printf("Not enough memory for malloc\n");
        exit(EXIT_FAILURE);
    }
    return test;
}

//2
char *duplicate(char *string)
{
    char *copy;
    copy = my_malloc(strlen(string));
    strcpy(copy, string);
    return copy;
}

int *create_array(int n, int initial_value)
{
    int *array[n];
    int i;
    for (i = 0; i < n; i++)
        array[i] = malloc(sizeof(initial_value));
        *array[i] = initial_value;
        if (array[i] == NULL) {
            printf("No memory available for malloc\n");
            return NULL;
        }
    return *array;
}

//correct way
int *create_array2(int n, int initial_value)
{
    int *a, *p;
    if ((a = (int *)malloc(n * sizeof(int))) == NULL) {
        printf("Error: malloc failed\n");
        return NULL;
    }
    for (p = a; p < a + n; p++)
        *p = initial_value;
    return a;
}

/*
struct node *delete_from_list(struct node **list, int n) {
    struct node *item = *list;
    while (item != NULL) {
        if (item->value == n) {
            *list = item->next;
            free(item);
            break;

        }
        list = item->next;
        item = list->next;
    }
    return list;
}
*/

/*
void delete_all(struct node **first)
{
    struct node *p, *next_node = (*first)->next;
    for (p = *first; p != NULL; p = p->next)
        next_node = p->next;
        free(p);
}
*/

bool push(struct node **top, int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        return false;
    new_node->value = n;
    new_node->next = *top;
    *top = new_node;
    return true;
}

void print_part(struct part *p)
{
    printf("Part number: %d\n", p->part_number);
    printf("part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
}

struct node *add_linked_list(struct node *list, int n)
{
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        exit(EXIT_FAILURE);
    new_node->value = n;
    new_node->next = list;
    list = new_node;
    return list;
}

int count_occurrences(struct node *list, int n)
{
    int count = 0;
    struct node *p;
    for (p = list; p != NULL; p = p->next) {
        if (p->value == n)
            count++;
    }
    return count;
}

//12
struct node *find_last(struct node *list, int n)
{
    struct node *match = NULL, *cur;
    for (cur = list; cur != NULL; cur = cur->next) {
        if (cur->value == n)
            match = cur;
    }
    if (match == NULL)
        return NULL;
    else return match;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node **pp = &list;
    while (list != NULL) {
        if (list->value >= new_node->value)
            break;
        pp = &list->next;
        list = list->next;
    }
    *pp = new_node;
    new_node = list;
    return list;
}

void delete_from_list(struct node **list, int n)
{
    struct node *entry = *list;

    while (entry != NULL) {
        if (entry->value == n) {
            *list = entry->next;
            free(entry);
        }
        list = &entry->next;
        entry = entry->next;
    }

}

//16
int sum(int (*f)(int), int start, int end)
{
    int sum = 0;
    while (start++ <= end) {
        sum += (*f)(start);
    }
    return sum;
}

//17
int compare(const void * x, const void * y)
{
    return (*(int*)x - *(int*)y);
}

int compare2(const void *x, const void *y)
{
    return (*(int*)y - *(int*)x);
}

void call_function(char string[100])
{
    for (int i = 0; i < sizeof(file_cmd) / sizeof(file_cmd[0]); i++) {
        if (strcmp(file_cmd[i].cmd_name, string) == 0) {
            return (*file_cmd[i].cmd_pointer)();
        }
    return;
    }
    if (strcmp(string, ))
}

