/* Author: pbollom
Date: 2020-05-31
Description: 4-12 Convert an integer to a string by calling a recursive routine
             4-13 A recursive version of string reversal */
#include<stdio.h>
#include<limits.h>

#define MAXLEN  12 /* length of MIN_INT as string, plus one */

void storechar(int n, char s[]);

int main()
{
    char s[MAXLEN];

    storechar(0, s);
    printf("%s\n", s);

    storechar(1, s);
    printf("%s\n", s);

    storechar(12, s);
    printf("%s\n", s);

    storechar(123, s);
    printf("%s\n", s);

    storechar(-123, s);
    printf("%s\n", s);

    storechar(1234, s);
    printf("%s\n", s);

    storechar(INT_MIN, s);
    printf("%s\n", s);

    storechar(INT_MAX, s);
    printf("%s\n", s);

    return 0;
}

int storecharint(unsigned int, int, char[]);
void reverse(char[], int);

/* storechar: stores int n as a string in s. handles minimum integer value */
void storechar(int n, char s[])
{
    int maxindex;

    if (n < 0)
    {
        unsigned int nmagnitude = 0 - n;
        maxindex = storecharint(nmagnitude, 0, s);
        s[++maxindex] = '-';
    }
    else
    {
        maxindex = storecharint(n, 0, s);
    }
    s[++maxindex] = '\0';
    reverse(s, maxindex);
}

/* storecharint: recursive function to store an integer in reverse order in s.
        returns the maximum filled index of the character string */
int storecharint(unsigned int n, int i, char s[])
{
    int maxindex = i;
    if (n / 10)
    {
        maxindex = storecharint(n / 10, i + 1, s);
    }
    s[i] = (n % 10 + '0');
    return maxindex;
}

void reverseint(char[], int, int);

/* reverse: reverses the characters in a string s of length n */
void reverse(char s[], int n)
{
    /* need to offset n by 1 prior to dividing; otherwise, even numbers will flip the center numbers twice */
    reverseint(s, (n - 1) / 2, n);
}

/* reverseint: recursive function to flip two characters at i and n-i-1 */
void reverseint(char s[], int i, int n)
{
    char c;

    if (i > 0)
    {
        reverseint(s, i - 1, n);
    }

    c = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = c;
}