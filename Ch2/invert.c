/* Author: pbollom
Date: 2020-05-17
Description: 2-7 Inverts n bits in x starting at position p (zero-based) */
#include<stdio.h>

int invert(unsigned x, int p, int n);

int main()
{
    printf("%d\n", invert(15,2,2)); // 9
    printf("%d\n", invert(9,2,1)); // 13
    printf("%d\n", invert(24,4,5)); // 7

    return 0;
}

/* Inverts n bits in x starting at position p (zero-indexed)
   Similar to other examples, does not do any error checking on inputs. */
int invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}