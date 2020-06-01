/* Author: pbollom
Date: 2020-05-31
Description: 4-14 a macro to swap two arguments of type t */
#include<stdio.h>

#define swap(t, x, y) t temp = x; x = y; y = temp;

int main()
{
    /*int x, y;
    x = 2;
    y = -2;
    swap(int, x, y);
    printf("x=%d y=%d\n", x, y);*/

    char x, y;
    x = 'p';
    y = 'B';
    swap(char, x, y);
    printf("x=%c y=%c\n", x, y);

    return 0;
}