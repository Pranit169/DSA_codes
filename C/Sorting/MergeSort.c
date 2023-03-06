#include <stdio.h>
void merge(int a[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int l1 = mid - start + 1;
    ;
    int r1 = end - mid;
    int left[l1], right[r1];

    for (int i = 0; i < l1; i++)
    {
        left[i] = a[start + i];
    }
    for (int i = 0; i < r1; i++)
    {
        right[i] = a[mid + i + 1];
    }
    int i = 0, j = 0;
    while (i < l1 && j < r1)
    {
        if (left[i] < right[j])
        {
            a[start++] = left[i++];
        }
        else
        {
            a[start++] = right[j++];
        }
    }
    while (i < l1)
    {

        a[start++] = left[i++];
    }
    while (i < l1)
    {
        a[start++] = right[j++];
    }
}
void mergeSort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    merge(a, start, end);
}

void main(){
    int a[]={3,2,6,5,1};
    mergeSort(a,0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    
}