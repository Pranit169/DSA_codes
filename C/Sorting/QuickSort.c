#include <stdio.h>
void quickSort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int start = low;
    int end = high;
    int mid = start + (end - start) / 2;
    int pivot = a[mid];
    while (start <= end)
    {
        while (a[start] < pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start <= end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
    }
    quickSort(a, low, end);
    quickSort(a, start, high);
}
void main()
{
    int a[] = {5, 2, 3, 1, 0};
    quickSort(a, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
}