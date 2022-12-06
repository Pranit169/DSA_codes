
class Doubly_Linkedlist {
    Node head;

    class Node {
        String data;
        Node next;
        Node prev;

        Node(String data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    public void add_AtPosition(String data, int pos) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        if (pos==1) {
            addFirst(data);
            return;
        }
        Node temp = head;
        int count=1;
        while(count<pos-1){
            temp = temp.next;
            count++;
        }
        newNode.next=temp.next;
        temp.next=newNode;
    }

    public void addFirst(String data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        newNode.next = head;
        // head.prev = newNode;
        head = newNode;
    }

    public void addLast(String data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        // newNode.prev = temp;

    }

    public void printList() {

        if (head == null) {
            System.out.println("The list is empty.");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public static void main(String[] args) {
        Doubly_Linkedlist list = new Doubly_Linkedlist();
        list.addFirst("a");
        list.printList();
        list.addFirst("is");
        list.addFirst("This");
        list.printList();
        list.addLast("list");
        list.printList();
        list.add_AtPosition("Error", 3);
        list.printList();

    }
}