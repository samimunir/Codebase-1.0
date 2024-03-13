public class LinkedList {
    private Node head;
    private int numberOfElements = 0;
    private int pointer = -1;

    public LinkedList() {
        System.out.println("singly-linked-list initialization successful.");
    }

    public boolean isEmpty() {
        if (this.head == null) {
            return true;
        } else {
            return false;
        }
    }
}