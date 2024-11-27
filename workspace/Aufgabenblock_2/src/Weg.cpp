#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>
#include <limits>

#include "global.h"

#include "Weg.h"
#include "Fahrzeug.h"

#include "Fahrausnahme.h"

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
        try {
            fahrzeug->vSimulieren();
        } catch (const Fahrausnahme& e) {
            // hier reicht ein catch für alle Fahrausnahmen,
            // da Fahrausnahme eine Basisklasse für alle Fahrausnahmen ist
            e.vBearbeiten();
        }
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
            return std::numeric_limits<int>::max();
        default:
            return std::numeric_limits<int>::max();
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

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartZeit) {
    pFahrzeug->vNeueStrecke(*this, dStartZeit);
    p_pFahrzeuge.push_front(std::move(pFahrzeug));
}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug) {
    pFahrzeug->vNeueStrecke(*this);
    p_pFahrzeuge.push_back(std::move(pFahrzeug));
}

void Weg::vAusgeben(std::ostream& stream) {
    vZeileWeg(stream, p_iID, p_sName, sType(), p_dLaenge, getTempolimit());
    stream << " (";
    for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it) {
        if (it != p_pFahrzeuge.begin()) {
            stream << ", ";
        }
        stream << (*it)->getName();
    }
    stream << ")";
}

bool Weg::operator==(const Weg& other) const {
    return this->getID() == other.getID();
}

std::string Weg::sType() {
    return "Weg";
}

const std::list<std::unique_ptr<Fahrzeug>>& Weg::getFahrzeuge() {
    return p_pFahrzeuge;
}
