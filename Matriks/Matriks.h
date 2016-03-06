
/**
* Class for the board that contains characters
* Characters represent living things in the world
* Character '*' represent empty or that there is no living thing
**/


#ifndef MATRIKS_H
#define MATRIKS_H
#include <iostream>
#include <fstream>
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

    /**
     * Constructor of Matrix Board
     * Read the matrix from an external file
     * @param filename The name of the file/path that will be opened
     */
    Matriks(const char* filename);

    //Cctor
    /**
     * Copy constructor of Matrix Board
     */
    Matriks(const Matriks& M);

    //Dtor
    /**
     * Destructor of Matrix Board
     */
    virtual ~Matriks();

    /**
     * Display the content of Matrix Board to the screen
     */
    void display();

    /**
     * Save the matrix to an external file
     * @param filename The name of the file/path for the matrix to be saved
     */
    void save(const char* filename);

    /**
     * Put a Makhluk randomly on a cell that is not occupied yet by other Makhluk
     * @param m Makhluk
     */
    void putMakhluk(Makhluk *m);

    /**
     * Move the item to a coordinate
     * @param x The x coordinate of the item that will be moved
     * @param y The y coordinate of the item that will be moved
     * @param movx The x coordinate for the movement
     * @param movy The y coordinate for the movement
     */
    void move(int x, int y, int movx, int movy);

    //Setter
    /**
    * @param x The x coordinate of the item that will be set
    * @param y The y coordinate of the item that will be set
    * @param c The character that will be set on the board
    **/
    void setBoard(int x, int y, Matriks* c);

    //Getter
    /**
    * @param x The x coordinate for the item that will be returned
    * @param y The y coordinate for the item that will be returned
    * @return char The character that is in the coordinate
    **/
    Matriks* getBoard(int x, int y);

private:
    /**
    * The Board itself
    **/
    Makhluk ***board;

    /**
    * The X dimension for Matrix Board
    **/
    int dimX;

    /**
    * The Y dimension for Matrix Board
    **/
    int dimY;

    const static int maxX = 10;
    const static int maxY = 10;
};

#endif // MATRIKS_H
