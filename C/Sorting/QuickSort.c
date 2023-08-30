#include <stdio.h>
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int start = low + 1;
    int end = high;
    int done = 0;
    while (start<=end)
    {
        while (start <= end && a[start] < pivot)
        {
            start++;
        }
        while (start <= end && a[end] > pivot)
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
    int temp = a[low];
    a[low] = a[end];
    a[end] = temp;
    return end;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(a, low, high);
        quick_sort(a, low, pivot_index);
        quick_sort(a, pivot_index + 1, high);
    }
}

int main()
{
    int a[] = {6, 5, 4, 3, 2, 1};
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    quick_sort(a, 0, n - 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}