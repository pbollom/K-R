/* Author: pbollom
Date: 2020-04-28
Description:
Prints a horizontal histogram of word lengths in an input */  
#include<stdio.h>

#define IN          1  /* inside a word */
#define OUT         0  /* outside a word */
#define MAXLENGTH   9 /* maximum discretely handled length */

int main()
{
    int i, j, c, state, wordLength;
    int nlength[MAXLENGTH + 1];

    wordLength = 0;
    for (i = 0; i < MAXLENGTH + 1; ++i)
    {
        nlength[i] = 0;
    }

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (state == IN)
            {
                state = OUT;

                if (wordLength > MAXLENGTH) /* We handle word lengths up to 9, after that it's a single bucket */
                {
                    ++nlength[MAXLENGTH];
                }
                else
                {
                    ++nlength[wordLength - 1];
                }

                wordLength = 0;
            }
        }
        else
        {
            if (state == OUT)
            {
                state = IN;
            }
            ++wordLength;
        }
    }

    /* actually do the printing of the histogram - note that this does not do any scaling right now,
       so things could run over to the next line... */
    for (i = 0; i < MAXLENGTH; ++i)
    {
        printf("%c  :", '1' + i);
        for (j = 0; j < nlength[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("10+:");
    for (j = 0; j < nlength[MAXLENGTH]; ++j)
    {
        printf("*");
    }
    printf("\n");
}