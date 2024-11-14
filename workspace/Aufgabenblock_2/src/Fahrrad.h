#ifndef FAHRRAD_H // Siehe Kommentar Zeile 1 in Fahrzeug.h
#define FAHRRAD_H

#include <string>

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:

    // Konstruktor mit Name und MaxGeschwindigkeit
    Fahrrad(const std::string& sName, double dMaxGeschwindigkeit);

    // Konstruktor mit Name
    Fahrrad(const std::string& sName);

    // Default-Konstruktor
    Fahrrad();

    // Destruktor
    ~Fahrrad();

    virtual double dGeschwindigkeit() override;

    virtual std::string sType() const override;

    // Überschreiben der Ausgabefunktion
    virtual void vAusgeben(std::ostream& stream) override;
};

#endif // FAHRRAD_H
