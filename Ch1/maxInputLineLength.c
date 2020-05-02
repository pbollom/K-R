/* Author: pbollom
Date: 2020-05-01
Description:
1-16 Finds the length of the longest line in the input
Prints up to the first 999 characters of that input */  
#include<stdio.h>

#define MAXLINE 1000 /* maximum line length */

int gtline(char line[], int maxline);
void copy(char from[], char to[]);
int gtremaininglen();

int main()
{
    int len;    /* current line length */
    int max;    /* current maximum line length */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* maximum saved input line */

    max = 0;
    while ((len = gtline(line, MAXLINE)) > 0)
    {
        if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') /* we hit the maximum and it was not terminated by a newline */
        {
            len = len + gtremaininglen(); /* the actual length of the line */
        }

        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
    }
    if (max > 0) /* there was a line */
    {
        printf("\n%s\n", longest);
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

/* when gtline returns an incomplete line, this is used to get the remaining length of that line */
int gtremaininglen()
{
    int c, i;

    i = 0;
    while ((c = getchar()) != '\n')
    {
        ++i;
    }
    ++i; /* add the extra character for the newline */

    return i;
}

/* copy 'from' into 'to'; assume 'to' is big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}