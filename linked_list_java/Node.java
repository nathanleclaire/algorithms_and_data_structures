public class Node {
	private Node next;
	int val;

	public Node(int d) {
		val = d;
	}

	public void dedupe() {
		Node dedupedNode = new Node(next.val);
		Node n = next;
		while (n.next != null) {
			dedupedNode.appendToTailDedupe(n.val);
			n = n.next;
		}
		next = dedupedNode;
	}


	public void appendToTail(int d) {
		Node end = new Node(d);
		Node n = this;
		while (n.next != null) {
			n = n.next;
		}	
		n.next = end;
	}

	public void appendToTailDedupe(int d) {
		Node end = new Node(d);
		Node n = this;
		while (n.next != null) {
			if (d == n.val) {
				return;
			}
			n = n.next;
		}
		n.next = end;
	}

	public void print() {
		System.out.print("(");
		if (next != null) {
			System.out.print(val);
			System.out.print(")->");
			next.print();
		} else {
			System.out.print(val);
			System.out.print(")\n");
		}
	}
}
