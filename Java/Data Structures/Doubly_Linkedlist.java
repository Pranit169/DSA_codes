
public class Doubly_Linkedlist {
    Node head;

    private class Node {

        int data;
        Node next;
        Node prev;

        public Node(int data) {
            this.data = data;
        }

        public Node(int data, Node next, Node prev) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    public void insertFirst(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        
        if (head != null) {
            head.prev = newNode;
        }
        head = newNode;
    }

    public void insertLast(int data) {
        Node newNode = new Node(data);
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        newNode.prev = temp;
        temp.next = newNode;
    }

    public void insertAtPos(int data, int pos) {
        Node newNode = new Node(data);
        int count = 0;
        Node temp = head;
        while (count < pos - 1) {
            temp = temp.next;
            count++;
        }
        newNode.next = temp.next;
        temp.next = newNode;
        newNode.prev = temp;
        newNode.next.prev = newNode;

    }

    public void deletion(int pos) {
        Node temp = head;
        while (pos == 0) {
            head = temp.next;
            head.prev = null;
            return;
        }
        int count = 0;
        while (count < pos - 1) {
            temp = temp.next;
            count++;
        }
        Node currnNode = temp.next.next;
        temp.next = currnNode;
        currnNode.prev = temp;

    }

    public void display() {
        Node temp = head;
        Node last = null;
        while (temp != null) {
            System.out.print(temp.data + "->");
            last = temp;
            temp = temp.next;
        }
        System.out.println("END");

        System.out.println("Print in rev");
        while (last != null) {
            System.out.print(last.data + "->");
            last = last.prev;
        }
        System.out.println("Start");
    }

    public static void main(String[] args) {
        Doubly_Linkedlist list = new Doubly_Linkedlist();
        list.insertFirst(6);
        list.insertFirst(5);
        list.insertLast(7);
        list.insertLast(8);
        list.insertLast(9);
        list.insertAtPos(10, 2);
        list.deletion(0);
        list.deletion(3);
        list.display();
    }
}