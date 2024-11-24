#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>
#include <limits>

#include "global.h"

#include "Weg.h"
#include "Fahrzeug.h"

Weg::Weg()
    : Simulationsobjekt(""), p_dLaenge(0.0), p_eTempolimit(Tempolimit::Autobahn) {
}

Weg::Weg(const std::string& sName, double dLaenge, Tempolimit eTempolimit)
    : Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(eTempolimit) {
}

Weg::~Weg() {
    // Fahrzeuge werden automatisch durch unique_ptr gelöscht
}

void Weg::vSimulieren() {
    // Alle Fahrzeuge auf dem Weg simulieren
    for (auto& fahrzeug : p_pFahrzeuge) {
        fahrzeug->vSimulieren();
    }
}

double Weg::getLaenge() const {
    return p_dLaenge;
}

double Weg::getTempolimit() const {
    switch (p_eTempolimit) {
        case Tempolimit::Innerorts:
            return 50.0;
        case Tempolimit::Landstrasse:
            return 100.0;
        case Tempolimit::Autobahn:
            return std::numeric_limits<double>::max();
        default:
            return std::numeric_limits<double>::max();
    }
}

std::string Weg::sKopf() {
    std::ostringstream stringStream;
    vKopfWeg(stringStream);
    return stringStream.str();
}

void Weg::vKopf(std::ostream& stream) {
    vKopfWeg(stream);
}

void Weg::vAusgeben(std::ostream& stream) {
    vZeileWeg(stream, p_iID, p_sName, sType(), p_dLaenge, getTempolimit());
}

bool Weg::operator==(const Weg& other) const {
    return this->getID() == other.getID();
}
