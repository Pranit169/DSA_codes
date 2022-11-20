public class Mergesort{
    static void merge(int []a,int start,int end){
          int mid=(end+start)/2;
        //   Length of array on left side
          int n1=mid-start+1;
        //   Length of array on right side
          int n2=end -mid;
        //   Creating two arrays
          int [] a1= new int[n1];
          int [] a2 = new int[n2];
        //   Copying the elements from a to a1
        for (int i = 0; i < n1; i++) {
            a1[i]=a[start+i];
        }
        // Copying the remaining elements from a to a2
        for (int i = 0; i < n2; i++) {
            a2[i]=a[mid+i+1];
        }
        int i=0,j=0;
        // Comparing the elements of both the arrays and placing them in array a
        while (i<n1 && j<n2) {
            if (a1[i]<=a2[j]) {
                a[start++]=a1[i++];
            }
            else{
                a[start++]=a2[j++];
            }
        }
        // Placing the remaining elements of a1 in a
        while (i<n1) {
            a[start++]=a1[i++];
        }
        // Placing the remaining elements of a2 in a
        while(j<n2){
            a[start++]=a2[j++];
        }
        
    }
    static void mergeSort(int []a,int start,int end){
        if (start>=end) {
            return;
        }
        // Findind the middle element
        int mid=(end+start)/2;
        // To sort the elements on the left side
        mergeSort(a, start, mid);
        // To sort the elements on the right side
        mergeSort(a, mid+1, end);
        // To merge the sorted elements
        merge(a,start,end);
    }
    public static void main(String[] args) {
        int []a={6,10,4,11,13,8,2};
        int length=a.length;
        System.out.println("Array before sorting: ");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("\nArray after sorting: ");
        mergeSort(a,0,length-1);
        for (int i = 0; i < length; i++) {
            System.out.print(a[i] + " ");
        }
    }
}