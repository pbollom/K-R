/* Author: pbollom
Date: 2020-05-04
Description:
1-22 Folds the input into strings of at most length FOLDLENGTH */  
#include<stdio.h>

#define FOLDLENGTH  10  /* the maximum linebreak spacing */

int main()
{
    int c, charindex, lastblank, i;
    char str[FOLDLENGTH];

    charindex = -1;
    lastblank = FOLDLENGTH - 1;
    while ((c = getchar()) != EOF)
    {
        ++charindex;
        str[charindex] = c;

        if (c == '\n') /* special case or manually entered newline */
        {
            str[charindex+1] = '\0';
            printf("%s", str);
            lastblank = FOLDLENGTH - 1;
            charindex = -1;
        }
        else if (c == ' ' || c == '\t')
        {
            lastblank = charindex;
        }
        
        if (charindex == (FOLDLENGTH - 1)) /* hit the cap, so print out what we have */
        {
            /* this is where defaulting lastblank to FOLDLENGTH pays off - no conditional! */
            str[lastblank] = '\0';
            printf("%s\n", str);
                
            for (i = 0; i < FOLDLENGTH - lastblank; ++i)
            {
                str[i] = str[lastblank + i + 1];
            }

            charindex = FOLDLENGTH - lastblank - 2; /* increment charindex first in the loop, need on extra offset */
            lastblank = FOLDLENGTH - 1;
        }
    }
}