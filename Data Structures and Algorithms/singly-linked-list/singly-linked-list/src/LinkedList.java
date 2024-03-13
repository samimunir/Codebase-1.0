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
            System.out.println("HEAD -> NULL");
        } else {
            Node currentNode = this.head;
            System.out.print("HEAD -> ");
            while (currentNode != null) {
                System.out.print(currentNode.getData() + " -> ");
                currentNode = currentNode.getNext();
            }
            System.out.print("NULL");
        }
    }
}