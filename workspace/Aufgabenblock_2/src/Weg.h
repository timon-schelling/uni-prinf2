#ifndef WEG_H
#define WEG_H

#include <iostream>
#include <list>
#include <memory>
#include <string>
using namespace std;

#include "vertagt_liste.h"

#include "Simulationsobjekt.h"
#include "Tempolimit.h"

class Fahrzeug;
class Kreuzung;

class Weg : public Simulationsobjekt {
private:
    double p_dLaenge;                                           // Länge des Weges in km
    Tempolimit p_eTempolimit;                                   // Tempolimit des Weges
    vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;    // Liste der Fahrzeuge auf dem Weg
    const std::shared_ptr<Kreuzung> p_pZielKreuzung;            // Zielkreuzung
    std::shared_ptr<Weg> p_pRueckWeg;                           // Rückweg

public:
    // Konstruktoren
    Weg();
    Weg(const std::string& sName, double dLaenge, Tempolimit eTempolimit = Tempolimit::Autobahn, std::shared_ptr<Kreuzung> pZielKreuzung = nullptr);

    // Getter für die Länge des Weges
    double getLaenge() const;

    // Getter für das Tempolimit
    double getTempolimit() const;

    // Getter für die Fahrzeuge auf dem Weg
    const vertagt::VListe<std::unique_ptr<Fahrzeug>>& getFahrzeuge() const;

    std::shared_ptr<Kreuzung> getZielKreuzung() const;

    std::shared_ptr<Weg> getRueckWeg() const;

    void setRueckWeg(const std::shared_ptr<Weg>& pRueckWeg);

    // Vergleichsoperator ==
    bool operator==(const Weg& other) const;

    // Methode zur Simulation des Weges
    virtual void vSimulieren() override;

    void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug);

    // Überladene Methode zur Annahme von parkenden Fahrzeugen mit Startzeit
    void vAnnahme(std::unique_ptr<Fahrzeug> pFahrzeug, double dStartZeit);

    std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& fahrzeug);

    // Copy-Konstruktor und Zuweisungsoperator verhindern
    Weg(const Weg&) = delete;
    Weg& operator=(const Weg& other) = delete;

    virtual std::string sType() const override;

    static std::string sKopf();
    static void vKopf(std::ostream& stream = std::cout);
    virtual void vAusgeben(std::ostream& stream = std::cout) const override;
};

#endif // WEG_H
