//Author/NIM: Garmastewira/13514068
//Date: 27 February 2016
//Filename: LinkedList.cpp (class's implementation)

#include "LinkedList.h"
#include "LinkedListExp.h"
#include "../Makhluk/Makhluk.h"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

template <class T>
int LinkedList<T>::getSize() {
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return (size == 0);
}

template <class T>
bool LinkedList<T>::isOneElmt() {
    return (size == 1);
}

template <class T>
void LinkedList<T>::insertFirst(T data) {
    Node<T> *P = new Node<T>(data);
    if (isEmpty()) {
        first = P;
        last = P;
    } else {
        P->setNext(first);
        first->setPrev(P);
        first = P;
    }
    ++size;
}

template <class T>
T LinkedList<T>::deleteFirst() {
    if (isEmpty()) {
        throw LinkedListExp(LinkedListExp::EMPTY);
    }

    T deletedVal = first->getData();
    Node<T> *P = first;
    if (!isOneElmt()) {
        first->getNext()->setPrev(nullptr);
        first = first->getNext();
    } else {
        first = nullptr;
        last = nullptr;
    }
    delete P;
    --size;
    return deletedVal;
}

template <class T>
void LinkedList<T>::printList() {
    Node<T> *P = first;
    cout << "Linked List: " << endl;
    for (int i = 0; i < size; i++) {
        std::cout << P->getData() << " ";
        P = P->getNext();
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::insertLast(T data) {
    if (isEmpty()) {
        return insertFirst(data);
    } else {
        Node<T> *P = new Node<T>(data);
        P->setPrev(last);
        last->setNext(P);
        last = P;
    }
    ++size;
}

template <class T>
T LinkedList<T>::deleteLast() {
    if (isEmpty()) {
        throw LinkedListExp(LinkedListExp::EMPTY);
    }

    T deletedVal = last->getData();
    Node<T> *P = last;
    if (!isOneElmt()) {
        last->getPrev()->setNext(nullptr);
        last = last->getPrev();
    } else {
        last = nullptr;
        first = nullptr;
    }
    delete P;
    --size;
    return deletedVal;
}

template <class T>
T& LinkedList<T>::operator[] (const int idx) {
    if (idx <= size / 2) {
        Node<T> *P = first;
        int i = 0;
        while (i < idx) {
            P = P->getNext();
            i++;
        }
        return P->getData();
    } else {
        Node<T> *P = last;
        int i = size-1;
        while (i > idx) {
            P = P->getPrev();
            i--;
        }
        return P->getData();
    }
}

template <class T>
T LinkedList<T>::deleteNodeAt(const int idx) {
    // Throws an exception if necessary
    if (isEmpty()) {
        throw LinkedListExp(LinkedListExp::EMPTY);
    }
    if (idx < 0) {
        throw LinkedListExp(LinkedListExp::NEGATIVE_INDEX);
    }
    if (idx >= size) {
        throw LinkedListExp(LinkedListExp::OUT_OF_BOUND);
    }

    Node<T> *P = first;
    int i = 0;
    while (i < idx) {
        P = P->getNext();
        i++;
    }
    if (P == first) {
        return deleteFirst();
    } else if (P == last) {
        return deleteLast();
    } else {
        return deleteNodeAt(P);
    }
}

template <class T>
T LinkedList<T>::deleteNodeAt(Node<T> *P) {
    if (isEmpty()) {
        throw LinkedListExp(LinkedListExp::EMPTY);
    }

    P->getPrev()->setNext(P->getNext());
    P->getNext()->setPrev(P->getPrev());
    T deletedVal = P->getData();
    delete P;
    --size;
    return deletedVal;
}

template <class T>
T LinkedList<T>::deleteNode(const T& data) {
    if (isEmpty()) {
        throw LinkedListExp(LinkedListExp::EMPTY);
    }

    Node<T> *P = first;
    int i = 0;
    while (i < size && P->getData() != data) {
        P = P->getNext();
        i++;
    }
    if (i < size) {
        return deleteNodeAt(P);
    } else {
        cout << "Data is not found" << endl;
        return 0;
    }
}

template class LinkedList<int>;
template class LinkedList<char>;
template class LinkedList<Makhluk*>;