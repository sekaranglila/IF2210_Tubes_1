#include "Makhluk.h"
#include "Hewan/Herbivore.h"
#include "Hewan/Carnivore.h"
#include "Hewan/Omnivore.h"
#include "Bakteri/Bakteri.h"
#include "Manusia/Men.h"
#include "Manusia/Female.h"
#include "Tumbuhan/Beracun.h"
#include "Tumbuhan/NonBeracun.h"

using namespace std;

int Makhluk::idCounter = 0;

//ctor
Makhluk::Makhluk(double _power, int _arah, string _type, char _c, int _deltaT) : id(idCounter++), power(_power), status(1), type(_type),
                                                                                 c(_c), arah(_arah), deltaT(_deltaT), currT(_deltaT),
                                                                                 battlePower(_power) { };

//dtor
Makhluk::~Makhluk() { }

/* GETTER */
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

/* SETTER */
void Makhluk::setPower(double i) {
    power = i;
}

void Makhluk::setDead() {
    status = 0;
}

void Makhluk::setType(string s) {
    type = s;
}

void Makhluk::setArah (int x) {
    arah = x;
}

void Makhluk::setPos(int x, int y) {
    pos[0] = x;
    pos[1] = y;
}

void Makhluk::setBattlePower(int power) {
    battlePower = power;
}

/* OTHER METHODS */
void Makhluk::decTime() {
    --currT;
}

void Makhluk::resetTime() {
    currT = deltaT;
}

Makhluk* Makhluk::createRandomMakhluk() {
    int num = rand() % 8;
    if (num == 0) {
        return new Herbivore;
    } else if (num == 1) {
        return new Carnivore;
    } else if (num == 2) {
        return new Omnivore;
    } else if (num == 3) {
        return new Bakteri;
    } else if (num == 4) {
        return new Men;
    } else if (num == 5) {
        return new Female;
    } else if (num == 6) {
        return new Beracun;
    } else {
        return new NonBeracun;
    }
}