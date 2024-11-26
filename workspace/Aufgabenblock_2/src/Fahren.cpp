#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>

double Fahren::dStrecke(Fahrzeug& aFahrzeug, double dZeit) {
    double dMoeglicheStrecke;
    if (aFahrzeug.dGeschwindigkeit() > p_rWeg.getTempolimit()) {
        dMoeglicheStrecke = p_rWeg.getTempolimit() * dZeit;
    } else {
        dMoeglicheStrecke = aFahrzeug.dGeschwindigkeit() * dZeit;
    }
    double dVerbleibendeStrecke = p_rWeg.getLaenge() - aFahrzeug.getAbschnittStrecke();

    if (dVerbleibendeStrecke <= 0) {
        // Fahrzeug steht bereits am Ende des Weges
#ifdef _DEBUG
        std::cout << "Fahrzeug \"" << aFahrzeug.getName() << "\" steht am Ende des Weges \""
                  << p_rWeg.getName() << "\"." << std::endl;
#endif
        throw Streckenende(fahrzeug, fahrzeug.getAktuelleWeg());
        return 0.0;
    } else if (dMoeglicheStrecke >= dVerbleibendeStrecke) {
        // Fahrzeug erreicht das Ende des Weges
#ifdef _DEBUG
        std::cout << "Fahrzeug \"" << aFahrzeug.getName() << "\" hat das Ende des Weges \""
                  << p_rWeg.getName() << "\" erreicht." << std::endl;
#endif
        return dVerbleibendeStrecke;
    } else {
        // Fahrzeug kann die geplante Strecke fahren
        return dMoeglicheStrecke;
    }
}