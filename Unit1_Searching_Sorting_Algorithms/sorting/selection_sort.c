#include <stdio.h>
void swap(int *x, int *y)
// function to swap two integers
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int *arr, int n)
// function to sort the given array using the Selection Sort algorithm
{
    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}
void printArray(int *arr, int n)
// fucntion to print the array
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
    selectionSort(arr, n);
    printf("\nThe sorted array is :\n");
    printArray(arr, n);
    return 0;
}