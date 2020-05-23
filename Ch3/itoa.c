/* Author: pbollom
Date: 2020-05-23
Description: 3-4 Converts an integer to a character sequence.
             The original in the book did not work for a two's complement machine as the 
             minimum value is one greater in magnitude than the maximum value, so taking the 
             negative will give the incorrect result. */
#include<stdio.h>
#include<limits.h>

#define MAXLEN  21 /* maximum length of the string. 2^64 has 20 digits, which should be longer than our input */

void printtest(int n);
void itoa(int n, char s[]);
void reverse(char s[], int n);

int main()
{
    printtest(0);
    printtest(-0);
    printtest(12345);
    printtest(-12345);
    printtest(INT_MAX);
    printtest(INT_MIN);

    return 0;
}

/* simple wrapper so that main can just test with a single integer without needing to worry about 
   the string or the printing */
void printtest(int n)
{
    char s[MAXLEN];
    
    itoa(n, s);
    printf("%s\n", s);

    return;
}

/* converts an integer n to a string s */
void itoa(int n, char s[])
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