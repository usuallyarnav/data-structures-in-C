#include <stdio.h>
void swap(int *x, int *y)
// function to swap two integers
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int *arr, int n)
// function to sort the given array using Bubble Sort algorithm
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of elements present in the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubbleSort(arr, n);
    printf("\nThe sorted array is :\n");
    printArray(arr, n);
    return 0;
}