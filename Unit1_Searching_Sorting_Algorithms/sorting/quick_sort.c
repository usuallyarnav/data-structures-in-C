#include <stdio.h>
void swap(int *x, int *y)
// function to swap two integers
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *arr, int low, int high)
// function that rearranges elements around pivot — smaller to its left, greater to its right.
{
    int pivot = arr[high];
    int i = low, j = high - 1;
    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= i && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
void quickSort(int *arr, int low, int high)
// function that performs the sorting using Quick Sort algorithm
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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
    quickSort(arr, 0, n - 1);
    printf("\nThe sorted array is :\n");
    printArray(arr, n);
    return 0;
}