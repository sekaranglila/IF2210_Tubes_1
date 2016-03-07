#include "Hewan.h"

Hewan::Hewan(string type) : Makhluk(randomizePower(), randomizeDir(), type, randomizeT()) { }

Hewan::~Hewan() { }

void Hewan::makan(Makhluk *M) {
    double x = getPower() + (0.1 * M->getPower());

    setPower(x);
}

double Hewan::randomizePower() {
    double x = rand() % 21 + 20; //generate integer power x secara random antara 20 - 40
    return x;
}

int Hewan::randomizeDir() {
    int y = rand() % 8; //generate integer arah y secara random antara 0 - 7
    return y;
}

int Hewan::randomizeT() {
    return (rand() % 3) + 3;
}