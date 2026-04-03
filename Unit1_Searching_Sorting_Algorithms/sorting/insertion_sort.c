#include <stdio.h>
void swap(int *x, int *y)
// function to swap two integers
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void insertionSort(int *arr, int n)
// function to sort the given array using Insertion Sort algorithm
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void printArray(int *arr, int n)
// function to print the array
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
    insertionSort(arr, n);
    printf("\nThe sorted array is :\n");
    printArray(arr, n);
    return 0;
}