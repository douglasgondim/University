class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, data):
        newNode = Node(data)
        if self.head == None:
            self.head = newNode
            self.tail = newNode
        else:
            self.tail.next = newNode
            self.tail = newNode

    def dequeue(self):
        if self.head != None:
            aux = self.head
            self.head = self.head.next
            return aux.data

    def printQueue(self):
        aux = self.head
        while aux != None:
            print(aux.data)
            aux = aux.next

    def isEmpty(self):
        if self.head == None:
            return True
        else:
            return False

# LL = Queue()

# LL.enqueue(20)
# LL.enqueue(40)
# LL.enqueue(0)
# LL.enqueue(11)

# # LL.dequeue()
# # LL.dequeue()
# # LL.dequeue()
# # LL.dequeue()
# LL.printQueue()
