/* Author: pbollom
Date: 2020-05-18
Description: 2-9 Count the number of one bits in an integer argument, two ways */
#include<stdio.h>
#include<time.h>

int bitcount1(unsigned x);
int bitcount2(unsigned x);

/* Computes a few bitcounts using the two separate algorithms, comparing the CPU time of each */
int main()
{
    clock_t tic = clock();

    printf("%d\n", bitcount1(1));
    printf("%d\n", bitcount1(10));
    printf("%d\n", bitcount1(100));
    printf("%d\n", bitcount1(1000));
    printf("%d\n", bitcount1(10000));
    printf("%d\n", bitcount1(100000));
    printf("%d\n", bitcount1(1000000));

    clock_t toc = clock();
    double time = (double)(toc - tic) / CLOCKS_PER_SEC;

    printf("\nbitcount1: %g\n\n", time);

    tic = clock();

    printf("%d\n", bitcount2(1));
    printf("%d\n", bitcount2(10));
    printf("%d\n", bitcount2(100));
    printf("%d\n", bitcount2(1000));
    printf("%d\n", bitcount2(10000));
    printf("%d\n", bitcount2(100000));
    printf("%d\n", bitcount2(1000000));

    toc = clock();
    time = (double)(toc - tic) / CLOCKS_PER_SEC;

    printf("\nbitcount2: %g\n\n", time);
}

/* The original implementation of bitcount */
int bitcount1(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }

    return b;
}

/* The faster version of bitcount, observing that for a two's complement system
   x &= (x-1) will always remove the rightmost one bit, as x - 1 will always replace
   the rightmost right bit with a zero and change everything further to the right to 
   a one. Then, bitwise-ANDing those two numbers will change everything at or to the 
   right of that rightmost one to zero. */
int bitcount2(unsigned x)
{
   int b;
   
   b = 0;
   while (x != 0)
   {
       x &= (x - 1);
       b++;
   }
   
    return b;
}