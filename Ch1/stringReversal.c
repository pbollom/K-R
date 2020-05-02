/* Author: pbollom
Date: 2020-05-02
Description:
1-19 Reverses a string up to 1000 characters in length. Trailing blanks are considered part of the string. */  
#include<stdio.h>

#define MAXLINE 1000 /* the maximum length of line we will handle */

int gtline(char line[], int maxline);

int main()
{
    int len, i;
    char line[MAXLINE];

    while ((len = gtline(line, MAXLINE)) > 0)
    {
        for (i = len - 2; i >= 0; --i) /* character at len-1 is \n; we add that separately */
        {
            printf("%c", line[i]);
        }
        printf("\n");
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