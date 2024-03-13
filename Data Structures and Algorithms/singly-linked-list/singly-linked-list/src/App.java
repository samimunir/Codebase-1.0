public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("singly linked list");
        System.out.println("------------------");

        LinkedList singlyLinkedList = new LinkedList();
        /*
         * Testing function printDataStructureStats()
         */
        singlyLinkedList.printDataStructureStats();
        /*
         * Testing function insertAtHead()
         */
        singlyLinkedList.insertAtHead(2);
        singlyLinkedList.insertAtHead(11);
        singlyLinkedList.insertAtHead(7);
        /*
         * Testing function removeFromHead()
         */
        singlyLinkedList.removeFromHead();
        singlyLinkedList.removeFromHead();
        singlyLinkedList.removeFromHead();
        singlyLinkedList.removeFromHead(); // return error expected (removing from empty/null linkedlist)
    }
}