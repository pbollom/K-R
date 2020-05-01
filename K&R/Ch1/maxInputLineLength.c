/* Author: pbollom
Date: 2020-05-01
Description:
Finds the length of the longest line in the input */  
#include<stdio.h>

#define MAXLINE 1000 /* maximum line length */

int gtline(char line[], int maxline);
void copy(char from[], char to[]);

int main()
{
    int len;    /* current line length */
    int max;    /* current maximum line length */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE]; /* maximum saved input line */

    max = 0;
    while ((len = gtline(line, MAXLINE)) > 0)
    {
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