#include <iostream>
#include <thread>
#include "LinkedList.h"
#include "LinkedListExp.h"

using namespace std;

int main() {
    cout << "Creating a linked list of integer.." << endl;
    LinkedList<int> LL;

    cout << "==========================" << endl;
    cout << "LINKED LIST TESTING DRIVER" << endl;
    cout << "==========================" << endl;
    cout << endl;

    cout << "Author: Garmastewira/13514068" << endl;
    cout << endl;

    try {
        cout << "Deleting the first Node from an empty list" << endl;
        LL.deleteFirst();
    }
    catch (LinkedListExp e) {
        e.printMsg();
    }
    cout << endl;

    cout << "Inserting 1 and 2 to the front of the list in order" << endl;
    LL.insertFirst(1);
    LL.insertFirst(2);
    LL.printList();
    cout << endl;

    cout << "Inserting 3 and 4 to the back of the list in order" << endl;
    LL.insertLast(3);
    LL.insertLast(4);
    LL.printList();
    cout << endl;

    cout << "Deleting the last Node" << endl;
    int deletedVal = LL.deleteLast();
    cout << "Deleted number: " << deletedVal << endl;
    LL.printList();
    cout << endl;

    cout << "Deleting the first Node" << endl;
    deletedVal = LL.deleteFirst();
    cout << "Deleted number: " << deletedVal << endl;
    LL.printList();
    cout << endl;

    cout << "Inserting 5, 6, 7, 8 to the back of the list in order" << endl;
    LL.insertLast(5);
    LL.insertLast(6);
    LL.insertLast(7);
    LL.insertLast(8);
    LL.printList();
    cout << endl;

    try {
        cout << "Deleting a node with negative index" << endl;
        LL.deleteNodeAt(-1);
    } catch (LinkedListExp e) {
        e.printMsg();
    }
    cout << endl;

    try {
        cout << "Deleting a node with an index >= size" << endl;
        LL.deleteNodeAt(6);
    } catch (LinkedListExp e) {
        e.printMsg();
    }
    cout << endl;

    cout << "Deleting a node with index = 3" << endl;
    deletedVal = LL.deleteNodeAt(3);
    cout << "Deleted number: " << deletedVal << endl;
    LL.printList();
    cout << endl;

    cout << "Deleting the number 9 (not in the linked list)" << endl;
    LL.deleteNode(9);
    cout << endl;

    cout << "Deleting the number 3" << endl;
    deletedVal = LL.deleteNode(3);
    cout << "Deleted number: " << deletedVal << endl;
    LL.printList();
    cout << endl;

    cout << "===================" << endl;
    cout << "SUCCESSFULLY TESTED" << endl;
    cout << "===================" << endl;
    cout << endl;
    return 0;
}