//Author/NIM: Garmastewira/13514068
//Date: 27 February 2016
//Filename: LinkedList.h (class's header)

/**
 *  This class represents a double-pointer linked list
 *  A double-pointer linked list is built from double-pointer nodes which have a pointer to the next node
 *  and a pointer to the previous node
 *  This linked list saves the size of the list, the first node of the list, and the last node of the list
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList {
public:
    /**
     *  Constructor of a LinkedList
     *  Setting its first and last to null and its size to 0
     */
    LinkedList();

    /**
     *  Getter for linked list's size
     *  @return The size of the list
     */
    int getSize();

    /**
     *  Inserts a Node containing data at the front of the list
     *  @param data Data contained in a Node
     */
    void insertFirst(T data);

    /**
     *  Deletes a Node at the front of the list
     *  @return The deleted data
     */
    T deleteFirst();

    /**
     *  Inserts a Node containing data at the back of the list
     *  @param data Data contained in a Node
     */
    void insertLast(T data);

    /**
     *  Deletes a Node at the back of the list
     *  @param data Data contained in a Node
     *  @return The deleted data
     */
    T deleteLast();

    /**
     *  Accesses the i-th Node, in which the 0-th Node is the first Node
     *  @param data ata contained in a Node
     *  @return A reference to the accessed Node's data
     */
    T& operator[] (const int idx);

    /**
     *  Deletes the i-th Node
     *  @param idx
     *  @return The deleted data
     */
    T deleteNodeAt(const int idx);

    /**
     *  Deletes the node P
     *  @param P
     *  @return The deleted data
     */
    T deleteNodeAt(Node<T> *P);

    /**
     *  Deletes a Node which contains the data given
     *  @param data Data contained in a Node
     *  @return The deleted data
     */
    T deleteNode(const T& data);

    /**
     *  Prints the list, starting from the first Node to the last Node
     */
    void printList();

private:
    // Member variables
    int size; // length of the list
    Node<T> *first; // pointer to the first Node
    Node<T> *last; // pointer to the last Node

    // Helper methods

    /**
     *  @return True if the list is empty
     */
    bool isEmpty();

    /**
     *  @return True if the list's size is only one
     */
    bool isOneElmt();
};

#endif //LINKEDLIST_H
