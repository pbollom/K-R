/* Author: pbollom
Date: 2020-05-09
Description:
2-1 prints the ranges of char, short, int, long. both signed and unsigned */
#include<stdio.h>
#include<limits.h>

void unsignedChar();
void signedChar();
void unsignedShort();
void signedShort();
void unsignedInt();
void signedInt();
void unsignedLong();
void signedLong();

int main()
{
    unsignedChar();
    signedChar();

    unsignedShort();
    signedShort();

    unsignedInt();
    signedInt();

    unsignedLong();
    signedLong();

    return 0;
}

void unsignedChar()
{
    unsigned char maxC, minC;

    minC = 0;
    maxC = minC - 1;

    printf("\nunsigned char\n");

    printf("Computed - Min: %d\n", minC);
    printf("Computed - Max: %d\n", maxC);

    printf("limits.h - Min: %d\n", 0);
    printf("limits.h - Max: %d\n", UCHAR_MAX);
}

void signedChar()
{
    char c, maxC, minC;

    c = 1;
    while ((c = (c * 2)) > 0)
        ;
    minC = c;
    maxC = minC - 1;

    printf("\nsigned char\n");

    printf("Computed - Min: %d\n", minC);
    printf("Computed - Max: %d\n", maxC);

    printf("limits.h - Min: %d\n", SCHAR_MIN);
    printf("limits.h - Max: %d\n", SCHAR_MAX);
}

void unsignedShort()
{
    unsigned short maxS, minS;

    minS = 0;
    maxS = minS - 1;

    printf("\nunsigned short\n");

    printf("Computed - Min: %d\n", minS);
    printf("Computed - Max: %d\n", maxS);

    printf("limits.h - Min: %d\n", 0);
    printf("limits.h - Max: %d\n", USHRT_MAX);
}

void signedShort()
{
    short s, maxS, minS;

    s = 1;
    while ((s = (s * 2)) > 0)
        ;
    minS = s;
    maxS = minS - 1;

    printf("\nsigned short\n");

    printf("Computed - Min: %d\n", minS);
    printf("Computed - Max: %d\n", maxS);

    printf("limits.h - Min: %d\n", SHRT_MIN);
    printf("limits.h - Max: %d\n", SHRT_MAX);
}

void unsignedInt()
{
    unsigned int maxI, minI;

    minI = 0;
    maxI = minI - 1;

    printf("\nunsigned int\n");

    printf("Computed - Min: %u\n", minI);
    printf("Computed - Max: %u\n", maxI);

    printf("limits.h - Min: %u\n", 0);
    printf("limits.h - Max: %u\n", UINT_MAX);
}

void signedInt()
{
    int i, maxI, minI;

    i = 1;
    while ((i = (i * 2)) > 0)
        ;
    minI = i;
    maxI = i - 1;

    printf("\nsigned int\n");

    printf("Computed - Min: %d\n", minI);
    printf("Computed - Max: %d\n", maxI);

    printf("limits.h - Min: %d\n", INT_MIN);
    printf("limits.h - Max: %d\n", INT_MAX);
}

void unsignedLong()
{
    unsigned long minL, maxL;

    minL = 0;
    maxL = minL - 1;

    printf("\nunsigned long\n");

    printf("Computed - Min: %lu\n", minL);
    printf("Computed - Max: %lu\n", maxL);

    printf("limits.h - Min: %lu\n", 0l);
    printf("limits.h - Max: %lu\n", ULONG_MAX);
}

void signedLong()
{
    long l, maxL, minL;

    l = 1;
    while ((l = (l * 2)) > 0)
        ;
    minL = l;
    maxL = l - 1;

    printf("\nsigned long\n");

    printf("Computed - Min: %ld\n", minL);
    printf("Computed - Max: %ld\n", maxL);

    printf("limits.h - Min: %ld\n", LONG_MIN);
    printf("limits.h - Max: %ld\n", LONG_MAX);
}