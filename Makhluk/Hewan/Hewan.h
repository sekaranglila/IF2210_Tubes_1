#include "../Makhluk.h"
#ifndef HEWAN_H
#define HEWAN_H

class Hewan : public Makhluk {
public:
    //ctor
    /**
     * Constructor of Hewan
     * @param type string that will defines what type of Makhluk it is
     */
    Hewan(string type, char c);

    //dtor
    /**
     * Destructor of Hewan
     */
    virtual ~Hewan();

    //method lain
    /**
     * Virtual method of Hewan to eat something and gain 10% power of its prey
     * @param M Makhluk that will be eaten by this Hewan
     */
    virtual void makan(const Makhluk &M);

    /**
     * Virtual method of Hewan to generate its power, with range from 20 to 40
     */
    virtual double randomizePower();

    /**
     * Virtual method of Hewan to generate its arah, with range from 0 to 7
     */
    virtual int randomizeDir();

    /**
     * Generate the deltaT of a Makhluk;
     */
    virtual int randomizeT();
};


#endif //HEWAN_H
