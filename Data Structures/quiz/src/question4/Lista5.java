package question4;

public class Lista5 {
	Node head;
	Node end;
	int len=0;
	
	
	void add(int position, int data) {
		Node newNode = new Node(data);
		if(len==0) {
			head = newNode;
			end = newNode;
		}else {
			if(position >= 0 && position <=len) {
				if(position == 0) {
					newNode.next = head;
					head = newNode;
				}else if(position==len) {
					end.next =newNode;
					newNode = end;
				}else {
			Node aux = head;
					for(int i=0;i<position-1;i++) {
						aux = aux.next;
					}
					newNode.next = aux.next;
					aux.next = newNode;	
				}
			}
		}
		len++;		
		
	}

	void print() {
		Node aux = head;
		for(int i=0;i<len;i++) {
			System.out.println(aux.data);
			aux = aux.next;
		}
	}


}
