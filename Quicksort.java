
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
