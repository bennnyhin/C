#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXLEN 50

//exercise 1
#define cube(x) ((x)*(x)*(x))
#define remainder_4(n) ((n) % 4))
#define less_than_1000(x, y) (((x)*(y)<100) ? 1 : 0)

//exercise 2
#define NELEMNS(a) (sizeof(a) / sizeof(a[0]))

//3
#define DOUBLE(x) (2*(x)) //needs brackets around x in case ofo (1+2)

//5
#define TOUPPER(c) ('a'<=(c) && (c)<='z' ? (c)-'a'+'A': (c))

//6
#define DISP(func,x) (printf("%s(%g) = %g\n", (#func), (x), (func(x))))

//8
#define STRINGIZE(x) #x
#define EXPAND_MACRO(x) STRINGIZE(x)
#define LINE_FILE ("Line " EXPAND_MACRO(__LINE__) " of file " __FILE__)

//9
#define CHECK(x, y, n) (0 < (x) && (x) < ((n)-1) && 0 < (y) && (y) < ((n)-1) ? 1 : 0)
#define MEDIAN(x, y, z) ((x)>=(y)&&(x)<=(z)?x : (y)>=(x)&&(y)<=(z))?(y):(z))
#define POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x) \
                    + 2*(x)*(x)*(x)*(x) \
                    - 5(x)*(x)*(x)*(x) \
                    - (x)*(x) \
                    + 7*(x)-6)
#define ENGLISH

//11
#define ERROR (fprintf(stderr, "Range error: index = %d\n", index)

//15


int main(void)
{
    //1
    printf("%d\n", cube(3));
    printf("%d\n", remainder_4(11);
    printf("%d\n", less_than_1000(10, 9));

    //2
    int test[] = {1, 2, 3, 4};
    printf("%ld\n", NELEMNS(test));

    //3
    printf("%d\n", DOUBLE(1+2));

    //5
    /*
    char s[] = "abcd";
    int i = 0;
    putchar(TOUPPER(s[++1]));
    */

   //6
   DISP(sqrt, 25.0);

   //7
   /*
   GENERIC_MAX(long) 
   long long_max(long x, long y) {return x > y ? x : y; }
   */

    //8
    const char *str = LINE_FILE;
    puts(str);

    //9
    printf("%d", CHECK(1, 2, 3));

    #if defined(FRENCH)
    #define INSERT_DISK "Inserez Le Disque 1"
    #
    #elif defined(ENGLISH)
    #define INSERT_DISK "Insert Disk 1"
    #
    #else
    #define INSERT_DISK "Inserte El Disco 1"
    #
    #endif

    printf("%s\n", INSERT_DISK);



}