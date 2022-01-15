# Node class
class Node:

    # Function to initialize the Node object
    def __init__(self,data):
        # Assign the data
        self.data = data
        # Assign the next as NULL
        self.next = None

# Linked list class
class LinkedList:

    # Function to initialize the head
    def __init__(self):
        self.head = None

    # Function to traverse and print the list
    def printList(self):
        ptr = self.head
        while(ptr):
            print(ptr.data, end=" ")
            ptr = ptr.next
        print("\n")

    # Function to insert node at the beg
    def insertBeg(self,data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Function to insert node after a particular node
    def insertAfter(self,data,val):
        new_node = Node(data)
        ptr = self.head
        while(ptr.data!=val):
            ptr=ptr.next
        new_node.next = ptr.next
        ptr.next = new_node

    # Function to insert node before a particular node
    def insertBefore(self,data,val):
        new_node = Node(data)
        ptr = self.head
        while(ptr.data!=val):
            pre_ptr = ptr
            ptr=ptr.next
        new_node.next = ptr
        pre_ptr.next = new_node

    # Function to insert node at the end
    def insertEnd(self, data):
        new_node = Node(data)
        ptr = self.head
        while(ptr.next):
            ptr = ptr.next
        ptr.next=new_node
        new_node.next = None

    # Function to delete node at the beg
    def deleteBeg(self):
        ptr = self.head
        self.head = ptr.next
        ptr = None

    # Function to delete node after a particular node
    def deleteAfter(self,data,val):
        ptr = self.head
        while(ptr.data!=val):
            ptr = ptr.next
        post_ptr = ptr.next
        ptr.next = post_ptr.next
        post_ptr = None

    # Function to delete node at end
    def deleteEnd(self):
        ptr = self.head
        while(ptr.next!=None):
            pre_ptr = ptr
            ptr = ptr.next
        pre_ptr.next = None
        ptr = None        

# Main function
if __name__=='__main__':
    # Create an empty linked list
    ll = LinkedList()

    # Create the nodes
    ll.head = Node(1)
    second = Node(2)
    third = Node(3)

    # Connect the nodes
    ll.head.next = second
    second.next = third

    # Print the linked list
    ll.printList()

    ll.insertBeg(1)
    ll.printList()

    ll.insertAfter(4,2)
    ll.printList()

    ll.insertBefore(6,3)
    ll.printList()

    ll.insertEnd(8)
    ll.printList()

    ll.deleteBeg()
    ll.printList()

    ll.deleteAfter(3,6)
    ll.printList()

    ll.deleteEnd()
    ll.printList()