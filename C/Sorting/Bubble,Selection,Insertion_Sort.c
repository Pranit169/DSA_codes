#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void bubbleSort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int a[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && a[j] < a[j - 1])
        {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j -= 1;
        }
    }
}

int main()
{
    int a[100];
    int ans, s, ch;

    while (1)
    {
        printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter size of an array: ");
            scanf("%d", &s);
            printf("Enter the elements for array: ");
            for (int i = 0; i < s; i++)
            {
                scanf("%d", &a[i]);
            }
            printf("Array after sorting: ");
            bubbleSort(a, s);
            printArray(a, s);
            break;

        case 2:
            printf("Enter size of an array: ");
            scanf("%d", &s);
            printf("Enter the elements for array: ");
            for (int i = 0; i < s; i++)
            {
                scanf("%d", &a[i]);
            }
            printf("Array after sorting: ");
            selectionSort(a, s);
            printArray(a, s);
            break;
        case 3:
            printf("Enter size of an array: ");
            scanf("%d", &s);
            printf("Enter the elements for array: ");
            for (int i = 0; i < s; i++)
            {
                scanf("%d", &a[i]);
            }
            printf("Array after sorting: ");
            insertionSort(a, s);
            printArray(a, s);
            break;
        case 4:
            exit(0);
        }
    }
}