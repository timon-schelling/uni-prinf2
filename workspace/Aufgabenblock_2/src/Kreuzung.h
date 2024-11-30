#ifndef KREUZUNG_H
#define KREUZUNG_H

#include <list>
#include <memory>
using namespace std;

#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Tempolimit.h"

class Kreuzung : public Simulationsobjekt {
private:
    double p_dTankstelle;
    std::list<std::shared_ptr<Weg>> p_pWege;

public:
    static void vVerbinde(
        const std::string& sNameHin,
        const std::string& sNameRueck,
        double dLaenge,
        std::shared_ptr<Kreuzung> kStart,
        std::shared_ptr<Kreuzung> kZiel,
        Tempolimit eLimit = Tempolimit::Autobahn
    );

    Kreuzung(const std::string& sName, double dTankstelle = 0.0);

    double getTankstelle() const;
    const std::list<std::shared_ptr<Weg>>& getWege() const;

    virtual void vSimulieren() override;
    void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dZeit);
    void vTanken(Fahrzeug& fahrzeug);
    std::shared_ptr<Weg> pZufaelligerWeg(const Weg& herkunftsWeg) const;

    void vZeichnen() const;
};

#endif // KREUZUNG_H
