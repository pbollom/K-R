/* Author: pbollom
Date: 2020-06-13
Description: strcat, copy one string to the end of another, pointer version */
#include<stdio.h>
#include<stdlib.h>

#define MAXLEN  1000    /* maximum length concatenated string we'll handle */

void strcatptr(char *, char *);

int main()
{
    char s[MAXLEN] = "Hello, world!";

    strcatptr(s, " It's a beautiful day!");
    printf("%s\n", s);

    return 0;
}

void strcatptr(char *s, char *t)
{
    while (*++s)
        ;
    while ((*s++ = *t++))
        ;
}