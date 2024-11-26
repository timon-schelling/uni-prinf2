#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>

#include "global.h"

#include "PKW.h"
#include "Fahrzeug.h"

#include "SimuClient.h"

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
    if (p_pVerhalten) {
        double tempolimit = p_pVerhalten->getWeg().getTempolimit();
        return std::min(p_dMaxGeschwindigkeit, tempolimit);
    }
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

double PKW::getTankinhalt() const {
    return p_dTankinhalt;
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

void PKW::vZeichnen(const Weg& weg) const {
    bZeichnePKW(p_sName, weg.getName(), p_dAbschnittStrecke / weg.getLaenge(), p_dGeschwindigkeit, p_dTankinhalt);
}
