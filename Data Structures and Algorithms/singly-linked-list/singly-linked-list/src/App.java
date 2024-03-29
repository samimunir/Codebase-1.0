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
        /*
         * Testing function insertAtTail()
         */
        singlyLinkedList.insertAtTail(2);
        singlyLinkedList.insertAtTail(11);
        singlyLinkedList.insertAtTail(7);
        /*
         * Testing function removeFromTail()
         */
        singlyLinkedList.removeFromTail();
        singlyLinkedList.removeFromTail();
        singlyLinkedList.removeFromTail();
        singlyLinkedList.removeFromTail(); // return error expected (removing from empty/null linkedlist)

        /*
         * Testing function doesContainData()
         */
        singlyLinkedList.insertAtHead(2);
        singlyLinkedList.insertAtTail(11);
        singlyLinkedList.insertAtHead(7);
        singlyLinkedList.insertAtTail(56);
        singlyLinkedList.doesContainData(11);

        /*
         * Testing function replaceDataAtNode()
         */
        singlyLinkedList.replaceDataAtNode(3, 22);
    }
}