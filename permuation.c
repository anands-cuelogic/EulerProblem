#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutation(char *str, int lower, int upper)
{
    int i;
    if (lower == upper)
    {
        printf("%s \n", str);
    }
    else
    {
        for (i = lower; i <= upper; i++)
        {
            swap((str + lower), (str + i));
            permutation(str, lower + 1, upper);
            swap((str + lower), (str + i));
        }
    }
}

void main()
{
    char str[10] = "abcd";
    int i;
    permutation(str, 0, strlen(str) - 1);
}