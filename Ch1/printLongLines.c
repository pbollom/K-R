/* Author: pbollom
Date: 2020-05-01
Description:
1-17 Prints the content of all lines longer than 80 characters */  
#include<stdio.h>

#define LONGLINE 80 /* the length to consider a line for printing */

int gtline(char line[], int maxline);

int main()
{
    int len, c;
    char line[LONGLINE + 1]; /* one longer to account for null ending */

    while ((len = gtline(line, LONGLINE + 1)) > 0)
    {
        /* the book does not specify, but I will consider newline part of the line 
           80 printable characters plus a newline will be printed by this program */
        if (len == LONGLINE && line[LONGLINE - 1] != '\n')
        {
            printf("%s", line);
            while ((c=getchar()) != '\n')
            {
                printf("%c", c);
            }
            printf("\n");
        }
    }

    return 0;
}

/* read a line into s, return the length */
int gtline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}