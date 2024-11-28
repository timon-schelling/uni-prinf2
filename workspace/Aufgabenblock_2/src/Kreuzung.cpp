#include "Kreuzung.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <random>
#include "Tempolimit.h"

Kreuzung::Kreuzung(const std::string& sName, double dTankstelle)
    : Simulationsobjekt(sName), p_dTankstelle(dTankstelle) {

}

Kreuzung::~Kreuzung() {

}

void Kreuzung::vTanken(Fahrzeug& fahrzeug) {
    double dMenge = fahrzeug.dTanken();
    if (p_dTankstelle >= dMenge) {
        p_dTankstelle -= dMenge;
    } else {
        fahrzeug.dTanken(p_dTankstelle);
        p_dTankstelle = 0.0;
    }
}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dZeit) {
    vTanken(*pFahrzeug);
    if (!p_pWege.empty()) {
        p_pWege.front()->vAnnahme(std::move(pFahrzeug), dZeit);
    }
}

void Kreuzung::vSimulieren() {
    for (auto& weg : p_pWege) {
        weg->vSimulieren();
    }
}

void Kreuzung::vVerbinde(
    const std::string& sNameHin,
    const std::string& sNameRueck,
    double dLaenge,
    std::shared_ptr<Kreuzung> pStartKreuzung,
    std::shared_ptr<Kreuzung> pZielKreuzung,
    Tempolimit eLimit
) {
    auto hinWeg = std::make_shared<Weg>(sNameHin, dLaenge, eLimit, pZielKreuzung);
    auto rueckWeg = std::make_shared<Weg>(sNameRueck, dLaenge, eLimit, pStartKreuzung);
    hinWeg->setRueckWeg(rueckWeg);
    rueckWeg->setRueckWeg(hinWeg);
    pStartKreuzung->p_pWege.push_back(hinWeg);
    pZielKreuzung->p_pWege.push_back(rueckWeg);
}

std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(const Weg& herkunftsWeg) {
    std::vector<std::shared_ptr<Weg>> moeglicheWege;
    for (const auto& weg : p_pWege) {
        if (!(*weg.get() == *herkunftsWeg.getRueckWeg())) {
            moeglicheWege.push_back(weg);
        }
    }
    if (moeglicheWege.empty()) {
        return herkunftsWeg.getRueckWeg();
    } else {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, moeglicheWege.size() - 1);
        return moeglicheWege[dis(gen)];
    }
}

double Kreuzung::dGetTankstelle() const {
    return p_dTankstelle;
}

const std::list<std::shared_ptr<Weg>>& Kreuzung::getWege() const {
    return p_pWege;
}

void Kreuzung::vZeichnen() const {
    for (const auto& weg : p_pWege) {
        weg->getFahrzeuge();
        for (const auto& fahrzeug : weg->getFahrzeuge()) {
            fahrzeug->vZeichnen(*weg);
        }
    }
}
