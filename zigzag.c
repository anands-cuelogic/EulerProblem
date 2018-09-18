#include <stdio.h>

void display(int *arr, int size)
{
    int i;
    printf("\nDisplay :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int *arr, int size)
{
    int temp, i, j;
    for (i = 1; i < size; i++)
    {
        for (j = i; j >= 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void genrateZigZag(int *arr, int size)
{
    int i, j, mid, newArr[size], k = 0;
    mid = size / 2;
    for (i = 0, j = mid + 1; i <= mid && j < size; i++, j++)
    {
        newArr[k++] = arr[i];
        newArr[k++] = arr[j];
    }
    while (i <= mid)
    {
        newArr[k++] = arr[i];
        i += 1;
    }
    printf("\n\nNew array");
    display(newArr, size);
}

void main()
{
    int arr[10] = {4, 3, 7, 8, 6, 2, 1};
    sort(arr, 7);
    display(arr, 7);
    genrateZigZag(arr, 7);
}