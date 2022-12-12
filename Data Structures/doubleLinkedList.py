class Node:
    def __init__(self, data = None):
        self.data = data
        self.next = None
        self.prev = None


class DLL:
    def __init__(self):
        self.head = None
        self.tail = None

    def addDLL(self, data):
        newNode = Node(data)
        if self.head == None and self.tail == None:
            self.head = newNode
            self.tail = newNode
        elif 