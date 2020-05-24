/* Author: pbollom
Date: 2020-05-24
Description: 4-1 Find the first location of a given substring in a string */
#include<stdio.h>

#define MAXLINE 1000

int gtline(char line[], int max);
int strnglen(char s[]);
int strrindex(char source[], int sourcelength, char searchfor[], int searchforlength);

char pattern[] = "ould";

/* find all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int linelength;
    int found = 0;
    int patternlength = strnglen(pattern);
    int rindex;

    while ((linelength = gtline(line, MAXLINE)) > 0)
    {
        if ((rindex = strrindex(line, linelength, pattern, patternlength)) >= 0)
        {
            printf("%d: %s", rindex, line);
            found++;
        }
    }
}

/* get line (up to length lim) into s, return length */
int gtline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

/* return the length of a string */
int strnglen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i;
}

/* return the last index of t in s, or -1 if none */
int strrindex(char s[], int slen, char t[], int tlen)
{
    int i, j, k;

    for (i = slen - tlen; i >= 0; i--)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}