#include "Kreuzung.h"
#include "Fahrzeug.h"
#include "Weg.h"

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

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dZeit) {
    vTanken(*fahrzeug);
    if (!p_pWege.empty()) {
        p_pWege.front()->vAnnahme(std::move(fahrzeug), dZeit);
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
    std::shared_ptr<Kreuzung> kStart,
    std::shared_ptr<Kreuzung> kZiel,
    Begrenzung eLimit
) {
    auto hinWeg = std::make_shared<Weg>(sNameHin, dLaenge, eLimit);
    auto rueckWeg = std::make_shared<Weg>(sNameRueck, dLaenge, eLimit);

    hinWeg->setZielKreuzung(kZiel);
    hinWeg->setRueckWeg(rueckWeg);

    rueckWeg->setZielKreuzung(kStart);
    rueckWeg->setRueckWeg(hinWeg);

    kStart->p_pWege.push_back(hinWeg);
    kZiel->p_pWege.push_back(rueckWeg);
}