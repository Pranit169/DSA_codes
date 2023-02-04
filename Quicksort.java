<<<<<<< HEAD
import java.util.Scanner;
import java.util.Arrays;

class Quicksort {
    public static void quickSort(int a[], int low, int high) {
        if (low >= high) {
            return;
        }
        int start = low;
        int end = high;
        int mid = start + (end - start) / 2;
        int pivot = a[mid];
        while (start <= end) {
            while (a[start] < pivot) {
                start++;
            }
            while (a[end] > pivot) {
                end--;
            }
            if (start <= end) {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements for array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Array before sorting: ");
        System.out.println(Arrays.toString(arr));

        System.out.println("\nArray after sorting: ");
        quickSort(arr, 0, n - 1);
        System.out.println(Arrays.toString(arr));

    }
}
=======
import java.util.Scanner;

class Quicksort {
    // To print the sorted array.
    public static void printArray(int a[]) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static int partition(int a[], int start, int end) {
        int temp1, temp2;
        int pivot = a[start];
        int count = 0;
        // To count the position of pivot.
        for (int i = start + 1; i <= end; i++) {
            if (pivot >= a[i]) {
                count++;
            }
        }
        int pivotIndex = start + count;
        // Swapping element of pivotIndex and start
        temp1 = a[pivotIndex];
        a[pivotIndex] = a[start];
        a[start] = temp1;

        int i = start, j = end;
        // Traversing the array
        while (i < pivotIndex && j > pivotIndex) {
            while (a[i] <= pivot) {
                i++;
            }
            while (a[j] > pivot) {
                j--;
            }
            // Swapping the elements
            if (i < pivotIndex && j > pivotIndex) {
                temp2 = a[i];
                a[i] = a[j];
                a[j] = temp2;
                i++;
                j--;
            }
        }
        return pivotIndex;

    }

    public static void quickSort(int a[], int start, int end) {
        if (start >= end) {
            return;
        }

        int p = partition(a, start, end);
        // To sort numbers less than piviot
        quickSort(a, start, p - 1);
        // To sort numbers greater than piviot
        quickSort(a, p + 1, end);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements for array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Array before sorting: ");
        printArray(arr);

        System.out.println("\nArray after sorting: ");
        quickSort(arr, 0, n - 1);

        printArray(arr);
    }
}
>>>>>>> 99375831d8481adaf41802f2c0970ace71f06579
