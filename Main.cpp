//
// Created by Rangga Garmastewira on 3/5/16.
//

#include <iostream>
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
    char c = 'a';
    Matriks A;
    LinkedList<Makhluk*> test;
    test.insertLast(new Carnivore);
    test.insertLast(new Herbivore);
    test.insertLast(new Omnivore);
    test.insertLast(new Bakteri);
    test.insertLast(new Men);
    test.insertLast(new Female);
    test.insertLast(new Beracun);
    test.insertLast(new NonBeracun);
    for (int i = 0; i < 8; i++) {
        Makhluk *t = test.deleteFirst();
        A.setMakhluk(i, 0, t);
        A.setBoard(i, 0, c);
        c++;
        cout << "ID: " << t->getID() << endl;
        cout << "Type: " << t->getType() << endl;
        cout << "Power: " << t->getPower() << endl;
        cout << "CurrT: " << t->getCurrT() << endl;
        cout << "Arah: " << t->getArah() << endl;
        cout << "Char: " << t->getChar() << endl;
        cout << endl;
        test.insertLast(t);
    }
    for (int i = 0; i < 8; i++){
        A.display();
        A.moveAll();
    }
    return 0;
}