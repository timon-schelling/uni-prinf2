#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
using namespace std;

#include "global.h"

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"
#include "Parken.h"

extern double dGlobaleZeit;

Fahrzeug::Fahrzeug(const std::string& sName, double iMaxGeschwindigkeit) : Simulationsobjekt(sName) {
    p_dMaxGeschwindigkeit = iMaxGeschwindigkeit;
#ifdef _DEBUG
    std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID
              << " und Maximalgeschwindigkeit " << p_dMaxGeschwindigkeit << " wurde erstellt.\n";
#endif
}

Fahrzeug::Fahrzeug(const std::string& sName) : Simulationsobjekt(sName) {
#if _DEBUG
    std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde erstellt.\n";
#endif
}

// Default-Konstruktor
Fahrzeug::Fahrzeug() : Simulationsobjekt() {
#if _DEBUG
    std::cout << "Fahrzeug ohne Name mit ID " << p_iID << " wurde erstellt.\n";
#endif
}

double Fahrzeug::getMaxGeschwindigkeit() const {
    return p_dMaxGeschwindigkeit;
}

double Fahrzeug::getGesamtStrecke() const {
    return p_dGesamtStrecke;
}

double Fahrzeug::getAbschnittStrecke() const {
    return p_dAbschnittStrecke;
}

void Fahrzeug::setVerhalten(std::unique_ptr<Verhalten> verhalten) {
    p_pVerhalten = std::move(verhalten);
}

// Modelierung hier nicht wirklich sinnvoll, fahrzeuge haben keine eindeutige größe die
// zum vergleichen logicherweise genutzt werden könnte
// Warum zum beispiel sollte statt der gesamtstrecke z.B. die Geschwindigkeit
// oder der Name zum vergleichen genutzt werden?
// besser wäre es hier eine Funktion zu haben die die Fahrzeuge nach einem bestimmten Kriterium vergleicht
bool Fahrzeug::operator<(const Fahrzeug& fahrzeug) const {
    return p_dGesamtStrecke > fahrzeug.p_dGesamtStrecke;
}

void Fahrzeug::vSimulieren() {
    // Überprüfen, ob es Zeit für einen neuen Simulationsschritt ist
    if (p_dZeit + 1e-6 >= dGlobaleZeit) {
        return;
    }

    // Berechnen der verstrichenen Zeit seit dem letzten Simulationsschritt
    double dDeltaZeit = dGlobaleZeit - p_dZeit;

    // Aktualisieren der Gesamtfahrzeit
    p_dGesamtZeit += dDeltaZeit;

    // Setze die letzte Abfertigungszeit auf die aktuelle globale Zeit
    p_dZeit = dGlobaleZeit;

    // Berechnung der zurückgelegten Strecke
    double dStreckenDelta = p_pVerhalten->dStrecke(*this, dDeltaZeit);

    // Berechnung der Geschwindigkeit
    p_dGeschwindigkeit = dStreckenDelta / dDeltaZeit;

    // Aktualisieren der Gesamtstrecke
    p_dGesamtStrecke += dStreckenDelta;
    p_dAbschnittStrecke += dStreckenDelta;

}

double Fahrzeug::dGeschwindigkeit() {
    return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge) {
    return 0.0;  // Standardmäßig für Fahrzeuge ohne Tank (z.B. Fahrrad)
}

void Fahrzeug::vNeueStrecke(Weg& weg) {
    p_pVerhalten = std::make_unique<Fahren>(weg);
    p_dAbschnittStrecke = 0.0;
}

void Fahrzeug::vNeueStrecke(Weg& weg, double dStartZeit) {
    p_pVerhalten = std::make_unique<Parken>(weg, dStartZeit);
    p_dAbschnittStrecke = 0.0;
}

std::string Fahrzeug::sType() const {
    return "Fahrzeug";
}

std::string Fahrzeug::sKopf() {
    std::ostringstream stringStream;
    vKopfFahrzeug(stringStream);
    return stringStream.str();
}

void Fahrzeug::vKopf(std::ostream& stream) {
    vKopfFahrzeug(stream);
}

void Fahrzeug::vAusgeben(std::ostream& stream) const {
    vZeileFahrzeug(stream, p_iID, p_sName, sType(), p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke, p_dAbschnittStrecke);
}
