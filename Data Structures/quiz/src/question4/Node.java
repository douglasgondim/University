package question4;

public class Node {
		int data;
		Node next;
		boolean positive;
		
		public Node() {}
		public Node(int data) {
			this.data = data;
			if(data>=0) {
				this.positive = true;
			}else {
				this.positive = false;
			}
			
		}
}
