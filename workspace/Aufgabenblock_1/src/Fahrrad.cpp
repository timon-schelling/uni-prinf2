#include <string>    // Für String
#include <iomanip>   // Für setw etc.

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
    double dFaktor = 1.0 - (static_cast<int>(p_dGesamtStrecke / 20) * 0.1);  // 10% pro 20 km
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * dFaktor;

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
