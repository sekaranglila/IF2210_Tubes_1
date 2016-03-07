#include "Makhluk.h"

using namespace std;

int Makhluk::idCounter = 0;

//ctor
Makhluk::Makhluk(double _power, int _arah, string _type, char _c, int _deltaT) : id(idCounter++), power(_power), status(1), type(_type),
                                                                                 c(_c), arah(_arah), deltaT(_deltaT), currT(_deltaT),
                                                                                 battlePower(_power) { };

//dtor
Makhluk::~Makhluk() { }

//getter
double Makhluk::getPower() const {
    return power;
}

int Makhluk::getStatus() const {
    return status;
}

string Makhluk::getType() const {
    return type;
}

int Makhluk::getArah() const {
    return arah;
}

int Makhluk::getID() const {
    return id;
}

int Makhluk::getDeltaT() const {
    return deltaT;
}

int Makhluk::getCurrT() const {
    return currT;
}

int Makhluk::getX() const {
    return pos[0];
}

int Makhluk::getY() const {
    return pos[1];
}

char Makhluk::getChar() const {
    return c;
}

double Makhluk::getBattlePower() const {
    return battlePower;
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

void Makhluk::setChar(char c1) {
    c = c1;
}

void Makhluk::setPos(int x, int y) {
    pos[0] = x;
    pos[1] = y;
}

void Makhluk::setBattlePower(int power) {
    battlePower = power;
}

// Other methods
void Makhluk::decTime() {
    --currT;
}

void Makhluk::resetTime() {
    currT = deltaT;
}