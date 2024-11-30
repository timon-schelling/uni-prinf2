#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "SimuClient.h"

#include "global.h"

#include "Fahrzeug.h"
#include "PKW.h"
#include "Verhalten.h"
#include "Weg.h"

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

double PKW::getTankinhalt() const {
    return p_dTankinhalt;
}

void PKW::vSimulieren() {
    if (p_dTankinhalt > 0)
    {
        double dGesamtStreckeVorher = p_dGesamtStrecke;
        Fahrzeug::vSimulieren();
        p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeVorher) * p_dVerbrauch / 100;
        if (p_dTankinhalt < 0) p_dTankinhalt = 0;
    }
}

// Implementierung von dGeschwindigkeit mit Tankberechnung
double PKW::dGeschwindigkeit() {
    if (p_pVerhalten) {
        double tempolimit = p_pVerhalten->getWeg().getTempolimit();
        return std::min(p_dMaxGeschwindigkeit, tempolimit);
    }
    return p_dMaxGeschwindigkeit;
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

void PKW::vZeichnen(const Weg& weg) const {
    // bZeichnePKW(p_sName, weg.getName(), p_dAbschnittStrecke / weg.getLaenge(), p_dGeschwindigkeit, p_dTankinhalt);
    // hier relative Strecke kleiner 1, da die Funktion bZeichneFahrrad sonst in nicht immer korrekt zeichnet (bei aufgabe 7 bei Kreuzung 4)
    bZeichnePKW(p_sName, weg.getName(), min(p_dAbschnittStrecke / weg.getLaenge(), 1.0 - 1e-4), p_dGeschwindigkeit, p_dTankinhalt);
}

std::string PKW::sType() const {
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

void PKW::vAusgeben(std::ostream& stream) const {
    vZeilePKW(stream, p_iID, p_sName, sType(), p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke, p_dAbschnittStrecke, p_dTankinhalt, p_dVerbrauch, p_dGesamtStrecke * p_dVerbrauch / 100);
}
