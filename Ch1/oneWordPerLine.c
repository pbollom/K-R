/* Author: pbollom
Date: 2020-04-27
Description:
K&R 1-12 write the input with one word per line */
#include<stdio.h>

#define IN  1  /* inside a word */
#define OUT 0  /* outside a word */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
        {
            nl++;
        }
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (state == IN) /* only add a new line if we were in a word */
            {
                printf("%c", '\n');
            }
            state = OUT;
        }
        else 
        {
            printf("%c", c);
            if (state == OUT)
            {
                state = IN;
                ++nw;
            }
        }
    }
}