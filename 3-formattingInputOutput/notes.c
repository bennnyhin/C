#include <stdio.h>

// function decleration
int test(void);
int printfnotes(void);
int scanfnotes(void);

int main(void)
{
    printf("%-12.5e\n", 30.253);
    printf("|%-10.2g|\n", .0000009979);
    printf("%.4f\n", 83.162);
    // printfnotes();
    // scanfnotes();

}

int printfnotes(void)
{
    //main specifiers are d, f, e, g which can be manipulaed with m and p 
    int height = 40;
    float x = 839.210f;
    printf("%4d\n", height); //the 4 represents the minium field width 
    printf("|%-4d|\n", height); //prints the extra spaces behind instead of in front
    printf("%.3d\n", height); //p for decimal form indicates the minmum of digits to display
    printf("%g\n", x); //g specifier is used when displaying numbers whosoe size can't be predicted 
    printf("%e\n", x);
    return 0;
}

int scanfnotes(void)
{
    //don't put a \n at the end of a scanf
   int i,j;
   float x,y;
   scanf("%d%d%f%f", &i, &j, &x, &y); //scanf skips blank spaces if neccessary both horizontally and vertically
   printf("%d, %d, %f, %f", i,j,x,y);

   //if there are other characters in a format string for scanf, scanf will compare it with the next input character
   scanf("%d /%d", &i,&j);  //scanf reads the following character so you should add a space before the / 
   printf("%d / %d\n", i,j);
   return 0;
}





