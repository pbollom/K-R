/* Author: pbollom
Date: 2020-06-13
Description: strcpy, both array and pointer versions */
#include<stdio.h>

void strcpyary(char *, char *);
void strcpyptr(char *, char *);

int main()
{
    char *s;

    strcpyary(s, "Hello, world, array");
    printf("Array: %s\n", s);
    strcpyptr(s, "Hellow, world, pointer");
    printf("Pointer: %s\n", s);

    strcpyary(s, "");
    printf("Array: %s\n", s);
    strcpyptr(s, "");
    printf("Pointer: %s\n", s);

    return 0;
}

/* strcpyary: copy t to s; array version */
void strcpyary(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
    {
        i++;
    }
}

/* strcpyptf: copy t to s; pointer version */
void strcpyptr(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}