/* Author: pbollom
Date: 2020-05-02
Description:
1-20 Replaces tabs in the input with the proper number of spaces to the next tabstop. */  
#include<stdio.h>

#define TABSPACING 8    /* the number of spaces between tabstops */

int main()
{
    int c, i, nexttabstop; /* haven't learned the mod operator at this point, so we'll do it manually */

    nexttabstop = TABSPACING;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (i = 0; i < nexttabstop; ++i)
            {
                printf(" ");
            }
            nexttabstop = TABSPACING;
        }
        else
        {
            printf("%c", c);
            if (c == '\n' || nexttabstop == 1)
            {
                nexttabstop = TABSPACING;
            }
            else
            {
                --nexttabstop;
            }
            
        }
        
    }

    return 0;
}