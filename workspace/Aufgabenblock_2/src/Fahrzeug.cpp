#include <optional>  // Für Optionale Werte
#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <memory>    // Für smart pointer
#include <sstream>

#include "global.h"

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"

extern double dGlobaleZeit;

Fahrzeug::Fahrzeug(const std::string& sName, double iMaxGeschwindigkeit) : Simulationsobjekt(sName){
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

void Fahrzeug::vInit()
{
	Simulationsobjekt::vInit();
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
}


void Fahrzeug::vSimulieren() {
	// Überprüfen, ob es Zeit für einen neuen Simulationsschritt ist
	if (p_dZeit >= dGlobaleZeit) {
        return;
    }

	// Berechnen der verstrichenen Zeit seit dem letzten Simulationsschritt
	double dDeltaZeit = dGlobaleZeit - p_dZeit;

	// Berechne die aktuelle Geschwindigkeit
	p_dGeschwindigkeit = dGeschwindigkeit();

	// Erhöhe die Gesamtstrecke basierend auf der Geschwindigkeit und der verstrichenen Zeit
	p_dGesamtStrecke += p_dGeschwindigkeit * dDeltaZeit;

	// Aktualisiere die gesamte Fahrzeit
	p_dGesamtZeit += dDeltaZeit;

	// Setze die letzte Abfertigungszeit auf die aktuelle globale Zeit
	p_dZeit = dGlobaleZeit;

}

double Fahrzeug::dGeschwindigkeit() {
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge) {
	return 0.0;  // Standardmäßig für Fahrzeuge ohne Tank (z.B. Fahrrad)
}

std::string Fahrzeug::sType() {
	return "Fahrzeug";
}

// Modelierung hier nicht wirklich sinnvoll, fahrzeuge haben keine eindeutige größe die
// zum vergleichen logicherweise genutzt werden könnte
// Warum zum beispiel sollte statt der gesamtstrecke z.B. die Geschwindigkeit
// oder der Name zum vergleichen genutzt werden?
// besser wäre es hier eine Funktion zu haben die die Fahrzeuge nach einem bestimmten Kriterium vergleicht
bool Fahrzeug::operator<(const Fahrzeug& fahrzeug) const {
    return p_dGesamtStrecke > fahrzeug.p_dGesamtStrecke;
}

std::string Fahrzeug::sKopf() {
	std::ostringstream stringStream;
	vKopfFahrzeug(stringStream);
	return stringStream.str();
}

void Fahrzeug::vKopf(std::ostream& stream) {
	vKopfFahrzeug(stream);
}

void Fahrzeug::vAusgeben(std::ostream& stream) {
	vZeileFahrzeug(stream, p_iID, p_sName, sType(), p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke);
}
