#ifndef VERHALTEN_H
#define VERHALTEN_H

#include "Weg.h"

class Fahrzeug;

class Verhalten {
protected:
    Weg& p_rWeg; // Referenz auf den Weg

public:
    Verhalten(const Weg& weg);

    virtual double dStrecke(Fahrzeug& aFahrzeug, double dZeit); // Methode zur Berechnung der Strecke
};

#endif // VERHALTEN_H
