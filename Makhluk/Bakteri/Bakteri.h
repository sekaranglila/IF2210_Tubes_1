#include "../Makhluk.h"
#ifndef BAKTERI_H
#define BAKTERI_H

class Bakteri : public Makhluk {
public:
    //ctor
    /**
     * Constructor of Bakteri
     */
    Bakteri();

    //dtor
    /**
     * Destructor of Bakteri
     */
    virtual ~Bakteri();

    //method lain
    /**
     * Virtual method of Bakteri to eat something, with condition if M's power is greater, it gain 20% of this Bakteri power
     * else, this Bakteri eats M and gain 50% of M's power
     * @param M Makhluk that will be eaten by this Bakteri
     */
    virtual void makan(Makhluk *M);

    /**
     * Virtual method of Bakteri to generate its power, range from 2 to 5
     */
    virtual double randomizePower();

    /**
     * Virtual method of Bakteri to generate its arah, range from 0 to 7
     */
    virtual int randomizeDir();

    /**
     * Generate the deltaT of Bakteri
     * The value ranges from 1 to 2
     */
    virtual int randomizeT();

    /**
     * Set the battle power of Bakteri respective to the other Makhluk
     */
    virtual void updateBattlePower(const Makhluk &M);
};

#endif //BAKTERI_H
