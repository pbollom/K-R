/* Author: pbollom
Date: 2020-04-26
Description:
K&R 1-4 Writes a table of temperature conversions from Celsius to Fahrenheit on the screen */  
#include<stdio.h>

int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%5s %6s\n", "Deg C", "Deg F");

    celsius = lower;
    while (celsius <= upper) /* Print Fahrenheit-Celsius conversion table for 0, 20, 40, ... 300 */
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%5.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}