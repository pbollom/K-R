/* Author: pbollom
Date: 2020-05-03
Description:
1-20 Replaces strings of blanks in the input with the minimum number of spaces or tabs
to achieve the same spacing. */  
#include<stdio.h>

#define TABSPACING 8    /* the number of spaces between tabstops */

int main()
{
    int c, i, nexttabstop, numblanks;

    nexttabstop = TABSPACING;
    numblanks = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (nexttabstop == 1)
            {
                if (numblanks == 0)
                {
                    printf("%c", ' ');
                }
                else /* some number greater than one space that started after the last tabstop */
                {
                    printf("%c", '\t');
                    numblanks = 0;
                }
            }
            else /* we might still have more blanks, and we want to merge multiple blanks into tab */
            {
                ++numblanks;
            }
            
        }
        else
        {
            for (i = 0; i < numblanks; ++i) /* didn't get to the tabstop, so fill in the missing spaces */
            {
                printf("%c", ' ');
            }
            numblanks = 0;
            printf("%c", c);
        }

        if (nexttabstop == 1 || c == '\n') /* don't forget to reset if we have a line break! */
        {
            nexttabstop = TABSPACING;
        }
        else
        {
            --nexttabstop;
        }
    }

    return 0;
}