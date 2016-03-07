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

void Matriks::action(Makhluk *M) {
    M->decTime();
    if (M->getCurrT()) {
        M->resetTime();
        move(M);
    }
}

void Matriks::move(Makhluk *M) {
    int d = M->getArah();
    switch (d) {
        case 0:
            move(M->getX(), M->getY(), M->getX() + 1, M->getY());
            break;
        case 1:
            move(M->getX(), M->getY(), M->getX() + 1, M->getY() + 1);
            break;
        case 2:
            move(M->getX(), M->getY(), M->getX(), M->getY() + 1);
            break;
        case 3:
            move(M->getX(), M->getY(), M->getX() - 1, M->getY() + 1);
            break;
        case 4:
            move(M->getX(), M->getY(), M->getX() - 1, M->getY());
            break;
        case 5:
            move(M->getX(), M->getY(), M->getX() - 1, M->getY() - 1);
            break;
        case 6:
            move(M->getX(), M->getY(), M->getX(), M->getY() - 1);
            break;
        case 7:
            move(M->getX(), M->getY(), M->getX() + 1, M->getY() - 1);
            break;
    }
}

void Matriks::move(int x, int y, int movx, int movy) {
    if (movx < dimX && movy < dimY && movx >= 0 && movy >= 0) {
        if (board[movx][movy] != NULL) {
            battle(board[x][y], board[movx][movy]);
            if (board[x][y] != NULL) { // Won the battle
                move(x, y, movx, movy);
            }
        } else {
            board[movx][movy] = board[x][y];
            board[movx][movy]->setPos(movx, movy);
            board[x][y] = NULL;
        }
    } else {
        int a = board[x][y]->getArah();
        a += 4;
        if (a > 7){
            a -= 8;
        }
        board[x][y]->setArah(a);
        move(board[x][y]);
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

void Matriks::putMakhluk(int x, int y, Makhluk* M){
    M->setPos(x, y);
    board[x][y] = M;
}

void Matriks::putMakhluk(Makhluk *M) {
    int x, y;
    do {
        x = rand() % dimX;
        y = rand() % dimY;
    } while (board[x][y] != NULL);
    putMakhluk(x, y, M);
}

void Matriks::battle(Makhluk *M1, Makhluk *M2) {
    M1->updateBattlePower(*M2);
    M2->updateBattlePower(*M1);
    if (M1->getBattlePower() < M2->getBattlePower()) {
        deleteMakhluk(M1);
        M1->setDead();
    } else if (M1->getBattlePower() > M2->getBattlePower()) {
        deleteMakhluk(M2);
        M2->setDead();
    } else {
        deleteMakhluk(M1);
        deleteMakhluk(M2);
        M1->setDead();
        M2->setDead();
    }
}

void Matriks::deleteMakhluk(Makhluk *M) {
    board[M->getX()][M->getY()] = NULL;
}