/* Author: pbollom
Date: 2020-04-26
Description:
K&R 1-10 makes tab, backspace, and backslash visible */  
#include<stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("%c%c", '\\', 't');
        }
        else if (c == '\b')
        {
            printf("%c%c", '\\', 'b');
        }
        else if (c == '\\')
        {
            printf("%c%c", '\\', '\\');
        }
        else
        {
            printf("%c", c);
        }   
    }
}