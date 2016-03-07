#include "Makhluk.h"

using namespace std;

int Makhluk::idCounter = 0;

//ctor
Makhluk::Makhluk(double _power = 0, int _arah = 0, string _type = "", int _deltaT = 0) : id(idCounter++), power(_power), status(1), type(_type), arah(_arah),
                                                           deltaT(_deltaT), currT(_deltaT) { }

//dtor
Makhluk::~Makhluk() { }

//getter
double Makhluk::getPower(){
    return power;
}

int Makhluk::getStatus() {
    return status;
}

string Makhluk::getType() {
    return type;
}

int Makhluk::getArah() {
    return arah;
}

int Makhluk::getID() {
    return id;
}

int Makhluk::getDeltaT() {
    return deltaT;
}

int Makhluk::getCurrT() {
    return currT;
}

//setter
void Makhluk::setPower(double i) {
    power = i;
}

void Makhluk::setDead() {
    status = 0;
}

void Makhluk::setAlive() {
    status = 1;
}

void Makhluk::setType(string s) {
    type = s;
}

void Makhluk::setArah (int x) {
    arah = x;
}

// Other methods
void Makhluk::decTime() {
    --currT;
}

void Makhluk::resetTime() {
    currT = deltaT;
}

char Makhluk::getChar() {
    return c;
}

void Makhluk::setChar(char c1) {
    c = c1;
}
