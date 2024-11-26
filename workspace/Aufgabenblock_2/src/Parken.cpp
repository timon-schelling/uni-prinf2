#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>
#include "Parken.h"
#include "global.h"

extern double dGlobaleZeit;

double Parken::dStrecke(Fahrzeug& fahrzeug, double dDeltaZeit) {
    if (!p_bStartErreicht && dGlobaleZeit >= p_dStartZeit) {
#ifdef _DEBUG
        std::cout << "Fahrzeug \"" << fahrzeug.getName() << "\" hat jetzt mit dem Parken begonnen.\n";
#endif
        p_bStartErreicht = true;
        throw Losfahren(fahrzeug, fahrzeug.getAktuelleWeg());
    }
    if (!p_bStartErreicht) {
        return 0.0;
    }
    // Nach Erreichen des Startzeitpunkts bewegt sich das Fahrzeug weiterhin oder bleibt geparkt
    return 0.0;
}