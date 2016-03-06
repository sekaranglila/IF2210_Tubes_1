//
// Created by Rangga Garmastewira on 2/29/16.
//

#include "LinkedListExp.h"
#include <iostream>

using namespace std;

LinkedListExp::LinkedListExp(int idx) : msg_id(idx) {

}

void LinkedListExp::printMsg() {
    cout << "ERROR: " << msg[msg_id] << endl;
}