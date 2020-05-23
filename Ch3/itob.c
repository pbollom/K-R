/* Author: pbollom
Date: 2020-05-23
Description: 3-5 Converts an integer to a character sequence in a given base. */
#include<stdio.h>
#include<limits.h>

#define MAXLEN  65 /* maximum length of the string, assuming 64 bits, with a base of 2 */

void printtest(int n, int b);
void itob(int n, char s[], int b);
void reverse(char s[], int n);

int main()
{
    printtest(0, 8);
    printtest(-0, 8);
    printtest(12345, 8);
    printtest(-12345, 8);
    printtest(INT_MAX, 8);
    printtest(INT_MIN, 8);

    return 0;
}

/* simple wrapper so that main can just test with a single integer without needing to worry about 
   the string or the printing */
void printtest(int n, int b)
{
    char s[MAXLEN];
    
    itob(n, s, b);
    printf("%s\n", s);

    return;
}

/* converts an integer n to a string s with given base b */
void itob(int n, char s[], int b)
{
    int i, sign, digit;

    if (b < 2 || b > 36) /* basic error checking on the base */
    {
        s[0] = '\0';
        return;
    }

    sign = n < 0;
    i = 0;
    do
    {
        digit = n % b; /* this could be negative, if the original number was negative */
        if (digit < 0)  /* is there a better way than checking this with each iteration? */
        {
            digit = -digit; /* if it is negative, flip the digit */
        }
        if (digit < 10)
        {
            s[i++] = digit + '0';
        }
        else
        {
            s[i++] = digit - 10 + 'a';
        }     
    } while ((n /= b) != 0);
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