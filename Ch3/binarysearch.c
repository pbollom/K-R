/* Author: pbollom
Date: 2020-05-20
Description: 3-1 Compares the performance of two separate implementations of binary search.
             The original has a better average case when the elements are in the array.
             The new has a better worse case when the element is not in the array. */
#include<stdio.h>
#include<time.h>

#define ARRAYLENGTH 100000 /* the number of elements we'll put in the array */

int binsearch1(int x, int v[], int n); /* the algorithm from the book */
int binsearch2(int x, int v[], int n); /* our implementation with the checks moved */

int main()
{
    int i, x, n;
    int v[ARRAYLENGTH];

    /* initialize the array with the value equal to the index */
    for (i = 0; i < ARRAYLENGTH; i++)
    {
        v[i] = i;
    }

    clock_t tic = clock();

    /* find each value */
    for (x = 0; x < ARRAYLENGTH; x++)
    {
        /* we don't care about the value, so we won't print it */
        binsearch1(x, v, ARRAYLENGTH);
    }

    clock_t toc = clock();
    double time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\nbinsearch1 finding all values: %g\n\n", time);

    tic = clock();

    /* try finding something outside of the array, 1000 times */
    for (i = 0; i < 1000; i++)
    {
        /* we don't care about the value, so we won't print it */
        binsearch1(ARRAYLENGTH, v, ARRAYLENGTH);
    }

    toc = clock();
    time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\nbinsearch1 with missing value 10 times: %g\n\n", time);

    tic = clock();

    /* find each value */
    for (x = 0; x <= ARRAYLENGTH; x++)
    {
        /* we don't care about the value, so we won't print it */
        binsearch2(x, v, ARRAYLENGTH);
    }

    toc = clock();
    time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\nbinsearch2 finding all values: %g\n\n", time);

    tic = clock();

    /* try finding something outside of the array, 1000 times */
    for (i = 0; i < 1000; i++)
    {
        /* we don't care about the value, so we won't print it */
        binsearch2(ARRAYLENGTH, v, ARRAYLENGTH);
    }

    toc = clock();
    time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\nbinsearch2 with missing value 1000 times: %g\n\n", time);

    tic = clock();

    return 0;
}

int binsearch1(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
        
    }

    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (x <= v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        } 
    }
    return (x == v[low]) ? low : -1;
}