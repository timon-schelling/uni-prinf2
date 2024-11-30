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
    Kreuzung(const std::string& sName, double dTankstelle = 0.0);
    virtual ~Kreuzung();

    void vTanken(Fahrzeug& fahrzeug);
    void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dZeit);
    virtual void vSimulieren() override;

    static void vVerbinde(
        const std::string& sNameHin,
        const std::string& sNameRueck,
        double dLaenge,
        std::shared_ptr<Kreuzung> kStart,
        std::shared_ptr<Kreuzung> kZiel,
        Tempolimit eLimit = Tempolimit::Autobahn
    );

    std::shared_ptr<Weg> pZufaelligerWeg(const Weg& herkunftsWeg);
    double dGetTankstelle() const;
    const std::list<std::shared_ptr<Weg>>& getWege() const;

    void vZeichnen() const;
};

#endif // KREUZUNG_H
