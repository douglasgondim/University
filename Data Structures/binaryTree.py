from queue import Queue

class Node:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None


class BST:
    def __init__(self):
        self.root = None

    def addBST(self, data):
        newNode = Node(data)
        if self.root == None:
            self.root = newNode
            return

        auxParent = None
        aux = self.root

        while(aux != None):
            auxParent = aux
            if(newNode.data > aux.data):
                aux = aux.right
            else:
                aux = aux.left

        if(newNode.data > auxParent.data):
            auxParent.right = newNode
            
        else:
            auxParent.left = newNode
        newNode.parent = auxParent
        

    def search(self, p, data):
        if(p == None):
            print('Element not found.')
            return None
        if(p.data == data):
            return p
        if(data > p.data):
            return self.search(p.right, data)
        else:
            return self.search(p.left, data)

    def printPreOrder(self, p):
        print(p.data)
        if p.left:
            self.printPreOrder(p.left)
        if p.right:
            self.printPreOrder(p.right)

    def printPostOrder(self, p):
        if p.left:
            self.printPostOrder(p.left)
        if p.right:
            self.printPostOrder(p.right)
        print(p.data)

    def printInOrder(self, p):
        if p.left:
            self.printInOrder(p.left)
        print(p.data)
        if p.right:
            self.printInOrder(p.right)

    def minimum(self, p):
        if(p == None):
            print('Empty Tree')
            return
        while(p.left != None):
            p = p.left
        return p
        print(p.data)

    def maximum(self, p):
        if(p == None):
            print('Empty Tree')
            return
        while(p.right != None):
            p = p.right
        return p

    def successor(self, data):
        p = self.search(self.root, data)
        if not p: return None
        if p.right: return self.minimum(p.right)
        aux = p.parent
        while aux and p == aux.right:
            p = aux
            aux = p.parent
        return aux


    def predecessor(self, data):
        p = self.search(self.root, data)
        if not p: return None
        if p.left: return self.maximum(p.left)
        aux = p.parent
        while aux and p == aux.left:
            p = aux
            aux = p.parent
        return aux

    def transplant(self, u, v):
        if u == self.root:
            self.root = v
        elif u == u.parent.right:
            u.parent.right = v
        else: u.parent.left = v
        if v:
            v.parent = u.parent

    def delete(self, data):
        nodeToDelete = self.search(self.root, data)
        if nodeToDelete:
            if not nodeToDelete.left:
                self.transplant(nodeToDelete, nodeToDelete.right)
            elif not nodeToDelete.right:
                self.transplant(nodeToDelete, nodeToDelete.left)
            else:
                y = self.minimum(nodeToDelete.right)
                if y.parent != nodeToDelete:
                    self.transplant(y, y.right)
                    y.right = nodeToDelete.right
                    y.right.parent = y
                self.transplant(nodeToDelete, y)
                y.left = nodeToDelete.left
                y.left.parent = y

                
    def printInLevel(self):
        if self.root == None: return
        queue = Queue()
        queue.enqueue(self.root)
        while not queue.isEmpty():
            pop = queue.dequeue()
            print(pop.data)
            if pop.left: queue.enqueue(pop.left)
            if pop.right: queue.enqueue(pop.right)

        


        




bst1 = BST()

bst1.addBST(20)
bst1.addBST(11)
bst1.addBST(5)
bst1.addBST(18)
bst1.addBST(2)
bst1.addBST(25)
bst1.addBST(82)
bst1.addBST(7)
bst1.addBST(90)
bst1.addBST(70)

bst1.printInLevel()

