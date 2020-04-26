/* Author: Patrick Bollom
Date: 2020-04-26
Description:
K&R 1-3 Writes a table of temperature conversions from Fahrenheit to Celsius on the screen */  
#include<stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%5s %6s\n", "Deg F", "Deg C");

    fahr = lower;
    while (fahr <= upper) /* Print Fahrenheit-Celsius conversion table for 0, 20, 40, ... 300 */
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%5.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}