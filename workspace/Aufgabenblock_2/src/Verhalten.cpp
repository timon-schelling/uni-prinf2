#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>

Verhalten::Verhalten(const Weg& weg) : p_rWeg(weg) { }

double Verhalten::dStrecke(Fahrzeug& fahrzeug, double dZeit) {
    double dMoeglicheStrecke = fahrzeug.dGeschwindigkeit() * dZeit;
    double dVerbleibendeStrecke = p_rWeg.getLaenge() - fahrzeug.getAbschnittStrecke();



    if (dMoeglicheStrecke >= dVerbleibendeStrecke) {
        // Fahrzeug kann nur noch die verbleibende Strecke fahren
        return dVerbleibendeStrecke;
    } else {
        // Fahrzeug kann die geplante Strecke fahren
        return dMoeglicheStrecke;
    }
}
