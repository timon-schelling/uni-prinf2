#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#include "SimuClient.h"

#include "global.h"

#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "Weg.h"

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

void Fahrrad::vZeichnen(const Weg& weg) const {
    bZeichneFahrrad(p_sName, weg.getName(), p_dAbschnittStrecke / weg.getLaenge(), p_dGeschwindigkeit);
}

std::string Fahrrad::sType() const {
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

void Fahrrad::vAusgeben(std::ostream& stream) const {
    vZeileFahrrad(stream, p_iID, p_sName, sType(), p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke, p_dAbschnittStrecke);
}
