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
    Matriks M;
    LinkedList<Makhluk*> test;
    test.insertLast(new Carnivore);
    test.insertLast(new Herbivore);
    test.insertLast(new Omnivore);
    test.insertLast(new Bakteri);
    test.insertLast(new Men);
    test.insertLast(new Female);
    test.insertLast(new Beracun);
    test.insertLast(new NonBeracun);
    for (int i = 0; i < test.getSize(); i++) {
        M.putMakhluk(test[i]);
    }
    M.display();
    return 0;
}