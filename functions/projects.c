//May 20, 2021

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int n, int a[]);
void randomWalk(void);
int* twoSum(int* nums, int numsSize, int target);

int main(void)
{
    //project 1 for selection sort
    /*
    int n;
    printf("How many integers do you want to sort?\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    selection_sort (n, a);
    for (int j = 0; j < n; j++)
        printf("%d\n", a[j]);
    */
   // randomWalk();
    // int a[] = twoSum((int []){2,7,11,15}, 4, 9);
    // printf("%d", a[0]);

    //project 7 
    int x, n;
    printf("Enter two values (x and n) which is in the form x^n: ");
    scanf("%d %d", &x, &n);




}

//project 1
void selection_sort (int n, int a[])
{
    int largest = 0, largest_index;
    int temp;

    if (n == 0)
        return;

    for (int i = 0; i < n; i++)
        if (largest < a[i]) {
            largest = a[i];
            largest_index = i;
        }
    temp = a[n-1];
    a[largest_index] = temp;
    a[n-1] = largest;
            
    selection_sort (n-1, a);
}

//project 9 chapter 8 
void randomWalk(void)
{
    int randomNum;
    char board[10][10] = {
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    int lastX = 0, lastY = 0;
    for (char letter = 'A'; letter < 'Z'; letter++) {
        board[lastX][lastY] = letter;
        
        premature:
        randomNum = rand();
        switch (randomNum % 4) {
            case 0: //down
                if (lastY != 10) {
                    lastY -= 1; 
                    break;
                }
                else goto premature;
            case 1: //up
                if (lastY != 0) {
                    lastY += 1; 
                    break;
                }
                else goto premature;
            case 2: //left
                if (lastX != 0) {
                    lastX -= 1; 
                    break;
                }
                else goto premature;
            case 3: //right
                if (lastX != 10) {
                    lastY += 1; 
                    break;
                }
                else goto premature;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 9)
                printf(" %c \n", board[i][j]);
            else
                printf(" %c ", board[i][j]);
        }
    }
}

// two sum leetcode
int* twoSum(int* nums, int numsSize, int target){
    
    int returnArray[2];
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (j == i)
                break;
            if (nums[i] + nums[j] == target)
                returnArray[0] = i;
                returnArray[1] = j;
        }
    }
    return returnArray;
}

//project 7
long powerFunction(int x, int n)
{
    long result;
    //check if n is odd or even
    if (n % 2 == 0) {
        
    }
}
