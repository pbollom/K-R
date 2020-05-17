/* Author: pbollom
Date: 2020-05-17
Description: 2-6 Returns x with the n bits that begin at position p set to
             set to the n rightmost bits of y, leaving the other bits unchanged */
#include<stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    printf("%d\n", setbits(15,2,2,14)); // 13
    printf("%d\n", setbits(8,2,2,8)); // 8
    printf("%d\n", setbits(1,4,2,14)); // 17
    return 0;
}

/* returns x with the n bits that begin at position p set to the n rightmost bits of y 
   this does not have any checks for reasonable bounds on p or n */
int setbits(unsigned x, int p, int n, unsigned y)
{
    /* this gives us the rightmost n bits from y, shifted to the position where
       we want to replace the bits from x */
    unsigned ymask = (y & ~(~0 << n)) << (p + 1 - n);

    /* this gives us x with the n bits starting at position p set to zero */
    unsigned xmask = x & ~((~(~0 << n)) << (p + 1 - n));

    return ymask | xmask;
}