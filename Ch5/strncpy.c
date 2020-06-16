/* Author: pbollom
Date: 2020-06-13
Description: strcpy, both array and pointer versions */
#include<stdio.h>

void strncpy2(char *, char *, int);

int main()
{
    char *s;

    /* returns substring */
    strncpy2(s, "Hello, world", 5);
    printf("%s\n", s);

    /* returns entire string */
    strncpy2(s, "Hello", 5);
    printf("%s\n", s);

    /* n > string length */
    strncpy2(s, "Hello", 6);
    printf("%s\n", s);

    /* empty string, zero length */
    strncpy2(s, "", 0);
    printf("%s\n", s);

    /* empy string, some length */
    strncpy2(s, "", 5);
    printf("%s\n", s);

    return 0;
}

/* strncpy2: copy t to s; pointer version */
void strncpy2(char *s, char *t, int n)
{
    int i;

    if (n == 0)
    {
        *s = '\0';
        return;
    }

    i = 0;
    while (i < n && (*s++ = *t++))
    {
        i++;
    }
    if (i == n && *--s != '\0')
    {
        *++s = '\0';
    } 
}