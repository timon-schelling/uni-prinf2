#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>
#include <limits>
#include <list>
#include <algorithm>

#include "global.h"

#include "Weg.h"
#include "Fahrzeug.h"

#include "Fahrausnahme.h"

Weg::Weg()
    : Simulationsobjekt(""), p_dLaenge(0.0), p_eTempolimit(Tempolimit::Autobahn) {
}

Weg::Weg(const std::string& sName, double dLaenge, Tempolimit eTempolimit, std::shared_ptr<Kreuzung> pZielKreuzung)
    : Simulationsobjekt(sName), p_dLaenge(dLaenge), p_eTempolimit(eTempolimit), p_pZielKreuzung(pZielKreuzung) {
}

Weg::~Weg() {
    // Fahrzeuge werden automatisch durch unique_ptr gelöscht
}

void Weg::vSimulieren() {

    // // Liste der IDs der bereits simulierten Fahrzeuge
    // // Wird benötigt, um zu verhindern, dass ein Fahrzeug mehrfach simuliert wird
    // // was zu einer Endlosschleife führen würde
    // // fix weil bearbeiten der Liste während des Iterierens
    // // ein neu anfangen des Iterierens erfordert
    // // gibt schönere Lösungen die aber beheben von vielen in der
    // // Aufgabe geforderten modelierungsfehlern erfordern
    // // z.B. das Fahrzeug nicht direkt löschen sondern nur als gelöscht markieren
    // // könnte auch mit einer lazy list implementiert werden
    // std::list<int> simulierteFahrzeugeIDs;

    // auto it = p_pFahrzeuge.begin();
    // while (it != p_pFahrzeuge.end()) {
    //     // Prüfen, ob das Fahrzeug bereits simuliert wurde
    //     if (std::find(std::begin(simulierteFahrzeugeIDs), std::end(simulierteFahrzeugeIDs), (*it)->getID()) != std::end(simulierteFahrzeugeIDs)) {
    //         ++it;
    //         continue;
    //     }
    //     simulierteFahrzeugeIDs.push_back((*it)->getID());
    //     try {
    //         (*it)->vSimulieren();
    //         ++it;
    //     } catch (const Fahrausnahme& e) {
    //         // Fahrausnahme bearbeiten
    //         e.vBearbeiten();

    //         // hier kann es sein, dass das Fahrzeug gelöscht wurde, deshalb Iterator zurücksetzen
    //         it = p_pFahrzeuge.begin();
    //     }
    // }

    auto it = p_pFahrzeuge.begin();
    while (it != p_pFahrzeuge.end()) {
        try {
            (*it)->vSimulieren();
        } catch (const Fahrausnahme& e) {
            // Fahrausnahme bearbeiten
            e.vBearbeiten();
        }
        ++it;
    }

    // Nach der Simulation die Liste aktualisieren
    p_pFahrzeuge.vAktualisieren();
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

const vertagt::VListe<std::unique_ptr<Fahrzeug>>& Weg::getFahrzeuge() {
    return p_pFahrzeuge;
}

std::unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& fahrzeug) {
    for (auto it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); ++it) {
        if (*(*it) == fahrzeug) {
            std::unique_ptr<Fahrzeug> pFahrzeug = std::move(*it);
            p_pFahrzeuge.erase(it);
            return pFahrzeug;
        }
    }
    // Sonderfall: Nullpointer zurückgeben, wenn Fahrzeug nicht gefunden
    return nullptr;
}

void Weg::setRueckWeg(const std::shared_ptr<Weg>& pRueckWeg) {
    p_pRueckWeg = pRueckWeg;
}

std::shared_ptr<Kreuzung> Weg::getZielKreuzung() const {
    return p_pZielKreuzung.lock();
}

std::shared_ptr<Weg> Weg::getRueckWeg() const {
    return p_pRueckWeg.lock();
}
