#include "Matriks.h"

using namespace std;

Matriks::Matriks()
{
    board = new Makhluk**[maxX];
    for (int i = 0; i < maxX; i++){
        board[i] = new Makhluk*[maxY];
        for (int j = 0; j < maxY; j++){
            board[i][j] = nullptr;
        }
    }
    dimX = maxX;
    dimY = maxY;
}

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
    for (int i = 0; i < dimX; i++) {
        delete[] board[i];
    }
    delete[] board;
}

void Matriks::display(){
    for (int i = 0; i < dimX; i++){
        for (int j = 0; j < dimY; j++){
            if (board[i][j] == nullptr) {
                cout << "* ";
            } else {
                cout << board[i][j]->getType() << " ";
            }
        }
        cout << endl;
    }
}

void Matriks::save(const char* filename){
    ofstream out(filename, ios::out);
    for (int i = 0; i < dimX; i++){
        for (int j = 0; j < dimY; j++){
            out << board[i][j]->getType();
            if (j != dimY - 1){
                out << " ";
            }
        }
        if (i != dimX - 1){
            out << endl;
        }
    }
}


void Matriks::putMakhluk(Makhluk *m) {
    do {
        int x = rand() % 10;
        int y = rand() % 10;
        if (board[x][y] == nullptr) {
            m->setPos(x, y);
            board[x][y] = m;
            break;
        }
    } while (true);
}

//void Matriks::move(int x, int y, int movx, int movy){
//    char temp;
//    if (x < dimX && y < dimY && movx < dimX && movy < dimY){
//        temp = board[x][y];
//        if (board[movx][movy] != '*'){
//            cout << "Terdapat makhluk pada koordinat tersebut." << endl;
//        } else {
//            board[x][y] = '*';
//            board[movx][movy] = temp;
//        }
//    } else {
//        cout << "Koordinat melebihi ukuran board." << endl;
//    }
//}
//
//void Matriks::setBoard(int x, int y, char c){
//    if (x < dimX && y < dimY){
//        board[x][y] = c;
//    } else {
//        cout << "Koordinat melebihi ukuran board." << endl;
//    }
//}
//
//char Matriks::getBoard(int x, int y){
//    if ((x < dimX) && (y < dimY)){
//        return board[x][y];
//    } else {
//        cout << "Koordinat melebihi ukuran board." << endl;
//        return ' ';
//    }
//}
