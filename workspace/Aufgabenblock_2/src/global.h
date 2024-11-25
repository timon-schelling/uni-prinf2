#ifndef GLOBAL_H // Siehe Kommentar Zeile 1 in Fahrzeug.h
#define GLOBAL_H

#include <iostream>
#include <optional>

// Hier alle globalen simulations variabeln
extern double dGlobaleZeit;

const int iIdLength = 10;
const int iTypeLength = 10;
const int iNameLength = 15;
const int iGeschwindigkeitLength = 17;
const int iMaxGeschwindigkeitLength = 20;
const int iGesamtstreckeLength = 15;
const int iTankinhaltLength = 12;
const int iVerbrauchLength = 10;
const int iGesamtverbrauch = 17;
const int iLaengeLength = 10;
const int iTempolimitLength = 10;

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
    std::optional<double> dGesamtstrecke = std::nullopt
);
void vZeilePKW(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt,
    std::optional<double> dGeschwindigkeit = std::nullopt,
    std::optional<double> dMaxGeschwindigkeit = std::nullopt,
    std::optional<double> dGesamtstrecke = std::nullopt,
    std::optional<double> dTankinhalt = std::nullopt,
    std::optional<double> dVerbrauch = std::nullopt
);
void vZeileFahrrad(
    std::ostream& stream,
    std::optional<int> iId = std::nullopt,
    std::optional<std::string> sName = std::nullopt,
    std::optional<std::string> sType = std::nullopt,
    std::optional<double> dGeschwindigkeit = std::nullopt,
    std::optional<double> dMaxGeschwindigkeit = std::nullopt,
    std::optional<double> dGesamtstrecke = std::nullopt
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
