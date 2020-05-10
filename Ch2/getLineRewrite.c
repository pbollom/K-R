/* Author: pbollom
Date: 2020-05-10
Description:
2-2 rewrite of the getline function from ch1, without && or || 
    if a line is longer than the maximum, then we will line break
    automatically and then keep printing the rest of the line. */
#include<stdio.h>

#define DONE    1 /* flag to indicate that a loop should end */
#define MAXLINE 1000 /* maximum line length */

int gtline(char line[], int maxline);

int main()
{
    char line[MAXLINE];     /* current input line */

    while (gtline(line, MAXLINE) > 0)
    {
        printf("%s\n", line);
    }

    return 0;
}

int gtline(char s[], int lim)
{
    int c, i, state;
    i = state = 0;

    while (state != DONE)
    {
        if (i < lim - 1)
        {
            if ((c = getchar()) != EOF)
            {
                if (c != '\n')
                {
                    s[i] = c;
                    ++i;
                }
                else
                {
                    state = DONE;
                }
                
            }
            else
            {
                state = DONE;
            }
            
        }
        else
        {
            state = DONE;
        }
        
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}