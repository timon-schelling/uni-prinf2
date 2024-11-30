#ifndef SIMULATIONSOBJEKT_H
#define SIMULATIONSOBJEKT_H

#include <iostream>
#include <string>
using namespace std;

class Simulationsobjekt {
private:
    static int p_iMaxID; // Statische Variable für die ID-Vergabe

protected:
    int p_iID;           // Eindeutige ID des Objekts
    std::string p_sName; // Name des Objekts
    double p_dZeit;      // Letzte Simulationszeit

public:
    // Konstruktoren
    Simulationsobjekt(const std::string& sName);
    Simulationsobjekt();
    ~Simulationsobjekt() = default;

    // Getter für ID und Name
    int getID() const;
    std::string getName() const;

    // Rein virtuelle Methode vSimulieren()
    virtual void vSimulieren();

    // Verhindern des Copy-Konstruktors
    Simulationsobjekt(const Simulationsobjekt&) = delete;

    // Zuweisungsoperator anpassen
    Simulationsobjekt& operator=(const Simulationsobjekt& other) = delete;

    // Vergleichsoperator ==
    bool operator==(const Simulationsobjekt& obj) const;

    // Funktion soll für jeden objekttyp eine identifizierbaren Typen Beschreibung ausgeben
    // Muss in den abgeleiteten Klassen überschrieben werden, kosmetisches Feature für die Ausgabe
    virtual std::string sType() const;

    static std::string sKopf();
    static void vKopf(std::ostream& stream = std::cout);
    virtual void vAusgeben(std::ostream& stream = std::cout) const;
};

// Operator zum Ausgeben eines Simulationsobjekt in einen Stream
std::ostream& operator<<(std::ostream& stream, Simulationsobjekt& obj);

#endif // SIMULATIONSOBJEKT_H
