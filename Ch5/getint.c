/* Author: pbollom
Date: 2020-06-03
Description: 5-1 get the next integer from the input into *pn */
#include<stdio.h>
#include<ctype.h>

int getint(int *);
int getch(void);

/* write integers to the output. quits on EOF. once you have broken out of the integer parsing,
this will just mirror the input in the output (for testing pushing back the non-integer input) */
int main()
{
    int i, c;

    while ((c = getint(&i)) != EOF && c != 0)
    {
        printf("%d\n", i);
    }

    while ((c = getch()) != EOF)
    {
        printf("%c", c);
    }

    return 0;
}

void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

#define BUFSIZE 100

int buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* getch: get a (possibility pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters");
    }
    else
    {
        buf[bufp++] = c;
    }
}