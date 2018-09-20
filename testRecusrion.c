#include <stdio.h>

int printLoop(int i, int j, int k)
{
    if (i < 2)
    {
        if (j < 2)
        {
            if (k < 2)
            {
                return (i * 100 + j * 10 + k);
                printLoop(i, j, k + 1);
            }
            else
            {
                printLoop(i, j + 1, 0);
            }
        }
        else
        {
            printLoop(i + 1, 0, 0);
        }
    }
}

int main()
{
    int i, j, k;

    printf("\nRecursion::::");
    printLoop(0, 0, 0);
}