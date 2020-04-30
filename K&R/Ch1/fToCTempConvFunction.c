/* Author: pbollom
Date: 2020-04-30
Description:
K&R 1-15 Prints a table of temperature conversions */  
#include<stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

float convertOneTemp(float fahr);

int main()
{
    float fahr;
    
    printf("%5s %6s\n", "Deg F", "Deg C");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%5.0f %6.1f\n", fahr, convertOneTemp(fahr));
    }

    return 0;
}

/* Converts a single temperature from fahrenheit to celsius */
float convertOneTemp(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}