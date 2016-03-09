//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#include "Tumbuhan.h"

//ctor
Tumbuhan::Tumbuhan(string type, char c) : Makhluk(randomizePower(), randomizeDir(), type, c, randomizeT()) {

}

//dtor
Tumbuhan::~Tumbuhan(){

}

//Method lainnya
double Tumbuhan::randomizePower() {
    return 0;
}

void Tumbuhan::photosynthesis() {
    setPower(getPower() + 1);
} 

int Tumbuhan::randomizeDir() {
    return 0;
}

int Tumbuhan::randomizeT() {
    return (rand() % 3) + 3;
}

void Tumbuhan::setBattlePowerToOpponent(const Makhluk &M){
    if ((M.getType() == "Herbivore") || (M.getType() == "Omnivore") || (M.getType() == "Men") || (M.getType() == "Female")){
        setBattlePower(-1); //Always Lose
    } else if (M.getType() == "Carnivore"){
        setBattlePower(0); //Carnivores and Plants do not interact
    } else {
        setBattlePower(getPower()); //Normal Power
    }
}
