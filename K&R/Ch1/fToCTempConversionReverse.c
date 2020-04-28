/* Author: pbollom
Date: 2020-04-26
Description:
K&R 1-5 Writes a table of temperature conversions from Fahrenheit to 
Celsius (reverse order) on the screen */  
#include<stdio.h>

#define  LOWER  0     /* lower limit on temperatures */
#define  UPPER  300   /* upper limit on temperatures */
#define  STEP   20    /* step size between temperatures */

int main()
{
    float fahr;

    printf("%5s %6s\n", "Deg F", "Deg C");

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    {
        printf("%5.0f %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}