/* Author: pbollom
Date: 2020-05-02
Description:
1-18 Removes trailing blanks and tabs from lines, and completely removes blanks lines */  
#include<stdio.h>

#define MAXLINE 1000 /* the maximum length of line we will handle */

int gtline(char line[], int maxline);
int rmblanks(char line[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = gtline(line, MAXLINE)) > 0)
    {
        if (rmblanks(line, len) > 0)
        {
            printf("%s\n", line);
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

/* using the passed line, remove trailing whitespace (and newline) and return the new length */
int rmblanks(char s[], int len)
{
    int i;

    i = len;
    if (s[i - 1] == '\n') /* Start by removing the newline, we'll add it back for printing */
    {
        --i;
    }

    while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
    {
        --i;
    }

    s[i] = '\0'; /* move the null ending to our new position */
    return i;
}