/* Author: pbollom
Date: 2020-05-21
Description: 3-2 Copies an input string from one array to another, making escaped characters
             visible, then reverting them. Prints both output strings. Currently only handles
             tab and newline characters. */
#include<stdio.h>

#define MAXINPUT    1000 /* maximum input length */

void escape(char s[], char t[]);
void unescape(char t[], char s[]);

int main()
{
    int c, i;
    char s[MAXINPUT + 1];
    char t[MAXINPUT * 2 + 1]; /* twice the length for the case when every character is escaped */

    i = 0;
    while ((c = getchar()) != EOF && i < MAXINPUT)
    {
        s[i++] = c;
    }
    s[i] = '\0';

    escape(s, t);
    printf("\nEscaped:\n");
    printf("%s\n", t);

    unescape(t, s);
    printf("\nUnescaped:\n");
    printf("%s\n", s);

    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    char c;

    i = j = 0;
    while ((c = s[i++]) != '\0')
    {
        switch (c)
        {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = c;
                break;
        }
    }
    t[j] = '\0';
    return;
}

void unescape(char t[], char s[])
{
    int i, j;
    char c;

    i = j = 0;
    while ((c = t[i++]) != '\0')
    {
        switch (c)
        {
            case '\\':
                c = t[i++];
                switch (c)
                {
                    case 't':
                        s[j++] = '\t';
                        break;
                    case 'n':
                        s[j++] = '\n';
                        break;
                    default:
                        s[j++] = '\0'; /* just terminate the string */
                }
                break;
            default:
                s[j++] = c;
                break;
        }
    }
    s[j] = '\0';
    return;
}