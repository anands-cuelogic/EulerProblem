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
    int i, j = strlen(newExpression);
    for (i = 0; i < upper; i++)
    {
        newExpression[j++] = operator[getIndex()];
    }
}

void appendOperand(int lower, int upper, int j, char *str, char *newExpression)
{
    int i;
    for (i = lower; i < upper; i++)
    {
        newExpression[j++] = str[i];
    }
    newExpression[j] = '\0';
}

void getExpression(char *str, int partition)
{
    int i, j;
    char newExpression[10];
    if (partition == 1)
    {
        appendOperand(0, 2, 0, str, newExpression);
        appendOperator(1, newExpression);

        appendOperand(2, 4, 3, str, newExpression);
        appendOperator(3 - partition, newExpression);
    }

    else if (partition == 2)
    {
        appendOperand(0, 3, 0, str, newExpression);
        appendOperator(2, newExpression);

        appendOperand(3, 4, 5, str, newExpression);
        appendOperator(3 - partition, newExpression);
    }
    else if (partition == 3)
    {
        appendOperand(0, 4, 0, str, newExpression);
        appendOperator(3, newExpression);
    }
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