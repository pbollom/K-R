/* Author: pbollom
Date: 2020-05-31
Description: A reverse polish calculator
             Some (case-sensitive) commands:
                +: add
                -: substract
                *: multiply
                /: divide
                %: modulous
                peek: peek the top value of the stack
                clear: clear the current stack of values
                dup: duplicate the top value of the stack
                flip: flip the top two values on the stack 
                sin: sine
                cos: cosine
                tan: tanangent
                pow: x^y
                exp: e^x
                sqrt: square root
             It is also possible to cache up to 26 variables using the x= command, where 'x'
             is the variable you want to cache. For example, 3.14 p= will set the value of 'p'
             to 3.14, such that future uses of p will use the numeric value 3.14. IMPORTANTLY, 
             replacing the variable with the value is done when we see the variable, not when
             we're doing the computation, so the value only applies to the variable when it is
             used after the set.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP   100 /* maximum size of operand or operator */
#define VARCOUNT 'z' - 'a' + 1 /* maximum number of variables */
#define NUMBER  '0' /* signal that a number was found */
#define DUP     EOF > 0 ? EOF + 1 : EOF - 1
#define PEEK    EOF > 0 ? EOF + 2 : EOF - 2
#define CLEAR   EOF > 0 ? EOF + 3 : EOF - 3
#define FLIP    EOF > 0 ? EOF + 4 : EOF - 4
#define SIN     EOF > 0 ? EOF + 5 : EOF - 5
#define COS     EOF > 0 ? EOF + 6 : EOF - 6
#define TAN     EOF > 0 ? EOF + 7 : EOF - 7
#define POW     EOF > 0 ? EOF + 8 : EOF - 8
#define EXP     EOF > 0 ? EOF + 9 : EOF - 9
#define SQRT    EOF > 0 ? EOF + 10 : EOF - 10
#define SET     EOF > 0 ? EOF + 11 : EOF - 11
#define VAR     EOF > 0 ? EOF + 12 : EOF - 12

int getop(char[]);
void push(double);
double pop(void);
double peek(void);
void clear(void);
void setvar(char, double);
double getvar(char);

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
            case VAR:
                push(getvar(s[0]));
                break;
            case SET:
                setvar(s[0], pop());
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
            case PEEK:
                printf("\t%.8g\n", peek());
                break;
            case CLEAR:
                clear();
                break;
            case DUP:
                push(peek());
                break;
            case FLIP:
                op2 = pop();
                op3 = pop();
                push(op2);
                push(op3);
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case TAN:
                push(tan(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case SQRT:
                push(sqrt(pop()));
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

int ismulticharacterop(char op[], int n);
int getch(void);
void ungetch(int);

/* getop: get the next operator or numeric operand */
int getop(char s[])
{
    int i, c, c2;

    /* strip off the leading whitespace and optional plus sign */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        if (c >= 'a' && c <= 'z')
        {
            c2 = getch();
            if (c2 == '=')
            {
                return SET;
            }
            else
            {
                if (c2 == ' ')
                {
                    return VAR;
                }
                ungetch(c2);
            }
        }

        ungetch(c);

        if (ismulticharacterop("peek", 4))
        {
            return PEEK;
        }

        if (ismulticharacterop("clear", 5))
        {
            return CLEAR;
        }

        if (ismulticharacterop("dup", 3))
        {
            return DUP;
        }

        if (ismulticharacterop("flip", 4))
        {
            return FLIP;
        }

        if (ismulticharacterop("sin", 3))
        {
            return SIN;
        }

        if (ismulticharacterop("cos", 3))
        {
            return COS;
        }

        if (ismulticharacterop("tan", 3))
        {
            return TAN;
        }

        if (ismulticharacterop("pow", 3))
        {
            return POW;
        }

        if (ismulticharacterop("exp", 3))
        {
            return EXP;
        }

        if (ismulticharacterop("sqrt", 4))
        {
            return SQRT;
        }
        
        getch();  /* what we want is already stored in c */
        return c; /* not a number or a special non-number operator */
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

/* ismulticharacterop: checks whether the input operator is a specific multi-character string
                       ensures the input is back in the buffer if it does not match */
int ismulticharacterop(char op[], int oplength)
{
    int i, c, done;

    i = 0;
    while (i < oplength)
    {
        if ((c = getch()) != op[i])
        {
            ungetch(c);
            i--;
            while (i >= 0)
            {
                ungetch(op[i--]);
            }
            return 0;
        }
        i++;
    }
    return 1;
}

int varindex(char);

double variables[VARCOUNT];
int variablesset[VARCOUNT];

/* setvar: caches the value of a specific single lowercase variable */
void setvar(char var, double val)
{
    int index;
    if ((index = varindex(var)) == -1)
    {
        printf("error: variable must be between 'a' and 'z'\n");
    }
    else
    {
        index = var - 'a';
        variables[index] = val;
        variablesset[index] = 1;
    }
}

/* getvar: gets the value of a specific single lowercase variable */
double getvar(char var)
{
    int index;
    if ((index = varindex(var)) == -1 || !variablesset[index])
    {
        printf("error: unknown variable\n");
        return 0.0;
    }
    else
    {
        return variables[index];
    } 
}

/* varindex: gets the index of a specific variable in the variable cache, 
or returns -1 if the variable is not in the cache */
int varindex(char var)
{
    if (var > 'z' || var < 'a')
    {
        return -1;
    }

    return var - 'a';
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