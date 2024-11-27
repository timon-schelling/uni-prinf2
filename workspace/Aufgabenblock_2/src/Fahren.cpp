#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>
#include "Streckenende.h"

double Fahren::dStrecke(Fahrzeug& fahrzeug, double dZeit) {
    double dMoeglicheStrecke = fahrzeug.dGeschwindigkeit() * dZeit;

    double dVerbleibendeStrecke = p_rWeg.getLaenge() - fahrzeug.getAbschnittStrecke();

    if (dVerbleibendeStrecke <= 0) {
        // Fahrzeug steht bereits am Ende des Weges
        throw Streckenende(fahrzeug, p_rWeg);
        return 0.0;
    } else if (dMoeglicheStrecke >= dVerbleibendeStrecke) {
        // Fahrzeug erreicht das Ende des Weges
        return dVerbleibendeStrecke;
    } else {
        // Fahrzeug kann die geplante Strecke fahren
        return dMoeglicheStrecke;
    }
}