//
// Created by Rangga Garmastewira on 2/29/16.
//

#ifndef LINKEDLISTEXP_H
#define LINKEDLISTEXP_H

#include <string>

using namespace std;

class LinkedListExp {
public:
    /**
     * Constructor
     * @param idx
     */
    LinkedListExp(int idx);

    /**
     * Prints the message to the screen depending on which
     * exception occurs
     */
    void printMsg();

    // Message IDs of different exception types
    static const int EMPTY = 0;
    static const int NEGATIVE_INDEX = 1;
    static const int OUT_OF_BOUND = 2;

private:
    const string msg[3] = { "Linked list is empty", "Linked list cannot access negative index",
                            "Node at the given index is not accessible" };
    const int msg_id;
};


#endif //LINKEDLISTEXP_H
