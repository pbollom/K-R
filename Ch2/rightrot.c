/* Author: pbollom
Date: 2020-05-17
Description: 2-8 *** */
#include<stdio.h>

int rightrot(unsigned x, int n);

int main()
{
    printf("%d\n", rightrot(8, 2)); // 2
    printf("%d\n", rightrot(9, 1)); // 12
    printf("%d\n", rightrot(8, 0)); // 8
    printf("%d\n", rightrot(0, 1)); // 0
    printf("%d\n", rightrot(20, 6)); // 10

    return 0;
}

/* rotate the bits in x to the right by n places.
   this does handle the case where n is greater than the number of bits in x */
int rightrot(unsigned x, int n)
{
    if (x == 0 || n == 0)
    {
        return x;
    }

    int numdigits, product, digitmask;

    product = 1; /* a running product we'll use to figure out the number of bits required */
    numdigits = 0; /* the number of bits required for the input number */
    
    while (product < x)
    {
        product *= 2;
        numdigits++;
    }

    n %= numdigits; /* just in case n is greater than the number of bits, reduce it */

    digitmask = ~(~0 << numdigits);
    return (x >> n) | ((x << (numdigits - n)) & digitmask);
}