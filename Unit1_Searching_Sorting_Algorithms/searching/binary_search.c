#include <stdio.h>
int binarySearch(int *arr, int n, int key)
// function to find 'key' using the binary search algorithm
{
    int st = 0, end = n - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the number of elements present in the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in ascending order\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int key;
    printf("Enter the key\n");
    scanf("%d", &key);
    if (binarySearch(arr, n, key) == -1)
    {
        printf("Key not found in the array\n");
    }
    else
    {
        printf("Key found at index %d\n", binarySearch(arr, n, key));
    }
    return 0;
}