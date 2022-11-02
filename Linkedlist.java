class Linkedlist{
	Node head;
	class Node{
		String data;
		Node next;
		Node(String data){
			this.data=data;
			this.next=null;
		}
	}
     public void addFirst(String data){
        Node newNode = new Node(data);   
		if (head==null) {
              head=newNode;			
			  return;	
 
			}
			newNode.next=head;
			head=newNode;
	 }
	 public void addLast(String data){
		Node newNode = new Node(data);   
		if (head==null) {
              head=newNode;			
			  return;	
 
			}
		Node currnNode = head;
		while(currnNode.next!=null){
			currnNode=currnNode.next;
		}
		currnNode.next=newNode;
	 }
	 public void printList(){
        if (head==null) {
			System.out.println("The list is empty.");
			return;
		}
		Node currnNode = head;
		while(currnNode!=null){
			
			System.out.print(currnNode.data + "->" );
			currnNode=currnNode.next;
		}
		System.out.println("NULL");
	 }
	public static void main(String[] args) {
	Linkedlist list = new Linkedlist();	
	list.addFirst("a");
	list.addFirst("is");
	list.printList();

	list.addLast("list");
	list.printList();

	list.addFirst("This");
	list.printList();


	}
}
	