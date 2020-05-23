/* Author: pbollom
Date: 2020-05-23
Description: 3-6 Converts an integer to a character sequence in base 10.
             Supports padding to a minimum length. */
#include<stdio.h>
#include<limits.h>

#define MAXLEN  21 /* maximum length of the string. 2^64 has 20 digits, which should be longer than our input */

void printtest(int n, int w);
void itoa(int n, char s[], int w);
void reverse(char s[], int n);

int main()
{
    printtest(0, 16);
    printtest(-0, 16);
    printtest(12345, 16);
    printtest(-12345, 16);
    printtest(INT_MAX, 16);
    printtest(INT_MIN, 16);

    return 0;
}

/* simple wrapper so that main can just test with a single integer without needing to worry about 
   the string or the printing */
void printtest(int n, int w)
{
    char s[MAXLEN];
    
    itoa(n, s, w);
    printf("%s\n", s);

    return;
}

/* converts an integer n to a string s, padded to a minimum length of w on the left */
void itoa(int n, char s[], int w)
{
    int i, sign, digit;

    sign = n < 0;
    i = 0;
    do
    {
        digit = n % 10; /* this could be negative, if the original number was negative */
        if (digit < 0)  /* is there a better way than checking this with each iteration? */
        {
            digit = -digit; /* if it is negative, flip the digit */
        }
        s[i++] = digit + '0';
    } while ((n /= 10) != 0);
    if (sign)
    {
        s[i++] = '-';
    }
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s, i);
}

/* reverses the characters in a string s of length n */
void reverse(char s[], int n)
{
    char c;
    int i;

    for (i = 0; i < n / 2; i++)
    {
        c = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = c;
    }

    return;
}