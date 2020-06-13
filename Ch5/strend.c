/* Author: pbollom
Date: 2020-06-13
Description: 5-4 strend, returns 1 if the string t occurs at the end of string s, 0 otherwise. */
#include<stdio.h>

#define FALSE   0
#define TRUE    1

int strend(char *, char *);

int main()
{
    /* both empty strings */
    printf("both empty (expect 1): %d\n", strend("", ""));
    
    /* t empty string */
    printf("t empty (expect 1): %d\n", strend("Hello", ""));

    /* t longer than s */
    printf("t longer than s (expect 0): %d\n", strend("Hello", "World!"));

    /* s does not end with t */
    printf("s does not end with t (expect 0): %d\n", strend("Hello", "World"));

    /* s ends with t */
    printf("s ends with t (expect 1): %d\n", strend("Hello", "lo"));
    
    return 0;
}

int strend(char *s, char *t)
{
    int slength, tlength, i;

    slength = 0;
    while (*++s)
    {
        slength++;
    }
        
    tlength = 0;
    while (*t++)
    {
        tlength++;
    }
    
    if (tlength > slength)
    {
        return FALSE;
    }

    while (i < tlength)
    {
        if (*s-- != *t--)
        {
            return FALSE;
        }
        i++;
    }

    return TRUE;
}