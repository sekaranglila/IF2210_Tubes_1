#include "Matriks.h"

using namespace std;

Matriks::Matriks()
{
    board = new Makhluk**[maxX];
    for (int i = 0; i < maxX; i++){
        board[i] = new Makhluk*[maxY];
        for (int j = 0; j < maxY; j++){
            board[i][j] = NULL;
        }
    }
    dimX = maxX;
    dimY = maxY;
}

/* Matriks::Matriks(const char* filename){
    load(filename);
} */

Matriks::Matriks(const Matriks& M){
    dimX = M.dimX;
    dimY = M.dimY;
    board = new Makhluk**[dimX];
    for (int i = 0; i < maxX; i++){
        board[i] = new Makhluk*[dimY];
        for (int j = 0; j < maxY; j++){
            board[i][j] = M.board[i][j];
        }
    }
}

Matriks::~Matriks()
{
    delete[] board;
}

void Matriks::display(){
    for (int i = 0; i < dimX; i++){
        for (int j = 0; j < dimY; j++){
            if (board[i][j] == NULL){
                cout << "*" << " ";
            } else {
                cout << board[i][j]->getChar() << " ";
            }
        }
        cout << endl;
    }
}

/* void Matriks::load(const char* filename){
    char c;
    int x = 0, y = 0;
    char b[100][100];

    ifstream in(filename, ios::in);
    while (in.get(c)){
        b[y][x] = c;
        x++;
        in.get(c); //Skips a space
        if ((int)c == 10){
            y++;
            x = 0;
        }
    }
    y++; //Last line
    board = new Makhluk**[x];
    for (int i = 0; i < x; i++){
        board[i] = new Makhluk*[y];
        for (int j = 0; j < y; j++){
            if (b[i][j] != NULL){
                board[i][j] = b[i][j];
            }
        }
    }
    dimX = x;
    dimY = y;
} */

void Matriks::save(const char* filename){
    ofstream out(filename, ios::out);
    for (int i = 0; i < dimX; i++){
        for (int j = 0; j < dimY; j++){
            out << board[i][j]->getChar();
            if (j != dimY - 1){
                out << " ";
            }
        }
        if (i != dimX - 1){
            out << endl;
        }
    }
}

void Matriks::move(int x, int y, int movx, int movy){
    Makhluk* temp;

    if (x < dimX && y < dimY && movx < dimX && movy < dimY){
        temp = board[x][y];
        if (board[movx][movy] != NULL){
            cout << "Terdapat makhluk pada koordinat " << movx << " " << movy << endl;
        } else {
            board[x][y] = NULL;
            board[movx][movy] = temp;
        }
    } else {
        int a = board[x][y]->getArah();
        a += 4;
        if (a > 7){
            a -= 7;
        }
        board[x][y]->setArah(a);
    }
}

void Matriks::setBoard(int x, int y, char c){
    if (x < dimX && y < dimY){
        board[x][y]->setChar(c);
    } else {
        cout << "Koordinat melebihi ukuran board." << endl;
    }
}

char Matriks::getBoard(int x, int y){
    if ((x < dimX) && (y < dimY)){
        return board[x][y]->getChar();
    } else {
        cout << "Koordinat melebihi ukuran board." << endl;
        return ' ';
    }
}

void Matriks::setMakhluk(int x, int y, Makhluk* M){
    board[x][y] = M;
}

void Matriks::moveAll(){
    for (int i = 0; i < dimX; i++){
        for (int j = 0; j < dimY; j++){
            if (board[i][j] != NULL){
                int m = board[i][j]->getArah();
                switch(m){
                    case 0:
                    {
                        move(i, j, i-1, j);
                        break;
                    }
                    case 1:
                    {
                        move(i, j, i-1, j+1);
                        break;
                    }
                    case 2:
                    {
                        move(i, j, i, j+1);
                        break;
                    }
                    case 3:
                    {
                        move(i, j, i+1, j+1);
                        break;
                    }
                    case 4:
                    {
                        move(i, j, i+1, j);
                        break;
                    }
                    case 5:
                    {
                        move(i, j, i+1, j-1);
                        break;
                    }
                    case 6:
                    {
                        move(i, j, i, j-1);
                        break;
                    }
                    case 7:
                    {
                        move(i, j, i-1, j-1);
                        break;
                    }
                }
            }
        }
    }
}