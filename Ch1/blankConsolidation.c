/* Author: pbollom
Date: 2020-04-26
Description:
K&R 1-9 Consolidates multiple blanks into a single blank */  
#include<stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            while ((c = getchar()) == ' ')
            {
                ;
            }
            printf("%c", ' ');
        }
        if (c != EOF) /* because there is a getchar outside of the main loop, we need to check this here */
        {
            printf("%c", c);
        }
    }
}