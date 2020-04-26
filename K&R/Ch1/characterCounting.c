/* Author: Patrick Bollom
Date: 2020-04-26
Description:
Counts characters in input */  
#include<stdio.h>

int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }
    printf("%ld\n", nc);
}