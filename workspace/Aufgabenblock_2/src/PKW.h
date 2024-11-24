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

    // Default-Konstruktor
    PKW();

     // Überschreiben der Simulationsfunktion
    virtual void vSimulieren() override;

    // Überschreiben der Geschwindigkeitsfunktion
    virtual double dGeschwindigkeit() override;

    // Überschreiben der Tanken-Funktion
    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;

    // Überchreiben der Fahrzeugtypenfunktion
    virtual std::string sType() override;

    static std::string sKopf();
    static void vKopf(std::ostream& stream = std::cout);
    virtual void vAusgeben(std::ostream& stream = std::cout) override;
};

#endif // PKW_H