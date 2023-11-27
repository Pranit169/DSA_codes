#include <stdio.h>
void quickSort(int a[], int low, int high)
{
    if(low>=high){
        return;
    }
    int start=low;
    int end=high;
    int m=s+(e-s)/2;
    int pivot=a[m];
    while (start<=end)
    {
        while (a[start] < pivot)
        {
            start++;
        }
        while ( a[end] > pivot)
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
    quickSort(a, low,start);
    quickSort(a,end,high);
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
