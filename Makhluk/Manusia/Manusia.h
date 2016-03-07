//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#ifndef MANUSIA_H
#define MANUSIA_H

#include "../Makhluk.h"

class Manusia : public Makhluk {
public:
    /**
     * Constructor for class Manusia
     * @param type type is a string that defines the type of Manusia Constructed, Male or Female
     */
    Manusia(string type, char c);

    /**
     * Deconstructor for class Manusia
     */
    virtual ~Manusia();

    /**
     * Virtual Procedure for Manusia to eat another Manusia or Makhluk and gain 0.1 power of its victim
     * @param M M is a pointer to Makhluk
     */
    virtual void makan(Makhluk *M); //Hewan akan memakan makhluk lain dengan gain power 10% dari power makhluk yang dimakan

    /**
     * Virtual Function that randomizes the power of Manusia Constructed, ranged 20 - 50 for Male and 20 - 40 for female
     * @return x x is the power randomized in the type double
     */
    virtual double randomizePower();

    /**
     * Virtual Function that randomizes the Direction of Manusia ranged 0 - 7
     * @return x x is the Direction randomizes in the type int
     */
    virtual int randomizeDir();

    /**
     * Generate the deltaT of Manusia
     * The value ranges form 2 to 4
     * @return deltaT value
     */
    virtual int randomizeT();
};

#endif //MANUSIA_H
