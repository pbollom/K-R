/* Author: pbollom
Date: 2020-06-05
Description: 5-2 get the next flating point number from the input into *pn */
#include<stdio.h>
#include<ctype.h>

int getfloat(double *);
int getch(void);

/* write integers to the output. quits on EOF. once you have broken out of the integer parsing,
this will just mirror the input in the output (for testing pushing back the non-integer input) */
int main()
{
    int c;
    double f;

    while ((c = getfloat(&f)) != EOF && c != 0)
    {
        printf("%g\n", f);
    }

    while ((c = getch()) != EOF)
    {
        printf("%c", c);
    }

    return 0;
}

void ungetch(int);

/* getfloat: get next floating point number from input into *pn */
int getfloat(double *pn)
{
    int c, sign;
    double power;

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
    }

    /* left of the decimal place */
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }

    if (c == '.')
    {
        c = getch();
    }

    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10.0;
    }

    *pn = sign * *pn / power;
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