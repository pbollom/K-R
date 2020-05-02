/* Author: pbollom
Date: 2020-04-29
Description:
K&R 1-13 Prints a horizontal histogram of character frequencies in an input.
Will only print characters that appeared, and newline and tab are the only
unprintable characters that are handled. */  
#include<stdio.h>

#define ASCIICOUNT          128 /* The size of the ASCII character set */
#define FIRSTPRINTABLECODE  32  /* The ASCII code for space, the first printable */
#define LASTPRINTABLECODE   127 /* The ASCII code of ~, the last printable */

int main()
{
    int c, i, j, charCount;
    int nchars[ASCIICOUNT];

    for (i = 0; i < ASCIICOUNT; ++i)
    {
        nchars[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        ++nchars[c];
    }

    /* we will only print the printables plus newline and tab right now
       could easily flesh of the remaining characters in the future if desired
       The printing should be refactored into a separate method, but we have
       not covered that at this point in the book */
    charCount = nchars['\n'];
    if (charCount > 0)
    {
        printf("\\n:");
        for (j = 0; j < charCount; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    
    charCount = nchars['\t'];
    if (charCount > 0)
    {
        printf("\\t:");
        for (j = 0; j < charCount; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    for (i = FIRSTPRINTABLECODE - 1; i < LASTPRINTABLECODE; ++i)
    {
        charCount = nchars[i];
        if (charCount > 0)
        {
            printf("%2c:", i);
            for (j = 0; j < charCount; ++j)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}