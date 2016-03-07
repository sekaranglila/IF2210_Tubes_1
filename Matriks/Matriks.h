
/**
* Class for the board that contains characters
* Characters represent living things in the world
* Character '*' represent empty or that there is no living thing
**/


#ifndef MATRIKS_H
#define MATRIKS_H
#include <iostream>
#include <fstream>
#include "../LinkedList/LinkedList.h"
#include "../Makhluk/Makhluk.h"

class Matriks
{
public:
    //Ctor
    /**
     * Constructor of Matrix Board
     * Initializes with empty Board, with char '*'
     */
    Matriks();

    //Cctor
    /**
     * Copy constructor of Matrix Board
     **/

    Matriks(const Matriks& M);

    //Dtor
    /**
     * Destructor of Matrix Board
     **/

    virtual ~Matriks();

    /**
    * Display the content of Matrix Board to the screen
    **/

    void display();

    /**
     * Save the matrix to an external file
     * @param filename The name of the file/path for the matrix to be saved
     */
    void save(const char* filename);

    /**
     * Trigger the Makhluk to do its action
     */
    void action(Makhluk *M);

    /**
     * Move the item to a coordinate
     * @param x The x coordinate of the item that will be moved
     * @param y The y coordinate of the item that will be moved
     * @param movx The x coordinate for the movement
     * @param movy The y coordinate for the movement
     */
    void move(int x, int y, int movx, int movy);

    /**
     * Move the item to a coordinate according to its movement direction
     * @param M Makhluk
     */
    void move(Makhluk *M);

    /**
     * Set the pointer to Makhluk
     * @param x x position
     * @param y y position
     * @param M Makhluk
     */
    void putMakhluk(int x, int y, Makhluk *M);

    /**
     * Put a Makhluk in a random position
     * @param M Makhluk
     */
    void putMakhluk(Makhluk *M);

    /**
     * Delete a Makhluk
     */
    void deleteMakhluk(Makhluk *M);

    /**
     * A battle between two Makhluk
     * @param M1 Makhluk
     * @param M2 Makhluk
     */
    void battle(Makhluk *M1, Makhluk *M2);

private:
    /**
     * The Board itself
     */
    Makhluk*** board;

    /**
     * The X dimension for Matrix Board
     */
    int dimX;

    /**
     * The Y dimension for Matrix Board
     */
    int dimY;

    const static int maxX = 10;
    const static int maxY = 10;
};

#endif // MATRIKS_H
