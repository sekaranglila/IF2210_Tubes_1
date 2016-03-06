//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#include "Men.h"

Men::Men() : Manusia(randomizePower(), 'M'){

}

Men::~Men() {

}

double Men::randomizePower() {
    return (rand() % 31) + 20;
}
