import java.util.Random;
import java.util.ArrayList;
import java.util.Scanner;
 class Movie{
    String title;
    String genere;
    int rating;
    
    void playIt(){
        System.out.println("Playing the movie.");
       
    
    }
}
public class new_class {
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    Movie one = new Movie();
    one.title= "Interstellar";
    one.genere= "Sci-fi";
    one.rating = 9;
    // String a = sc.nextLine();

    Movie two = new Movie();
    two.title = "Inception";
    two.genere="Sci-fi";
    two.rating=8;
    two.playIt();
    // System.out.println(two.title);
    int targetname = (int) (Math.random()*10);
     System.out.println(targetname);
     
     int a = sc.nextInt();
     System.out.println(a);
     byte x = 2;
}
    
}
