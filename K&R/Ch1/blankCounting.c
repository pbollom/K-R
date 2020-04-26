/* Author: Patrick Bollom
Date: 2020-04-26
Description:
K&R 1-8 Counts blanks, tabs, and newlines in input */  
#include<stdio.h>

int main()
{
    int c;
    long blankCount;

    blankCount = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            ++blankCount;
        }
    }

    printf("%ld\n", blankCount);
}