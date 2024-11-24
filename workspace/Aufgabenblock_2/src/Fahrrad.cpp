#include <string>    // Für String
#include <iomanip>   // Für setw etc.

#include <cmath>

#include "Fahrrad.h"
#include "Fahrzeug.h"

extern double dGlobaleZeit;

Fahrrad::Fahrrad(const std::string& sName, double dMaxGeschwindigkeit)
    : Fahrzeug(sName, dMaxGeschwindigkeit) {
}

Fahrrad::Fahrrad(const std::string& sName)
    : Fahrzeug(sName) {
}

Fahrrad::Fahrrad()
    : Fahrzeug() {
}

Fahrrad::~Fahrrad(){}

double Fahrrad::dGeschwindigkeit() {
    // Berechnung der aktuellen Geschwindigkeit
    int i20kmSteps = (int)(p_dGesamtStrecke / 20);
    double dAktuelleGeschwindigkeit = pow(0.9, i20kmSteps) * p_dMaxGeschwindigkeit;

    // Die Geschwindigkeit darf nicht unter 12 km/h sinken
    if (dAktuelleGeschwindigkeit < 12.0) {
        dAktuelleGeschwindigkeit = 12.0;
    }

    p_dGeschwindigkeit = dAktuelleGeschwindigkeit;

    return dAktuelleGeschwindigkeit;
}

std::string Fahrrad::sType() const {
    return "Fahrrad";
}

void Fahrrad::vAusgeben(std::ostream& stream) {
    return Fahrzeug::vAusgeben(stream);
}
