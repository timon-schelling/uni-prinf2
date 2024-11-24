#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>

#include <cmath>

#include "global.h"

#include "Fahrrad.h"
#include "Fahrzeug.h"

Fahrrad::Fahrrad(const std::string& sName, double dMaxGeschwindigkeit)
    : Fahrzeug(sName, dMaxGeschwindigkeit) {
}

Fahrrad::Fahrrad(const std::string& sName)
    : Fahrzeug(sName) {
}

Fahrrad::Fahrrad()
    : Fahrzeug() {
}

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

std::string Fahrrad::sType() {
    return "Fahrrad";
}

std::string Fahrrad::sKopf() {
    std::ostringstream stringStream;
    vKopfFahrrad(stringStream);
    return stringStream.str();
}

void Fahrrad::vKopf(std::ostream& stream) {
    vKopfFahrrad(stream);
}

void Fahrrad::vAusgeben(std::ostream& stream) {
    vZeileFahrrad(stream, p_iID, p_sName, sType(), p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke);
}
