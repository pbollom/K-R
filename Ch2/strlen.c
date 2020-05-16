/* Author: pbollom
Date: 2020-05-16
Description: Determine the length of a string */
#include<stdio.h>

#define MAXLEN  1000; /* maximum length of string we'll support */

int mystrlen(char s[]);

int main()
{
    printf("Hello, world! Has length: %d\n", mystrlen("Hello, world!"));
    return 0;
}

/* must scan the entire string to figure out the length */
int mystrlen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}