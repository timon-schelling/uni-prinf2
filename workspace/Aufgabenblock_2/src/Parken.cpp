#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>
#include "Parken.h"
#include "global.h"

#include "Losfahren.h"

extern double dGlobaleZeit;

double Parken::dStrecke(Fahrzeug& fahrzeug, double dDeltaZeit) {
    if (!p_bStartErreicht && dGlobaleZeit >= p_dStartZeit - 1e-6) {
        p_bStartErreicht = true;
        throw Losfahren(fahrzeug, p_rWeg);
    }
    if (!p_bStartErreicht) {
        return 0.0;
    }
    return 0.0;
}