/* Author: pbollom
Date: 2020-06-13
Description: strcmp, both array and pointer versions. These do not handle case,
             since it's just a character code comparison. */
#include<stdio.h>

int strcmpary(char *, char *);
int strcmpptr(char *, char *);

int main()
{
    /* Equal strings */
    printf("Array, equal: %d\n", strcmpary("Hello, world!", "Hello, world!"));
    printf("Pointer, equal: %d\n", strcmpptr("Hello, world!", "Hello, world!"));

    /* Equal strings, empty */
    printf("Array, equal: %d\n", strcmpary("", ""));
    printf("Pointer, equal: %d\n", strcmpptr("", ""));

    /* s sorts before t */
    printf("Array, negative: %d\n", strcmpary("b", "p"));
    printf("Pointer, negative: %d\n", strcmpptr("b", "p"));

    /* t sorts before s */
    printf("Array, positive: %d\n", strcmpary("p", "b"));
    printf("Pointer, positive: %d\n", strcmpptr("p", "b"));

    return 0;
}

/* strcmpary: string compraison; array version */
int strcmpary(char *s, char *t)
{
    int i;
    
    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
        {
            return 0;
        }
    }
    return s[i] - t[i];
}

/* strcmpptr: string comparison, pointer version */
int strcmpptr(char *s, char *t)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }
    return *s - *t;
}