// Author/NIM: Garmastewira/13514068
// Date: 27 February 2016
// Filename: Node.h (class Node's header and implementation)

/**
 * This class represents a double-pointer linked list's node
 * A node contains the data it contains, a pointer to the next node, and a pointer
 * to the previous node.
 */

#ifndef BADBLOOD_NODE_H
#define BADBLOOD_NODE_H

template <class T>
class Node {
public:
    /**
     * Constructor for a Node
     * @param data Data contained in a Node
     * @param next Pointer to the next Node
     * @param prev Pointer to the prev Node
     */
    Node(T data, Node *next = nullptr, Node *prev = nullptr) : m_data(data), m_next(next), m_prev(prev) {

    }

    /**
     * Node's next getter
     * @return Pointer to the next Node
     */
    Node* getNext() {
        return m_next;
    }

    /**
     * Node's prev getter
     * @return Pointer to the prev Node
     */
    Node* getPrev() {
        return m_prev;
    }

    /**
     * Node's data getter
     * @return Data contained in a Node
     */
    T& getData() {
        return m_data;
    }

    /**
     * Node's next setter
     * @param next Pointer to the next Node
     */
    void setNext(Node *next) {
        m_next = next;
    }

    /**
     * Node's prev setter
     * @param prev Pointer to the prev Node
     */
    void setPrev(Node *prev) {
        m_prev = prev;
    }

private:
    T m_data;
    Node *m_next;
    Node *m_prev;
};

#endif //BADBLOOD_NODE_H
