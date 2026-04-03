#include <stdio.h>
int linearSearch(int *arr, int n, int key)
// function to find 'key' using linear search algorithm
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
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
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int key;
    printf("Enter the key\n");
    scanf("%d", &key);
    if (linearSearch(arr, n, key) == -1)
    {
        printf("Key not found in the array\n");
    }
    else
    {
        printf("Key found at index %d\n", linearSearch(arr, n, key));
    }
    return 0;
}