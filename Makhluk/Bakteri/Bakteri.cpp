#include "Bakteri.h"

Bakteri::Bakteri() : Makhluk(randomizePower(), randomizeDir(), "Bakteri", 'B', randomizeT()) { }

Bakteri::~Bakteri() { }

void Bakteri::makan(const Makhluk &M) {
    double x;

    if (M.getPower() < getPower()) {
        x = getPower() + (0.5 * M.getPower());
    } else {
        x = 1.2 * getPower();
    }
    setPower(x);
}

double Bakteri::randomizePower() {
    double x = rand() % 4 + 2; // Generate integer power x secara random antara 2 - 5
    return x;
}

int Bakteri::randomizeDir() {
    int y = rand() % 8; // Generate integer arah y secara random antara 0 - 7
    return y;
}

int Bakteri::randomizeT() {
    return (rand() % 2) + 1;
}

void Bakteri::setBattlePowerToOpponent(const Makhluk &M) {
    if (M.getType() == "NonBeracun" || M.getType() == "Beracun") {
        setBattlePower(-1); // Will always lose
    } else {
        setBattlePower(getPower()); // Normal power
    }
}