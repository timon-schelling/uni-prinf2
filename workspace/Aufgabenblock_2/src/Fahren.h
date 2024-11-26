#ifndef FAHREN_H
#define FAHREN_H

#include "Verhalten.h"

class Fahren : public Verhalten {
public:
    Fahren(Weg& weg) : Verhalten(weg) { }
    virtual double dStrecke(Fahrzeug& fahrzeug, double dDeltaZeit) override;
};
#endif // FAHREN_H
