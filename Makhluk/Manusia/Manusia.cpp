//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#include "Manusia.h"

Manusia::Manusia(int power, char type) : Makhluk(power, randomizeDir(), type, randomizeT()) {

}

Manusia::~Manusia() { }

void Manusia::makan(Makhluk *M) {
//Kamus Lokal
    double x;

//Algoritma
    x = (double) (getPower() + (0.1 * M->getPower()));
    setPower(x);
}

int Manusia::randomizeDir() {
    int x = rand() % 8; //generate integer arah y secara random antara 0 - 7
    return x;
}

int Manusia::randomizeT() {
    return (rand() % 3) + 2;
}
