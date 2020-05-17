/* Author: pbollom
Date: 2020-05-17
Description: 2-5 Returns the first location in s1 where any character in s2 occurs, or -1 if none of   
             the characters in s2 are in s1 */
#include<stdio.h>

void printTest(char s1[], char s2[]);
int any(char s1[], char s2[]);
int charInStr(char s[], int c);

int main()
{
    printTest("a","b"); // no overlap, single characters: -1
    printTest("asdf", "jkl;"); // no overlap, multi-characters: -1
    printTest("", ""); // double empty string input: -1
    printTest("", "a"); // empty string to find in: -1
    printTest("a", ""); // empty string to find: -1
    printTest("a","a"); // identical single characters: 0
    printTest("aba","a"); // multi-character in string, single character to find, leading: 0
    printTest("bba", "a"); // multi-character in string, single character to find, non-leading: 2
    printTest("asdf","sd"); // multi-character to find, same order: 1
    printTest("asdf", "ds"); // multi-character to find, reverse order: 1

    return 0;
}

void printTest(char s1[], char s2[])
{
    printf("%d\n", any(s1, s2));
}

/* Returns the integer location fo the first instnace in s1 where any character in s2 occurs, or -1 if
none of the characters in s2 are in s1. Similar to squeeze (2-4), if we were doing this a lot with the 
same string s2, we would want to remove any duplicate characters.*/
int any(char s1[], char s2[])
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
    {
        if (charInStr(s2, s1[i]))
        {
            return i;
        }
    }

    return -1;
}

/* Checks whether a single character is in a string. Returns 1 if it is, or 0 if it is not. */
int charInStr(char s[], int c)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return 1;
        }
    }

    return 0;
}