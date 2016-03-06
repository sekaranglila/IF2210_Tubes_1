//
// Created by SekarAnglilaHapsari on 02/03/2016.
//

#ifndef TUMBUHAN_H
#define TUMBUHAN_H

#include "../Makhluk.h"

class Tumbuhan : public Makhluk {
public :
    /**
     * Constructor for class Tumbuhan
     * @param type A string that defines the type of Tumbuhan Constructed, which is Beracun or NonBeracun
     */
    Tumbuhan(char type);

    /**
     * Deconstructor for class Tumbuhan
     */
    virtual ~Tumbuhan();

    /**
     * Eating other Makhluk
     * As Tumbuhan cannot eat other Makhluk, it does not do anything
     */
    virtual void makan(Makhluk *M) { }

    /**
     * Generate the power of Tumbuhan
     * @return 0 (initial power of Tumbuhan)
     */
    virtual double randomizePower();

    /**
     * Generate the direction of Tumbuhan
     * The direction is set to 0 as it does not move
     * @return 0 (direction of Tumbuhan)
     */
    virtual int randomizeDir();

    /**
     * Generate the deltaT of Tumbuhan
     * The range of deltaT will be 3-5
     * @return The deltaT of Tumbuhan
     */
    virtual int randomizeT();
};

#endif //TUMBUHAN_H
