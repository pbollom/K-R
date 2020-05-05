/* Author: pbollom
Date: 2020-05-05
Description:
1-23 Strips comments from the input C program */  
#include<stdio.h>

#define OUT         0
#define INMLCOMMENT 1
#define INSLCOMMENT 2
#define INSTRING    3

int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (state == OUT)
        {
            if (c == '"')
            {
                printf("%c", c);
                state = INSTRING;
            }
            else if (c == '/')
            {
                c = getchar(); /* safe to do, since EOF needs to follow a \n */
                if (c == '*')
                {
                    state = INMLCOMMENT;
                    /* don't print, since we are stripping comments */
                }
                else if (c == '/')
                {
                    state = INSLCOMMENT;
                    /* don't print, since we are stripping comments */
                }
                else
                {
                    printf("%c%c", '/', c); /* print both characters, since it wasn't a comment start */
                }
            }
            else
            {
                printf("%c", c);
            }
        }
        else if (state == INSTRING)
        {
            printf("%c", c);
            if (c == '"')
            {
                state = OUT;
            }
        }
        else if (state == INMLCOMMENT)
        {
            if (c == '*')
            {
                c = getchar(); /* safe to do, since EOF needs to follow a \n */
                if (c == '/')
                {
                    state = OUT;
                    /* don't print, since we are stripping comments */
                }
            }
            /* don't print, since we are stripping comments */
        }
        else if (state == INSLCOMMENT)
        {
            if (c == '\n')
            {
                printf("%c", c); /* make sure to print the line break */
                state = OUT;
            }
            /* don't print, since we are stripping comments */
        }
    }

    return 0;
}