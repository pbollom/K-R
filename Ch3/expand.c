/* Author: pbollom
Date: 2020-05-22
Description: 3-3 Expands sequences like a-d into abcd. Handles upper and lowercase
             letters as well as digits, converting all letters to lowercase.
             Doesn't handle "multiple expansion", where you might input a-d-f and
             expect that to be abcdef. Instead, you will get abcd-f. */
#include<stdio.h>
#include<ctype.h>

#define MAXINPUT    99 /* maximum length of the input */

void expand(char s[], char t[]);

int main()
{
    int i;
    char c;
    char s[MAXINPUT + 1];
    char t[MAXINPUT / 3 * 26 + 1];

    i = 0;
    while ((c = getchar()) != EOF && c != '\0' && i < MAXINPUT)
    {
        s[i++] = c;
    }
    s[i] = '\0';

    printf("Input: %s\n", s);
    expand(s, t);
    printf("Output: %s\n", t);

    return 0;
}

void expand(char s[], char t[])
{
    int i, j;
    char c, d;

    i = j = 0;
    while ((c = s[i++]) != '\0')
    {
        /* current character is alphanumeric, next character is hyphen
           then, validate that the current and two to the right are both alpha or both numeric  */
        if (isalnum(c) && s[i] == '-' &&
                ((isalpha(c) && isalpha(s[i+1])) || (isnumber(c) && isnumber(s[i+1]))) &&
                s[i+1] > c)
        {
            for (d = tolower(c); d <= tolower(s[i + 1]); d++)
            {
                t[j++] = d;
            }
            i += 2;
        }
        else /* otherwise, just print the character */
        {
            t[j++] = c;
        }
    }
    t[j] = '\0';
}