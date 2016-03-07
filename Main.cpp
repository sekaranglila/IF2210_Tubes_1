//
// Created by Rangga Garmastewira on 3/5/16.
//

#include <iostream>
#include <cstdlib>
#include "LinkedList/LinkedList.h"
#include "Matriks/Matriks.h"
#include "Makhluk/Hewan/Herbivore.h"
#include "Makhluk/Hewan/Carnivore.h"
#include "Makhluk/Hewan/Omnivore.h"
#include "Makhluk/Bakteri/Bakteri.h"
#include "Makhluk/Manusia/Men.h"
#include "Makhluk/Manusia/Female.h"
#include "Makhluk/Tumbuhan/Beracun.h"
#include "Makhluk/Tumbuhan/NonBeracun.h"

using namespace std;

int main() {
    srand(time(NULL));
    Matriks A;
    LinkedList<Makhluk*> test;

    for (int i = 0; i < 10; i++) {
        Makhluk *m = new Bakteri;
        test.insertLast(m);
        A.putMakhluk(m);
    }
    A.display();
    cout << endl;
    while (test.getSize() > 1) {
        for (int j = 0; j < test.getSize(); j++) {
            if (test[j]->getStatus() == 0) {
                test.deleteNodeAt(j);
            } else {
                A.action(test[j]);
            }
        }
        system("clear");
        A.display();
        cout << endl;
        sleep(1);
    }
    cout << "FINISHED" << endl;
    return 0;
}