//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#ifndef FEMALE_H
#define FEMALE_H

#include "Manusia.h"

class Female: public Manusia {
public:
    /**
     * Construtor for the Female class which inherits functions and voids from class Manusia
     */
    Female();

    /**
     * Deconstructor for the Men class
     */
    virtual ~Female();

    /**
     * Virtual Function that randomizes the power of Manusia Constructed, ranged 20 - 50 for Male and 20 - 40 for female
     * @return x x is the power randomized in the type double
     */
    virtual double randomizePower();
};

#endif //Men_H
