package Sorting;
import java.util.Scanner;

public class Mergesort {
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
        mergeSort(arr, 0, n - 1);

        printArray(arr);
    }
    // To print the sorted array.
    public static void printArray(int a[]) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    static void merge(int[] a, int start, int end) {
        int mid = (end + start) / 2;
        // Length of array on left side
        int n1 = mid - start + 1;
        // Length of array on right side
        int n2 = end - mid;
        // Creating two arrays
        int[] a1 = new int[n1];
        int[] a2 = new int[n2];
        // Copying the elements from a to a1
        for (int i = 0; i < n1; i++) {
            a1[i] = a[start + i];
        }
        // Copying the remaining elements from a to a2
        for (int i = 0; i < n2; i++) {
            a2[i] = a[mid + i + 1];
        }
        int i = 0, j = 0;
        // Comparing the elements of both the arrays and placing them in array a
        while (i < n1 && j < n2) {
            if (a1[i] <= a2[j]) {
                a[start++] = a1[i++];
            } else {
                a[start++] = a2[j++];
            }
        }
        // Placing the remaining elements of a1 in a
        while (i < n1) {
            a[start++] = a1[i++];
        }
        // Placing the remaining elements of a2 in a
        while (j < n2) {
            a[start++] = a2[j++];
        }
    }

    static void mergeSort(int[] a, int start, int end) {
        if (start >= end) {
            return;
        }
        // Findind the middle element
        int mid = (end + start) / 2;
        // To sort the elements on the left side
        mergeSort(a, start, mid);
        // To sort the elements on the right side
        mergeSort(a, mid + 1, end);
        // To merge the sorted elements
        merge(a, start, end);
    }
}