#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>

#include "global.h"

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

PKW::PKW() : PKW("", 0.0, 0.0, 0.0) {}

// Implementierung von dGeschwindigkeit mit Tankberechnung
double PKW::dGeschwindigkeit() {
    return p_dMaxGeschwindigkeit;
}

void PKW::vSimulieren()
{
	if (p_dTankinhalt > 0)
	{
		double dGesamtStreckeVorher = p_dGesamtStrecke;
		Fahrzeug::vSimulieren();
		p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeVorher) * p_dVerbrauch / 100;
		if (p_dTankinhalt < 0) p_dTankinhalt = 0;
	}
}

double PKW::dTanken(double dMenge) {
    double dGetankteMenge = 0.0;

    // Wenn dMenge größer als das Tankvolumen ist, wird nur bis zum Tankvolumen getankt
    if (dMenge >= p_dTankvolumen - p_dTankinhalt) {
        dGetankteMenge = p_dTankvolumen - p_dTankinhalt;
        p_dTankinhalt = p_dTankvolumen;
    } else {
        dGetankteMenge = dMenge;
        p_dTankinhalt += dMenge;
    }

    return dGetankteMenge;
}

std::string PKW::sType() {
    return "PKW";
}

std::string PKW::sKopf() {
    std::ostringstream stringStream;
    vKopfPKW(stringStream);
    return stringStream.str();
}

void PKW::vKopf(std::ostream& stream) {
    vKopfPKW(stream);
}

void PKW::vAusgeben(std::ostream& stream) {
	vZeilePKW(stream, p_iID, p_sName, sType(), p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke, p_dAbschnittStrecke, p_dTankinhalt, p_dVerbrauch, p_dGesamtStrecke * p_dVerbrauch / 100);
}
