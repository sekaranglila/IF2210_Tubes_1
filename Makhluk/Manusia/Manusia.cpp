//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#include "Manusia.h"

Manusia::Manusia(string type, char c) : Makhluk(randomizePower(), randomizeDir(), type, c, randomizeT()) {

}

Manusia::~Manusia() { }

void Manusia::makan(Makhluk *M) {
//Kamus Lokal
    double x;

//Algoritma
    x = (double) (getPower() + (0.1 * M->getPower()));
    setPower(x);
}

double Manusia::randomizePower() {
//Kamus Lokal
    double x;

//Algoritma
    if (getType() == "Male"){ //Jika manusia berkelamin pria
        x = rand() % 31 + 20; //generate integer power x secara random antara 20 - 50
    } else { //Jika manusia berkelamin wanita
        x = rand() % 21 + 20; //generate integer power x secara random antara 20 - 40
    }
    return x;
}

int Manusia::randomizeDir() {
//Kamus Lokal
    int x;

//Algoritma
    x = rand() % 8; //generate integer arah y secara random antara 0 - 7
    return x;
}

int Manusia::randomizeT() {
    return (rand() % 3) + 2;
}
