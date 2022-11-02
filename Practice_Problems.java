import java.util.Scanner;


public class Practice_Problems{
    public static int factorial(int reamin){
        int fact=1;
        
        for (int i = 1; i <=reamin ; i++) {
            fact=fact*i;
        }
        return fact;
    }
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int digits[] = new int[3];
        int sum=0;
        
        while (n>0) {
            int remain = n%10;
             for (int i = 0; i < digits.length; i++) {
                digits[i]=factorial(remain);
             }
            n=n/10;

        }
        for (int i = 0; i < digits.length; i++) {
            System.out.println(digits[i]);
        }

        // for (int i = 0; i < digits.length; i++) {
        //     sum=sum+digits[i];
        // }
        // if (sum==n) {
        //     System.out.println("The number is peterson number.");
        // }
        //    else{
        //     System.out.println("The number is not peterson number.");
        //    } 
        
        
    }
}