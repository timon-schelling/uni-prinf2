#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <string>
using namespace std;

#include "Simulationsobjekt.h"
#include "Verhalten.h"

class Verhalten;
class Weg;

class Fahrzeug : public Simulationsobjekt {

protected:
    std::unique_ptr<Verhalten> p_pVerhalten; // Zeiger auf Verhalten
    double p_dMaxGeschwindigkeit = 0.0; // Maximale Geschwindigkeit des Fahrzeugs (in km/h)
    double p_dGeschwindigkeit = 0.0; // Aktuelle Geschwindigkeit des Fahrzeugs (in km/h)
    double p_dGesamtStrecke = 0.0; // Gesamtstrecke, die das Fahrzeug zurückgelegt hat (in km)
    double p_dGesamtZeit = 0.0; // Gesamtzeit, die das Fahrzeug unterwegs war (in h)
    double p_dZeit = 0.0; // Letzte Abfertigungszeit des Fahrzeugs (in h)
    double p_dAbschnittStrecke = 0.0; // Strecke auf aktuellem Weg

public:

    // Konstruktor mit Name und MaxGeschwindigkeit
    Fahrzeug(const std::string& sName, double dMaxGeschwindigkeit);

    // Konstruktor mit Name
    Fahrzeug(const std::string& sName);

    // Default-Konstruktor
    Fahrzeug();

    // Getter für p_dMaxGeschwindigkeit
    double getMaxGeschwindigkeit() const;

    // Getter für p_dGesamtStrecke
    double getGesamtStrecke() const;

    // Getter für p_dAbschnittStrecke
    double getAbschnittStrecke() const;

    // Setter für p_pVerhalten
    void setVerhalten(std::unique_ptr<Verhalten> verhalten);

    // Vergleichsoperator kleiner als
    bool operator<(const Fahrzeug& f) const;

    // Simulationsfunktion, virtuell, da sie in den abgeleiteten Klassen überschrieben wird
    virtual void vSimulieren() override;

    // Berechnet die aktuelle Geschwindigkeit des Fahrzeugs
    virtual double dGeschwindigkeit();

    // Tanken-Funktion, virtuell, da sie in den abgeleiteten Klassen überschrieben wird
    // schlechte Abbildung der Realität, da fahrräder nicht tanken können
    // würde man eigentlich anders modellieren
    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

    // Neue Methode zum Setzen des Verhaltens
    void vNeueStrecke(Weg& weg);

    // Überladene Methode zum Setzen des Verhaltens für parkende Fahrzeuge mit Startzeit
    void vNeueStrecke(Weg& weg, double dStartZeit);

    // Verhindert das Kopieren Der Copy-Konstruktor wird gelöscht (delete),
    // weil es nicht sinnvoll ist, dass zwei verschiedene Fahrzeugobjekte dieselbe ID oder Ressource teilen.
    // Würden wir den Copy-Konstruktor nicht löschen, könnte es passieren,
    // dass mehrere Fahrzeuge dieselbe ID haben, was zu Verwirrung führt.
    Fahrzeug(const Fahrzeug&) = delete;
    Fahrzeug& operator=(const Fahrzeug& other) = delete;

    virtual void vZeichnen(const Weg& weg) const = 0;

    // Funktion soll für jeden fahrzeugtyp eine identifizierbaren Typen Beschreibung ausgeben
    // Muss in den abgeleiteten Klassen überschrieben werden, kosmetisches Feature für die Ausgabe
    virtual std::string sType() const override;

    static std::string sKopf();
    static void vKopf(std::ostream& stream = std::cout);
    virtual void vAusgeben(std::ostream& stream = std::cout) const override;
};

#endif // FAHRZEUG_H
