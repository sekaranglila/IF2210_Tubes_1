//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#include "Tumbuhan.h"

//ctor
Tumbuhan::Tumbuhan(string type) : Makhluk(randomizePower(), randomizeDir(), type, randomizeT()) {

}

//dtor
Tumbuhan::~Tumbuhan(){

}

//Method lainnya
double Tumbuhan::randomizePower() {
    return 0;
}

int Tumbuhan::randomizeDir() {
    return 0;
}

int Tumbuhan::randomizeT() {
    return (rand() % 3) + 3;
}