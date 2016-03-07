#ifndef MAKHLUK_H
#define MAKHLUK_H

#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Makhluk {
public:
    //ctor
    /**
     * Constructor of Makhluk
     * @param _power defines its power
     * @param _arah defines its direction
     * @param _type defines what type of Makhluk it is
     */
    Makhluk(double _power, int _arah, string _type, char _c, int _deltaT);

    //dtor
    /**
     * Destructor of Makhluk
     */
    virtual ~Makhluk();

    /* GETTER */

    /**
     * Get the power of this Makhluk
     * @return power return double typed attribute
     */
    double getPower() const;

    /**
     * Get the status of this Makhluk
     * @return status return integer 1 or 0
     */
    int getStatus() const;

    /**
     * Get the ID of this Makhluk
     * @return id return integer generated from idCounter
     */
    int getID() const;

    /**
     * Get the direction of this Makhluk
     * @return arah return integer between 0 - 7
     */
    int getArah() const;

    /**
     * Get the type of this Makhluk
     * @return type return string depends on its child
     */
    string getType() const;

    /**
     * Get the deltaT of Makhluk
     * @return deltaT of Makhluk
     */
    int getDeltaT() const;

    /**
     * Get the currT of Makhluk
     * @return currT of Makhluk
     */
    int getCurrT() const;

    /**
     * Get the x position of Makhluk
     * @return x position of Makhluk
     */
    int getX() const;

    /**
     * Get the y position of Makhluk
     * @return y position of Makhluk
     */
    int getY() const;

    /**
     * Get the char of Makhluk
     * @return character representation of Makhluk
     */
    char getChar() const;

    /**
     * Get the
     * @return battle power of Makhluk
     */
    double getBattlePower() const;

    /* SETTER */

    /**
     * Set the power of this Makhluk
     * @param x the amount of power to be set to Makhluk
     */
    void setPower(double);

    /**
     * Set the status of this Makhluk to 0
     */
    void setDead(); //set status makhluk menjadi mati

    /**
     * Set the type of this Makhluk
     * @param s string that defines what the Makhluk type will be
     */
    void setType(string);

    /**
     * Set the direction of this Makhluk
     * @param x integer of arah between 0 - 7
     */
    void setArah(int);

    /**
     * Set position of a Makhluk
     * @param x x position of Makhluk
     * @param y y position of Makhluk
     */
    void setPos(int x, int y);

    /**
     * Set battle power of Makhluk
     */
    void setBattlePower(int x);

    /* OTHER METHODS */

    /**
     * Eating other Makhluk
     * @param M what Makhluk that is being eaten
     */
    virtual void makan(const Makhluk &M) = 0;

    /**
     * Generate the power of a Makhluk.
     */
    virtual double randomizePower() = 0;

    /**
     * Generate the arah of a Makhluk
     */
    virtual int randomizeDir() = 0;

    /**
     * Generate the deltaT of a Makhluk
     */
    virtual int randomizeT() = 0;

    /**
     * Decrement currT by 1
     */
    void decTime();

    /**
     * Reset currT back to deltaT
     */
    void resetTime();

    /**
     * Set the battle power of a Makhluk based on the opponent's type
     * @param M The Makhluk opponent
     */
    virtual void setBattlePowerToOpponent(const Makhluk &M) { }

private:
    static int idCounter; // Sebuah pencacah jumlah makhluk hidup yang telah dibuat
    string type; // Mencatat type dari makhluk tersebut
    int id; // Id sebuah makhluk hidup. Id makhluk hidup yang pertama kali diciptakan adalah 0
    int arah; // Memberi arah gerak dari makhluk dengan timur = 0 hingga tenggara = 7, secara berlawanan arah jarum jam.
    double power; // Kekuatan suatu makhluk
    double battlePower;
    int deltaT; // Besar deltaT sebuah makhluk untuk melakukan seuatu aksi
    int currT;
    int pos[2]; // pos[0] merupakan posisi baris, dan pos[1] merupakan posisi kolom sebuah Makhluk
    int status; // Status hidup atau mati makhluk. Hidup = 1, mati = 0
    char c; //Karakter yang ditampilkan pada board
};


#endif //MAKHLUK_H
