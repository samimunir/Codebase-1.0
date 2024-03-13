public class LinkedList {
    private Node head;
    private int numberOfElements = 0;
    private int pointer = -1;

    public LinkedList() {
        System.out.println("singly-linked-list initialization successful.");
    }
    
    private boolean isEmpty() {
        if (this.head == null) {
            return true;
        } else {
            return false;
        }
    }

    public void printLinkedList() {
        if (isEmpty()) {
            System.out.println("\tHEAD -> NULL");
        } else {
            Node currentNode = this.head;
            System.out.print("\tHEAD -> ");
            while (currentNode != null) {
                System.out.print(currentNode.getData() + " -> ");
                currentNode = currentNode.getNext();
            }
            System.out.println("NULL");
        }
    }

    public void printDataStructureStats() {
        printLinkedList();
        System.out.println("\tnumberOfElements: " + this.numberOfElements);
        System.out.println("\tpointer: " + pointer);
    }

    public void insertAtHead(int data) {
        System.out.println("\ninsertAtHead(" + data + ") called...");
        if (isEmpty()) {
            this.head = new Node(data);
            this.numberOfElements++;
            this.pointer++;
        } else {
            Node newHeadNode = new Node(data, this.head);
            this.head = newHeadNode;
            this.numberOfElements++;
            this.pointer++;
        }
        printDataStructureStats();
    }
}