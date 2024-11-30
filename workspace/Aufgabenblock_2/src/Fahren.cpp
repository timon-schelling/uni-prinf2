#include <iostream>
using namespace std;

#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahren.h"
#include "Streckenende.h"

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeit) {
    double dMoeglicheStrecke = fahrzeug.dGeschwindigkeit() * dZeit;

    double dVerbleibendeStrecke = p_rWeg.getLaenge() - fahrzeug.getAbschnittStrecke() - 1e-6;

    if (dVerbleibendeStrecke <= 0) {
        // Fahrzeug steht bereits am Ende des Weges
        throw Streckenende(fahrzeug, p_rWeg);
    } else if (dMoeglicheStrecke >= dVerbleibendeStrecke) {
        // Fahrzeug erreicht das Ende des Weges
        return dVerbleibendeStrecke;
    } else {
        // Fahrzeug kann die geplante Strecke fahren
        return dMoeglicheStrecke;
    }
}
