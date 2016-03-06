#include "Makhluk.h"

using namespace std;

int Makhluk::idCounter = 0;

//ctor
Makhluk::Makhluk(double _power, int _arah, char _type, int _deltaT) : id(idCounter++), power(_power), status(1), type(_type), arah(_arah),
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

char Makhluk::getType() {
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

void Makhluk::setType(char s) {
    type = s;
}

void Makhluk::setArah (int x) {
    arah = x;
}

void Makhluk::setPos(int x, int y) {
    pos[0] = x;
    pos[1] = y;
}

// Other methods
void Makhluk::decTime() {
    --currT;
}

void Makhluk::resetTime() {
    currT = deltaT;
}
