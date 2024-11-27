#ifndef WEG_H
#define WEG_H

#include <string>
#include <list>
#include <memory>
#include <iostream>

// Einbinden der Basisklasse
#include "Simulationsobjekt.h"

class Fahrzeug;

#include "Tempolimit.h"

class Weg : public Simulationsobjekt {
private:
    double p_dLaenge;                              // Länge des Weges in km
    Tempolimit p_eTempolimit;                      // Tempolimit des Weges
    std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge; // Liste der Fahrzeuge auf dem Weg

public:
    // Konstruktoren
    Weg();
    Weg(const std::string& sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn);

    // Destruktor
    virtual ~Weg();

    // Methode zur Simulation des Weges
    virtual void vSimulieren() override;

    // Getter für die Länge des Weges
    double getLaenge() const;

    // Getter für das Tempolimit
    double getTempolimit() const;

    // Getter für die Fahrzeuge auf dem Weg
    const std::list<std::unique_ptr<Fahrzeug>>& getFahrzeuge();

    static std::string sKopf();
    static void vKopf(std::ostream& stream = std::cout);
    virtual void vAusgeben(std::ostream& stream = std::cout) override;

    // Vergleichsoperator ==
    bool operator==(const Weg& other) const;

    // Copy-Konstruktor und Zuweisungsoperator verhindern
    Weg(const Weg&) = delete;
    Weg& operator=(const Weg& other) = delete;

    virtual std::string sType() override;

    void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);

    // Überladene Methode zur Annahme von parkenden Fahrzeugen mit Startzeit
    void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartZeit);

    std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);
};

#endif // WEG_H
