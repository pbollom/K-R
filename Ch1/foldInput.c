/* Author: pbollom
Date: 2020-05-04
Description:
1-22 Folds the input into strings of at most length FOLDLENGTH 
Right now this is incorrect because it doesn't handle non-space blanks
and it doesn't fold after the last non-blank character - it just folds on 
the blank. Also, the input length is locked to one too small right now. */  
#include<stdio.h>

#define FOLDLENGTH  10  /* the maximum linebreak spacing */

int main()
{
    int c, i, lastspace, j;
    char str[FOLDLENGTH + 1]; /* need one extra character at the end for null terminating */

    i = -1;
    lastspace = -1;
    while ((c = getchar()) != EOF)
    {
        ++i;
        str[i] = c;

        if (c == '\n') /* special case or manually entered newline */
        {
            str[i+1] = '\0';
            printf("%s", str);
            lastspace = -1;
            i = -1;
        }
        else 
        {
            if (c == ' ')
            {
                lastspace = i;
            } 
        }
        
        if (i == (FOLDLENGTH - 1)) /* hit the cap, so print out what we have */
        {
            if (lastspace == -1) /* special case, no spaces */
            {
                str[FOLDLENGTH] = '\0';
                printf("%s\n", str);
                i = -1;
                lastspace = -1;
            }
            else /* replace the last space with a null */
            {
                str[lastspace] = '\0';
                printf("%s\n", str);
                
                for (j = 0; j < FOLDLENGTH - lastspace; ++j)
                {
                    str[j] = str[lastspace + j + 1];
                }

                i = FOLDLENGTH - lastspace - 2;
                lastspace = -1;
            }
        }
    }
}