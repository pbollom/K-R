/* Author: pbollom
Date: 2020-05-24
Description: A reverse polish calculator
             Some commands:
                +: add
                -: substract
                *: multiply
                /: divide
                %: modulous
                ?: peek the top value of the stack
                ~: clear the current stack of values
                ": duplicate the top value of the stack
                ;: flip the top two values on the stack 
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100 /* maximum size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void clear(void);

int main()
{
    int type;
    double op2, op3;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                {
                    push(pop() / op2);
                }
                else
                {
                    printf("error: zero divisor\n");
                }
                break;
            case '%': /* will need to convert both operands to integers, potentially losing information */
                op2 = pop();
                if ((int)op2 != 0)
                {
                    push((int)pop() % (int)op2);
                }
                else
                {
                    printf("error: zero modulo divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case '?':
                printf("\t%.8g\n", peek());
                break;
            case '~':
                clear();
                break;
            case '"':
                push(peek());
                break;
            case ';':
                op2 = pop();
                op3 = pop();
                push(op2);
                push(op3);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto the value stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop()
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: return the top value from the stack without removing it */
double peek()
{
    if (sp > 0)
    {
        return val[sp - 1];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }   
}

/* clear: reset the stack */
void clear()
{
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get the next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    /* strip off the leading whitespace and optional plus sign */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c; /* not a number */
    }

    i = 0;
    if (isdigit(c) || c == '-') /* integer part */
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    if (i == 1 && s[0] == '-') /* special case, we really just read a minus sign */
    {
        return '-';
    }

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
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