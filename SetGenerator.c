#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char operator[] = {'+', '-', '*', '/'};

    int i, j, k, count = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("\n[%c,%c,%c]", operator[i], operator[j], operator[k]);
                count += 1;
            }
        }
    }
    printf("\nCount %d", count);
}