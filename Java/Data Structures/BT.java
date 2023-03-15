import java.util.Scanner;

public class BT {
    public static void main(String[] args) {
      createTree();
    }

    static Node createTree() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the data");
        int data = sc.nextInt();

        if (data == -1) {
            return null;
        }
        Node root = new Node(data);
        
        System.out.println("Enter left for " + data);
        root.left=createTree();

        System.out.println("Enter right for data " + data);
        root.right=createTree();
        return root;
    }
}

class Node {
    Node left, right;
    int data;

    public Node(int data) {
        this.data = data;
    }
}
