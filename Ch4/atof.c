/* Author: pbollom
Date: 2020-05-24
Description: 4-2 Convert a string to a floating point number, handling scientific notation exponents */
#include<stdio.h>
#include<ctype.h>

double atof(char s[]);

int main()
{
    printf("%f\n", atof("123"));
    printf("%f\n", atof("123.0"));
    printf("%f\n", atof("123.123"));
    printf("%f\n", atof("1.23e"));
    printf("%f\n", atof("1.23E3"));
    printf("%f\n", atof("1.23e-3"));
    printf("%f\n", atof("12.3e4"));
    printf("%f\n", atof("0e5"));
    printf("%f\n", atof("-123.123"));
    printf("%f\n", atof("-123.123e-3"));

    return 0;
}

double atof(char s[])
{
    double val, power, exponentmultiplier;
    int i, j, sign, exponentpower;

    /* delete leading whitespace */
    for (i = 0; isspace(s[i]); i++)
        ;
    
    /* cache the sign */
    sign = (s[i] == '-') ? -1 : 1;

    /* strip the optional sign */
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    /* get the digits to the left of the decimal point */
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    /* remove the decimal point */
    if (s[i] == '.')
    {
        i++;
    }

    /* get the digits to the left of the decimal point */
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    /* handle the scientific notation */
    if (tolower(s[i]) == 'e')
    {
        i++; /* remove the e */
        exponentmultiplier = (s[i] == '-') ? 0.1 : 10.0; /* what we'll multiply by to move the decimal */

        /* strip the optional sign */
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }

        /* parse off the number */
        for (exponentpower = 0; isdigit(s[i]); i++)
        {
            exponentpower = 10 * exponentpower + (s[i] - '0');
        }

        /* apply the decimal offset the correct number of places */
        for (j = 0; j < exponentpower; j++)
        {
            val *= exponentmultiplier;
        }
    }

    return sign * val / power;
}