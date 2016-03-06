//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#include "Female.h"

Female::Female() : Manusia(randomizePower(), 'F'){

}

Female::~Female() {

}

double Female::randomizePower() {
    return (rand() % 21) + 20;
}
