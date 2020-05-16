/* Author: pbollom
Date: 2020-05-16
Description: 2-3 Convert a hexadecimal string to an integer */
#include<stdio.h>

#define NOTDONE 0
#define DONE    1

int htoi(char s[]);

int main()
{
    printf("a:     %d\n", htoi("a")); // 10
    printf("0xa:   %d\n", htoi("0xa")); // 10
    printf("0Xa:   %d\n", htoi("0Xa")); // 10
    printf("A:     %d\n", htoi("A")); // 10
    printf("0xa1F: %d\n", htoi("0xa1F")); // 2591
    printf("G:     %d\n", htoi("G")); // 0
    printf("g:     %d\n", htoi("0xg")); // 0

    return 0;
}

/* A naive implementation of htoi, assuming consecutive characters
   in the machine's character set */
int htoi(char s[])
{
    int i, n, state;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }
    else
    {
        i = 0;
    }
    
    n = 0;
    state = NOTDONE;
    while (state != DONE)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n = 16 * n + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            n = 16 * n + (s[i] - 'a' + 10);
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            n = 16 * n + (s[i] - 'A' + 10);
        }
        else
        {
            state = DONE;
        }

        ++i;
    }

    return n;
}