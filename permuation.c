#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int UPPER = 3, LOWER = 0;
char operator[] = {'+', '-', '/', '*'};

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int getIndex()
{
    return (rand() % (UPPER - LOWER + 1)) + LOWER;
}

void appendOperator(int upper, char *newExpression)
{
    int i, j = strlen(newExpression) - 1;
    for (i = 0; i < upper; i++)
    {
        newExpression[j++] = operator[getIndex()];
    }
}

void getExpression(char *str, int partition)
{
    int i, j;
    char newExpression[10];
    if (partition == 1)
    {
        for (i = 0, j = 0; i < 2;)
        {
            newExpression[j++] = str[i++];
        }
        newExpression[j++] = operator[getIndex()];

        for (; i < 4; i++)
        {
            newExpression[j++] = str[i];
        }
        for (i = 0; i < 3 - partition; i++)
        {
            newExpression[j++] = operator[getIndex()];
        }
    }

    else if (partition == 2)
    {
        for (i = 0, j = 0; i < 3;)
        {
            newExpression[j++] = str[i++];
        }
        newExpression[j++] = operator[getIndex()];
        newExpression[j++] = operator[getIndex()];

        for (; i < 4; i++)
            newExpression[j++] = str[i];

        for (i = 0; i < 3 - partition; i++)
        {
            newExpression[j++] = operator[getIndex()];
        }
    }
    else if (partition == 3)
    {
        for (i = 0, j = 0; i < 4;)
        {
            newExpression[j++] = str[i++];
        }
        newExpression[j++] = operator[getIndex()];
        newExpression[j++] = operator[getIndex()];
        newExpression[j++] = operator[getIndex()];
    }
    printf("\nNew Expression %s\n", newExpression);
}

void permutation(char *str, int lower, int upper)
{
    int i;
    if (lower == upper)
    {
        i = getIndex();
        if (i == 0)
            i = 1;
        getExpression(str, i);
        return;
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
    srand(time(0));
    char str[10] = "abcd";
    int i;
    permutation(str, 0, strlen(str) - 1);
}