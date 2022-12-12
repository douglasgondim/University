
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.top = None

    def push(self, data):
        newNode = Node(data)
        if self.top == None:
            self.top = newNode
        else:
            newNode.next = self.top
            self.top = newNode

    def pop(self):
        newNode = None
        if self.top:
            newNode = self.top
            self.top = self.top.next

        return newNode

    def printStack(self):
        aux = self.top
        if aux == None: 
            print('Empty Stack')
        while aux != None:
            print(aux.data)
            aux = aux.next




newStack = Stack()
newStack.push(5)
newStack.push(9)
newStack.push(7)
newStack.pop()
newStack.pop()
newStack.pop()
newStack.pop()
newStack.printStack()