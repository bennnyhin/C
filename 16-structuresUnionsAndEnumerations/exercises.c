//June 1, 2021

#include <stdio.h>
#include <stdbool.h>

#define PI 3.142857

//2
struct {
    double real;
    double imaginary;
} c1 = {0.0, 1.0}, c2 = {.real = 1.0, .imaginary = 0.0}, c3;

//3
struct complex {
    double real;
    double imaginary;
} a1, a2, a3;

//4
typedef struct {
    double real;
    double imaginary;
} complex2;

//5
struct date {
    int month; 
    int day;
    int year;
};

//6
struct time {
    int hours;
    int minutes;
    int seconds;
};

struct fraction {
    int numerator;
    int denominator;
};

struct color {
    int red; 
    int green;
    int blue;
};

struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right; };

//14
struct shape {
    enum {RECTANGLE, CIRCLE} shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
}s;

//15
enum days {monday = 10, tuesday, wednesday, thursday, friday, saturday, sunday};
// typedef enum {monday, tuesday, wednesday, thursday, friday, saturday, sunday} days2;

//18
typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {BLACK, WHITE} Color;

//a
typedef struct {
    Piece piece;
    Color color;
} Square;

//19
struct pinball_machine {
    char name[40+1];
    int year;
    enum {EM, SS} type;
    int players;
};

//20
enum {NORTH, SOUTH, EAST, WEST} direction;

//21
enum {SO = 45, SI, DLE, CAN = 37, EK} test_enum;

//make sure to put the prototypes before the structs
struct complex make_complex(double real, double imaginary);
complex2 make_complex2(double real, double imaginary);
int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);
struct time split_time(long total_seconds);
struct fraction reduce(struct fraction f1);
struct fraction add_fraction(struct fraction f1, struct fraction f2);
struct color make_color(int red, int green, int blue);
bool equal_color(struct color color1, struct color color2);
int getRed (struct color c);
int area(struct rectangle r1);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int x, int y);
double area2 (struct shape s);
struct shape scale(struct shape s, double c);

int main(void)
{
    c2 = c1;
    printf("%lf\n", c2.real);
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    struct complex test1 = make_complex(1.0, 2.0);
    printf("%lf\n", test1.real);

    struct date d1 = {2, 5, 2004};
    struct date d2 = {3, 5, 2004};
    printf("%d\n", day_of_year(d1));
    printf("%d\n", compare_dates(d1, d2));

    struct time t1 = split_time(23423);
    printf("H:%d M:%d S:%d\n", t1.hours, t1.minutes, t1.seconds);

    struct fraction f1 = {2, 10};
    struct fraction reduced_fraction = reduce(f1);
    printf("%d/%d\n", reduced_fraction.numerator, reduced_fraction.denominator);

    struct fraction f2 = {3, 7};
    struct fraction added = add_fraction(f1, f2);
    printf("Sum: %d/%d\n", added.numerator, added.denominator);

    const struct color MAGENTA = {255, 0, 255};
    printf("%d\n", MAGENTA.red);
    const struct color MAGENTA2 = {.red = 255, .blue = 255};
    struct rectangle r1 = {(struct point){3, 6}, (struct point){7, 0}};
    printf("Area: %d\n", area(r1));

    printf("Center = x: %d  y: %d\n", center(r1).x, center(r1).y);
    struct shape rec = {.shape_kind = RECTANGLE, .center = {1, 2}, .u.rectangle.height = 5, .u.rectangle.width = 4};
    printf("Area: %.2lf\n", area2(rec));

    enum days day1;
    day1 = tuesday;
    printf("%d\n", day1);

    //18
    Square board[8][8] = {
    {{ROOK,  WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE},
     {KING,  WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK,  WHITE}},
    {{PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE},
     {PAWN,  WHITE}, {PAWN,   WHITE}, {PAWN,   WHITE}, {PAWN,  WHITE}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK},
     {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK},
     {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK},
     {EMPTY, BLACK}, {EMPTY,  BLACK}, {EMPTY,  BLACK}, {EMPTY, BLACK}},
    {{PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK},
     {PAWN,  BLACK}, {PAWN,   BLACK}, {PAWN,   BLACK}, {PAWN,  BLACK}},
    {{ROOK,  BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK},
     {KING,  BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK,  BLACK}},
    };

    //19
    direction = WEST;
    struct point location = {0, 0};
    if (direction == WEST)
        printf("West\n");
    
    //21
    test_enum = SI;
    printf("%d\n", test_enum);

    //22
    int piece_value = {200, 9, 5, 3, 3, 1};
    int piece_value2 = {[KING] = 200, [QUEEN] = 9, [ROOK] = 5, [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1};
}


struct complex make_complex(double real, double imaginary)
{
    struct complex number;
    number.real = real;
    number.imaginary = imaginary;
    return number;
}

complex2 make_complex2(double real, double imaginary)
{
    complex2 number; 
    number.real = real;
    number.imaginary = imaginary;
    return number;
}

int day_of_year(struct date d) 
{
    int days = 0;
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < (d.month - 1); i++) {
        days += days_in_month[i];
    }
    days += d.day;
    return days;
}

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else {
        if (d1.month < d2.month)
            return -1;
        else if (d1.month > d2.month)
            return 1;
        else {
            if (d1.day < d2.day)
                return -1;
            else if (d1.day > d2.day)
                return 1;
            else return 0;
        }
    }
}

struct time split_time(long total_seconds)
{
    struct time split;
    split.hours = total_seconds / 3600;
    total_seconds %= 3600;
    split.minutes = total_seconds / 60;
    split.seconds = total_seconds % 60;
    return split;
}

struct fraction reduce(struct fraction f1)
{
    int GDC = 0;
    struct fraction reduced;
    for (int i = 1; i <= f1.denominator && i <= f1.numerator; i++) {
        if (f1.denominator % i == 0 && f1.numerator % i == 0)
            GDC = i;
    } 
    reduced.numerator = (f1.numerator / GDC);
    reduced.denominator = (f1.denominator / GDC);
    return reduced;
}

struct fraction add_fraction(struct fraction f1, struct fraction f2)
{
    struct fraction added;
    f1.numerator *= f2.denominator;
    f2.numerator *= f1.denominator;
    added.numerator = f1.numerator + f2.numerator;
    added.denominator = f2.denominator * f1.denominator;
    added = reduce(added);
    return added;
}

struct color make_color(int red, int green, int blue)
{
    if (red < 0)
        red = 0;
    else if (red > 255)
        red = 255;
    if (green < 0)
        green = 0;
    else if (green > 255)
        green = 255;
    if (blue < 0)
        blue = 0;
    else if (blue > 255)
        blue = 255;
    return (struct color) {red, green, blue}; //compound literal
}

int getRed (struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    if (color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue)
        return true;
    else return false;
}

int area(struct rectangle r1)
{
    int length, width;
    width = r1.lower_right.x - r1.upper_left.x;
    length = r1.upper_left.y - r1.lower_right.y;
    return width * length;
}

struct point center(struct rectangle r)
{
    struct point center;
    center.y = (r.upper_left.y + r.lower_right.y) / 2;
    center.x = (r.upper_left.x + r.lower_right.x) / 2;
    return center;
}

struct rectangle move(struct rectangle r, int x, int y)
{
    struct rectangle moved;
    moved.upper_left.x = r.upper_left.x + x;
    moved.upper_left.y = r.upper_left.y + y;
    moved.lower_right.x = r.lower_right.x + x;
    moved.lower_right.y = r.lower_right.y + y;
    return moved;
}

double area2 (struct shape s)
{
    if (s.shape_kind == RECTANGLE)
        return (double) (s.u.rectangle.height * s.u.rectangle.width);
    else
        return (double) (s.u.circle.radius * s.u.circle.radius * PI);
}

struct shape scale(struct shape s, double c)
{
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else {
        s.u.circle.radius *= c;
    }
    return s;
}