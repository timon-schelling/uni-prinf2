#ifndef VERHALTEN_H
#define VERHALTEN_H

#include <iostream>
using namespace std;

#include "Fahrzeug.h"
#include "Weg.h"

class Verhalten {
protected:
    Weg& p_rWeg;

public:
    Verhalten(Weg& weg) : p_rWeg(weg) { };
    virtual ~Verhalten() = default;
    virtual double dStrecke(Fahrzeug& fahrzeug, double dDeltaZeit) = 0;
    Weg& getWeg() {
        return p_rWeg;
    }
};

#endif // VERHALTEN_H
