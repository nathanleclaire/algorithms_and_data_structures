public class LL {
	public static void main(String[] args) {
		Node ll = new Node(1);
		ll.appendToTail(2);	
		ll.appendToTail(3);	
		ll.appendToTail(4);	
		ll.appendToTail(5);	
		ll.appendToTail(2);	
		ll.appendToTail(2);	
		ll.appendToTail(1);	
		ll.appendToTail(3);	
		ll.print();
		ll.dedupe();
		ll.print();
	}	
}
