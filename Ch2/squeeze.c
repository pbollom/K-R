/* Author: pbollom
Date: 2020-05-17
Description: 2-4 Remove all characters from s1 that also exist in s2 */
#include<stdio.h>

void squeeze(char s1[], char s2[]);
int charInStr(char s[], int c);

int main()
{
    char s[] = "Hello, world! This input string should be stripped of all: a,s,d,f";
    squeeze(s, "asdf");
    printf("%s\n", s);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (!charInStr(s2, s1[i]))
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int charInStr(char s[], int c)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return 1;
        }
    }

    return 0;
}