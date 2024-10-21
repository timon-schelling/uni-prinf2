#ifndef PKW_H // Siehe Kommentar Zeile 1 in Fahrzeug.h
#define PKW_H

#include <string>

#include "Fahrzeug.h"

class PKW : public Fahrzeug {
protected:
    double p_dVerbrauch; // Verbrauch pro 100km (in Litern)
    double p_dTankvolumen; // Tankvolumen (in Litern)
    double p_dTankinhalt; // Aktueller Tankinhalt (in Litern)

public:

    // Konstruktor mit Name, MaxGeschwindigkeit, Verbrauch und Tankvolumen
    PKW(
        const std::string& name,
        double maxGeschwindigkeit,
        double verbrauch,
        double tankvolumen = 55.0
    );

    // Destruktor
    ~PKW();

    virtual double dGeschwindigkeit() override;

    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

    virtual std::string sType() const override;

    // Überschreiben der Ausgabefunktion
    virtual void vAusgeben(std::ostream& stream) override;
};

#endif // PKW_H
