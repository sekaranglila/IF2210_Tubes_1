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
    Makhluk(double _power, int _arah, string _type, int _deltaT);

    //dtor
    /**
     * Destructor of Makhluk
     */
    virtual ~Makhluk();

    //getter
    /**
     * Get the power of this Makhluk
     * @return power return double typed attribute
     */
    double getPower();

    /**
     * Get the status of this Makhluk
     * @return status return integer 1 or 0
     */
    int getStatus();

    /**
     * Get the ID of this Makhluk
     * @return id return integer generated from idCounter
     */
    int getID();

    /**
     * Get the direction of this Makhluk
     * @return arah return integer between 0 - 7
     */
    int getArah();

    /**
     * Get the type of this Makhluk
     * @return type return string depends on its child
     */
    string getType();

    /**
     * Get the deltaT of Makhluk
     * @return deltaT of Makhluk
     */
    int getDeltaT();

    /**
     * Get the currT of Makhluk
     * @return currT of Makhluk
     */
    int getCurrT();

    //setter
    /**
     * Set the power of this Makhluk
     * @param x the amount of power to be set to Makhluk
     */
    void setPower(double);

    /**
     * Set the status of this Makhluk to 1
     */
    void setAlive(); //set status makhluk hidup

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

    //method lain
    /**
     * Eating other Makhluk
     * @param M what Makhluk that is being eaten
     */
    virtual void makan(Makhluk *M) = 0;

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
     * Get the char of Makhluk
     */
    char getChar();

    /**
     * Set the char of Makhluk
     */
    void setChar(char c1);

private:
    static int idCounter; // Sebuah pencacah jumlah makhluk hidup yang telah dibuat
    string type; // Mencatat type dari makhluk tersebut
    int id; // Id sebuah makhluk hidup. Id makhluk hidup yang pertama kali diciptakan adalah 0
    int arah; // Memberi arah gerak dari makhluk dengan timur = 0 hingga tenggara = 7, secara berlawanan arah jarum jam.
    double power; // Kekuatan suatu makhluk
    int deltaT; // Besar deltaT sebuah makhluk untuk melakukan seuatu aksi
    int currT;
    int pos[2]; // pos[0] merupakan posisi baris, dan pos[1] merupakan posisi kolom sebuah Makhluk
    int status; // Status hidup atau mati makhluk. Hidup = 1, makhluk = 0
    char c; //Karakter yang ditampilkan pada board
};


#endif //MAKHLUK_H