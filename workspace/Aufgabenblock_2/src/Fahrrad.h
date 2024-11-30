#ifndef FAHRRAD_H // Siehe Kommentar Zeile 1 in Fahrzeug.h
#define FAHRRAD_H

#include <string>
using namespace std;

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:

    // Konstruktor mit Name und MaxGeschwindigkeit
    Fahrrad(const std::string& sName, double dMaxGeschwindigkeit);

    // Konstruktor mit Name
    Fahrrad(const std::string& sName);

    // Default-Konstruktor
    Fahrrad();

    virtual double dGeschwindigkeit() override;

    virtual void vZeichnen(const Weg& weg) const override;

    virtual std::string sType() const override;

    static std::string sKopf();
    static void vKopf(std::ostream& stream = std::cout);
    virtual void vAusgeben(std::ostream& stream = std::cout) const override;
};

#endif // FAHRRAD_H
