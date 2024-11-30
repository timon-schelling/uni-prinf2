// Prüfen, ob die Header-Datei bereits eingebunden wurde, Wenn nicht, dann einbinden und
// hier die Definitionen vornehmen, damit sie nicht doppelt eingebunden wird.
// Dies ermöglicht es, die Header-Datei in mehreren Dateien zu verwenden, ohne dass es zu
// Konflikten kommt.
// Funktionsweise:
// `#ifndef` steht für "if not defined" und fügt den folgenden Code nur ein, wenn die Konstante
// noch nicht definiert ist.
// `#define` definiert die Konstante, die in ifndef verwendet wird.
// zusammen bedeuten sie, dass der folgende Code nur einmal vom Präprozessor eingefügt wird.
#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <optional>

// Hier alle globalen simulations variabeln
extern double dGlobaleZeit;

// Hier sind die Längen der einzelnen Spalten definiert
const int iIdLength = 10;
const int iTypeLength = 10;
const int iNameLength = 20;
const int iGeschwindigkeitLength = 17;
const int iMaxGeschwindigkeitLength = 20;
const int iGesamtstreckeLength = 15;
const int iTankinhaltLength = 12;
const int iVerbrauchLength = 10;
const int iGesamtverbrauchLength = 17;
const int iLaengeLength = 10;
const int iTempolimitLength = 10;
const int iAbschnittStreckeLength = 20;

void vKopfSimulationsobjekt(std::ostream& stream = std::cout);
void vKopfFahrzeug(std::ostream& stream = std::cout);
void vKopfPKW(std::ostream& stream = std::cout);
void vKopfFahrrad(std::ostream& stream = std::cout);
void vKopfWeg(std::ostream& stream = std::cout);

void vZeileSimulationsobjekt(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt
);
void vZeileFahrzeug(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt,
    std::optional<double> dGeschwindigkeit = std::nullopt,
    std::optional<double> dMaxGeschwindigkeit = std::nullopt,
    std::optional<double> dGesamtstrecke = std::nullopt,
    std::optional<double> dAbschnittStrecke = std::nullopt
);
void vZeilePKW(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt,
    std::optional<double> dGeschwindigkeit = std::nullopt,
    std::optional<double> dMaxGeschwindigkeit = std::nullopt,
    std::optional<double> dGesamtstrecke = std::nullopt,
    std::optional<double> dAbschnittStrecke = std::nullopt,
    std::optional<double> dTankinhalt = std::nullopt,
    std::optional<double> dVerbrauch = std::nullopt,
    std::optional<double> dGesamtverbrauch = std::nullopt
);
void vZeileFahrrad(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt,
    std::optional<double> dGeschwindigkeit = std::nullopt,
    std::optional<double> dMaxGeschwindigkeit = std::nullopt,
    std::optional<double> dGesamtstrecke = std::nullopt,
    std::optional<double> dAbschnittStrecke = std::nullopt
);
void vZeileWeg(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt,
    std::optional<double> dLaenge = std::nullopt,
    std::optional<double> sTempolimit = std::nullopt
);

#endif // GLOBAL_H
