#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAXLENGTH 100

int read_line(char *string, int n);
int read_line2(char *string, int n);
int read_line3(char *string, int n);
int read_line4(char *string, int n);
void capitalize(char *string, int n);
void capitalize2(char *string, int n);
void censor(char s[]);
void get_extension(char *file_name, char *extension);
void get_extension2(char *file_name, char *extension);
int count_spaces(char *s);
bool test_extension(char *file_name, char *extension);
void remove_filename(char *url);
void remove_filename2(char *url);

int main(void)
{
    //exercise 1
    // printf("%s", "\n");
    // puts("");

    //exercise 2
    // char *p = "abc";
    // putchar(*p);
    // puts(p);

    //exercise 3
    // int i, j;
    // char *s;
    // scanf("%d%s%d", &i, s, &j); 
    // printf("%d\n", i);
    // printf("%s\n", s);
    // printf("%d\n", j);

    //exercise 4a
    // char test[50], test2[50], test3[50], test4[3];
    // int N = 50, N2 = 3;
    // read_line(test, N);
    // printf("%s", test);

    // read_line2(test2, N);
    // printf("%s", test2);

    // read_line3(test3, N);
    // printf("%s", test3);

    // read_line4(test4, N2);
    // printf("%s", test4);

    //exercise 5
    // char test[100];
    // capitalize2(test, 100);
    // printf("%s", test);

    // censor(test, 100);
    // printf("%s", test);

    //exercise 6
    // char sentence[MAXLENGTH];
    // read_line(sentence, MAXLENGTH);
    // censor(sentence);
    // printf("%s", sentence);

    //exercise 12
    // char file[100], extension[100];
    // get_extension2("memo.txt", extension);
    // puts(extension);

    //exercise 14
    // char s[] = "Hsjodi", *p;
    // for (p = s; *p; p++) //*p is equivalent to *p != '\0'
    //     --*p;
    // puts(s);

    //exercise 16
    /*
    char sentence[] = "test dsk sdf";
    printf("%d\n", count_spaces(sentence));
    */

   //exercise 17
//    if (test_extension("memo.txt", "TXT"))
//         printf("true");

    //exercise 18
    char url[] = "http://www.knking.com/index.html/test";
    remove_filename(url);
    printf("%s\n", url);

}

int read_line(char *string, int n)
{
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        if (i == 0 && isspace(ch))
            ;
        else if (i < n)
            string[i++] = ch;
    }
    string[i] = '\0';
    return i;
}

int read_line2(char *string, int n)
{
    int i = 0, ch;
    while ((ch = getchar()) != '\n') {
        if (isspace(ch))
            break;
        string[i++] = ch;
    }
    string[i] = '\0';
    return i;
}

int read_line3(char *string, int n)
{
    int i = 0, ch;
    while ((ch = getchar()) != '\n') {
        string[i++] = ch;
    }
    string[i] = '\n';
    string[i+1] = '\0';
    return i+1;
}

int read_line4(char *string, int n)
{
    int i = 0, ch;
    while ((ch = getchar()) != '\n') {
        if (i >= n)
            break;
        string[i++] = ch;
    }
    string[i] = '\0';
    return i;

}

void capitalize(char string[], int n)
{
    int i = 0, ch;
    while ((ch = getchar()) != '\n') {
        string[i++] = toupper(ch);
    }
    string[i] = '\0';
    return;
}

void capitalize2(char *string, int n) //using pointer arithmetics
{
    char *p = string, ch;
    while ((ch = getchar()) != '\n') {
        *p++ = toupper(ch);
    }
    *p = '\0';
    return;
}

void censor(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'f' && s[i+1] == 'o' && s[i+2] == 'o')
            s[i] = s[i+1] = s[i+2] = 'x';
    }
    return;
}

//exercise 12
void get_extension(char *file_name, char *extension)
{
    char *p = file_name, *q = extension, ch;
    while ((ch = getchar()) != '.') {
        if (ch == '\n') {
            *p = '\0';
            *q = '\0';
            return;
        }
        *p++ = ch;
    }
    while ((ch = getchar()) != '\n') {
        *q++ = ch;
    }
    *p = '\0';
    *q = '\0';
    return;
}

void get_extension2(char *file_name, char *extension) 
{
    while (*file_name) {
        if (*file_name++ == '.') {
            strcpy(extension, file_name);
            return;
        }
    }
    strcpy(extension, "");
}

int count_spaces(char *s)
{
    char *p = s;
    int count = 0;
    while (*p) {
        if (*p++ == ' ')
            count++;
    }
    return count;
}

//exercise 17
bool test_extension(char *file_name, char *extension)
{
    while (*file_name++ != '.')
        ;
    while (*file_name && *extension)
        if (toupper(*file_name++) != toupper(*extension++))
            return false;
    return true;
}

//exercise 18
void remove_filename(char *url) //mine
{
    char *p = url;
    int i = 0;
    while(i < 2) {
        if (*p++ == '/')
            i++;
    }
    while (*p++ != '\0') {
        if (*p == '/')
            *p = '\0';
    }
    return;
}

void remove_filename2(char *url) { //answer
    char *p = url;
    while (*url) {
        if (*url == '/') //only removes the last part of the url not all
            p = url;
        url++;
    }
    *p = '\0';
}