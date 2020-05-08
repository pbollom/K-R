/* Author: pbollom
Date: 2020-05-05
Description:
1-24 A very rudimentary C syntax checker. Not my best code, but 
     it works well for some basic checks. */  
#include<stdio.h>

#define OUT         0
#define INMLCOMMENT 1
#define INSLCOMMENT 2
#define INSTRING    3

#define MAXNESTING  100

#define NOERROR     0
#define ERROR       1

int main()
{
    int c, state, errorstate, i, countnesting;
    char nesting[MAXNESTING];

    state = OUT;
    errorstate = NOERROR;
    countnesting = 0;
    while (errorstate == NOERROR && (c = getchar()) != EOF)
    {
        if (state == OUT && c == '/') /* potential start of comment */
        {
            /* grab the next character. we know that this will either indicate that
               we're entering a comment, or we can ignore the '/' character */
            c = getchar();
            if (c == '*')
            {
                state = INMLCOMMENT;
                c = getchar();
            }
            else if (c == '/')
            {
                state = INSLCOMMENT;
                c = getchar();
            }
            else
            {
                /* it wasn't a comment start, this will fall through to the other state == OUT block */
            }
        }
        
        if (state == OUT && c == '\'') /* start of character literal */
        {
            c = getchar();
            if (c == '\\') /* escaped, so we need one additional character */
            {
                c = getchar();
            }
            if ((c = getchar()) != '\'')
            {
                printf("Invalid character literal\n");
                errorstate = ERROR;
            }
        }
        
        if (errorstate == NOERROR)
        {
            if (state == OUT)
            {
                if (c == '"')
                {
                    state = INSTRING;
                }
                else if (c == '[' || c == '{' || c == '(')
                {
                    nesting[countnesting] = c;
                    ++countnesting;
                }
                else if (c == ']' || c == '}' || c == ')')
                {
                    if (c == ']' && nesting[countnesting - 1] != '[')
                    {
                        printf("Mismatched closing bracket\n");
                        errorstate = ERROR;
                    }
                    else if (c == '}' && nesting[countnesting - 1] != '{')
                    {
                        printf("Mismatched closing brace\n");
                        errorstate = ERROR;
                    }
                    else if (c == ')' && nesting[countnesting - 1] != '(')
                    {
                        printf("Mismatched closing parenthesis\n");
                        errorstate = ERROR;
                    }
                    else
                    {
                        --countnesting;
                    }
                }
            }
            else if (state == INSTRING)
            {
                if (c == '"')
                {
                    state = OUT;
                }
            }
            else if (state == INMLCOMMENT)
            {
                if (c == '*')
                {
                    c = getchar();
                    if (c == '/')
                    {
                        state = OUT;
                    }
                    /* still in the comment, so ignore */
                }
                /* still in the comment, so ignore */
            }
            else if (state == INSLCOMMENT)
            {
                if (c == '\n') /* everything until the end of line is a comment */
                {
                    state = OUT;
                }
                /* still in the comment, so ignore */
            }
        }
    }

    /* only check for final errors if we haven't already printed one 
       there could be multiple of these errors */
    if (errorstate == NOERROR)
    {
        if (countnesting > 0)
        {
            printf("More opening grouping characters than closing grouping characters\n");
        }
        
        if (state == INSTRING)
        {
            printf("Non-closed string literal\n");
        }

        if (state == INMLCOMMENT)
        {
            printf("Non-closed multi-line comment\n");
        }
    }
    
    return 0;
}