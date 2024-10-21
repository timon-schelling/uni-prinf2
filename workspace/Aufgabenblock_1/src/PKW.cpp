#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.

#include "PKW.h"
#include "Fahrzeug.h"

extern double dGlobaleZeit;

PKW::PKW(
    const std::string& name,
    double maxGeschwindigkeit,
    double verbrauch,
    double tankvolumen
) : Fahrzeug(name, maxGeschwindigkeit),
    p_dVerbrauch(verbrauch),
    p_dTankvolumen(tankvolumen),
    p_dTankinhalt(tankvolumen / 2.0)
{
#ifdef _DEBUG
    std::cout << "PKW \"" << p_sName << "\" mit Verbrauch " << p_dVerbrauch
              << " l/100km und einem Tankvolumen von " << p_dTankvolumen << " Litern wurde erstellt.\n";
#endif
}

PKW::~PKW() {}

// Implementierung von dGeschwindigkeit mit Tankberechnung
double PKW::dGeschwindigkeit() {
    // Berechne die maximal mögliche Strecke, die mit dem aktuellen Tankinhalt gefahren werden kann
    double dMaxFahrbareStrecke = (p_dTankinhalt / p_dVerbrauch) * 100.0;

    // Berechne die Zeitdifferenz seit der letzten Simulation
    double dDeltaZeit = dGlobaleZeit - p_dZeit;

    // Berechne die Strecke, die mit der maximalen Geschwindigkeit zurückgelegt werden würde
    double dStreckeMitMaxGeschwindigkeit = p_dMaxGeschwindigkeit * dDeltaZeit;

    // Wenn die Tankfüllung ausreicht, um mit maximaler Geschwindigkeit zu fahren
    if (dStreckeMitMaxGeschwindigkeit <= dMaxFahrbareStrecke) {

        // Setze den Tankinhalt auf den verbleibenden Wert
        p_dTankinhalt -= (dStreckeMitMaxGeschwindigkeit / 100.0) * p_dVerbrauch;

        return p_dMaxGeschwindigkeit;
    } else {
        // Berechne, wie viel Geschwindigkeit möglich ist, basierend auf dem verbleibenden Tankinhalt
        double dMöglicheGeschwindigkeit = (dMaxFahrbareStrecke / dDeltaZeit);

        // Setze den Tankinhalt auf 0, da der PKW dann nicht mehr weiterfahren kann
        p_dTankinhalt = 0.0;

        return dMöglicheGeschwindigkeit;
    }
}

double PKW::dTanken(double dMenge) {
    double dGetankteMenge = 0.0;

    // Wenn dMenge größer als das Tankvolumen ist, wird nur bis zum Tankvolumen getankt
    if (dMenge >= p_dTankvolumen) {
        dGetankteMenge = p_dTankvolumen - p_dTankinhalt;
        p_dTankinhalt = p_dTankvolumen;
    } else {
        dGetankteMenge = dMenge;
        p_dTankinhalt += dMenge;
    }

    return dGetankteMenge;
}

std::string PKW::sType() const {
    return "PKW";
}

std::string PKW::sAusgeben() {
	return Fahrzeug::sZeile(p_iID, sType(), p_sName, p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke, p_dTankinhalt);
}
