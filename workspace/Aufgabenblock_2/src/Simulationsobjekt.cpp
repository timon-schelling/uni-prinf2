#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <sstream>

#include "global.h"

#include "Simulationsobjekt.h"

// Initialisierung der statischen Variable
int Simulationsobjekt::p_iMaxID = 0;

// Konstruktor
Simulationsobjekt::Simulationsobjekt(const std::string& sName) {
    vInit();
    p_sName = sName;
#ifdef _DEBUG
    std::cout << "Simulationsobjekt \"" << p_sName << "\" mit ID " << p_iID << " erstellt.\n";
#endif
}

Simulationsobjekt::Simulationsobjekt() {
    vInit();
#ifdef _DEBUG
    std::cout << "Simulationsobjekt ohne Name mit ID " << p_iID << " erstellt.\n";
#endif
}

// Destruktor
Simulationsobjekt::~Simulationsobjekt() {
#ifdef _DEBUG
    std::cout << "Simulationsobjekt \"" << p_sName << "\" mit ID " << p_iID << " gelöscht.\n";
#endif
}

std::string Simulationsobjekt::sKopf() {
    std::ostringstream stringStream;
    vKopfSimulationsobjekt(stringStream);
    return stringStream.str();
}

void Simulationsobjekt::vKopf(std::ostream& stream) {
    vKopfSimulationsobjekt(stream);
}

// vAusgeben() gibt ID und Name aus
void Simulationsobjekt::vAusgeben(std::ostream& stream) {
    vZeileSimulationsobjekt(stream, p_iID, p_sName, sType());
}

// vInit() initialisiert die ID
void Simulationsobjekt::vInit() {
    p_iID = ++p_iMaxID;
    p_sName = "";
}

void Simulationsobjekt::vSimulieren() {
    // Nichts zu tun
}

// Vergleichsoperator ==
bool Simulationsobjekt::operator==(const Simulationsobjekt& obj) const {
    return this->p_iID == obj.p_iID;
}

// Getter für ID und Name
int Simulationsobjekt::getID() const {
    return p_iID;
}

std::string Simulationsobjekt::getName() const {
    return p_sName;
}

std::string Simulationsobjekt::sType() {
    return "Simulationsobjekt";
}

std::ostream& operator<<(std::ostream& stream, Simulationsobjekt& obj) {
    obj.vAusgeben(stream);
    return stream;
}
