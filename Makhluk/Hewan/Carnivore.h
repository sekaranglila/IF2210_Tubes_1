#include "Hewan.h"
#ifndef CARNIVORE_H
#define CARNIVORE_H

class Carnivore : public Hewan {
public:
    //ctor
    /**
     * Constructor of Carnivore
     */
    Carnivore();

    //dtor
    /**
     * Destructor of Carnivore
     */
    virtual ~Carnivore();
};

#endif //CARNIVORE_H
