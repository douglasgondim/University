####################  READ ME  #####################

# Author: José Douglas Gondim Soares, MAT 485347

# Como não estava certo sobre que porção do algoritmo era suficiente, resolvi mandar todo o meu código.
# O código contém a implementação de uma fila com lista simplismente encadeada e até mesmo toda a implementação
# da Árvore Binária de Busca que fiz para praticar e testar.

# O código é 100% funcional e até deixei um cenário de teste na MAIN function.

# Eu poderia ter usado uma lista comum do python com append e pop(0), mas essa não é uma boa implementação de uma fila,
# já que remover no começo é muito custoso. Dessa forma, implementei minha própria fila para garantir tempo O(n) no total do algoritmo.

# A parte chave do trabalho está salientada com uma linha de #'s.

####################  READ ME  #####################


class QueueNode:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, data):
        newNode = QueueNode(data)
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


################################# FUNÇÃO VISITA EM NÍVEL #################################  

def printInLevel(T):
    if T.root == None: return
    queue = Queue()
    queue.enqueue(T.root)
    while not queue.isEmpty():
        pop = queue.dequeue()
        print(pop.data)
        if pop.left: queue.enqueue(pop.left)
        if pop.right: queue.enqueue(pop.right)

################################# FUNÇÃO VISITA EM NÍVEL #################################  


# MAIN function

T = BST()

T.addBST(20)
T.addBST(11)
T.addBST(5)
T.addBST(18)
T.addBST(2)
T.addBST(25)
T.addBST(82)
T.addBST(7)
T.addBST(90)
T.addBST(70)

printInLevel(T)
