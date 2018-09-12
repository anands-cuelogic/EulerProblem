#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int UPPER = 3, LOWER = 0;
char operator[] = {'+', '-', '/', '*', '(', ')'};

void display(int *numArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", numArray[i]);
    }
    printf("\n");
}

int getIndex()
{
    return (rand() % (UPPER - LOWER + 1)) + LOWER;
}

void createExpression(int *numArray, int size)
{
    int i = 0, result = 0;
    for (i = 0; i < 4; i++)
    {
        printf("a %c b %c c %c d\n", operator[getIndex()], operator[getIndex()], operator[getIndex()]);
    }
}

void swapArray(int pos, int *numArray, int size)
{
    int i, temp = numArray[0];
    numArray[0] = numArray[pos];
    numArray[pos] = temp;
    display(numArray, size);
}

int main()
{
    srand(time(0));
    int numArray[] = {1, 2, 3, 4};
    createExpression(numArray, 4);
    // for(int i = 0; i < 4; i++){
    //     swapArray(i, numArray, 4);
    // }
}