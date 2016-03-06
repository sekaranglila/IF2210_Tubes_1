//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#ifndef MEN_H
#define MEN_H

#include "Manusia.h"

class Men: public Manusia {
public:
    /**
     * Construtor for the Men class which inherits functions and voids from class Manusia
     */
    Men();

    /**
     * Deconstructor for the Men class
     */
    virtual ~Men();

    /**
     * Virtual Function that randomizes the power of Manusia Constructed, ranged 20 - 50 for Male and 20 - 40 for female
     * @return x x is the power randomized in the type double
     */
    virtual double randomizePower();
};

#endif //Men_H
