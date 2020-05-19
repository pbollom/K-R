/* Author: pbollom
Date: 2020-05-19
Description: 2-10 Convert uppercase letters to lowercase letters using a conditional expression */
#include<stdio.h>

char lower(char c);

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        printf("%c", lower(c));
    }

    return 0;
}

/* Convert uppercase English letters to lowercase, and leave all other characters untouched */
char lower(char c)
{
    /* we do the conditional expression in this order so that any non-
       alphabetic characters are not converted */
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}