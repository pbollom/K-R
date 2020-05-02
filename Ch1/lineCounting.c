/* Author: pbollom
Date: 2020-04-26
Description:
Counts newlines in input */  
#include<stdio.h>

int main()
{
    int c;
    long nl;

    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }

    printf("%ld\n", nl);
}