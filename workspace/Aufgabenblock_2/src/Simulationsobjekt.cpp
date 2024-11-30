#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "global.h"

#include "Simulationsobjekt.h"

// Initialisierung der statischen Variable
int Simulationsobjekt::p_iMaxID = 0;

Simulationsobjekt::Simulationsobjekt(const std::string& sName) : p_iID(++p_iMaxID), p_sName(sName) {
#ifdef _DEBUG
    std::cout << "Simulationsobjekt \"" << p_sName << "\" mit ID " << p_iID << " erstellt.\n";
#endif
}

Simulationsobjekt::Simulationsobjekt() : p_iID(++p_iMaxID), p_sName("") {
#ifdef _DEBUG
    std::cout << "Simulationsobjekt ohne Name mit ID " << p_iID << " erstellt.\n";
#endif
}

// Getter für ID und Name
int Simulationsobjekt::getID() const {
    return p_iID;
}

std::string Simulationsobjekt::getName() const {
    return p_sName;
}

void Simulationsobjekt::vSimulieren() {
    // Nichts zu tun
}

// Vergleichsoperator ==
bool Simulationsobjekt::operator==(const Simulationsobjekt& obj) const {
    return this->p_iID == obj.p_iID;
}

std::string Simulationsobjekt::sType() const {
    return "Simulationsobjekt";
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
void Simulationsobjekt::vAusgeben(std::ostream& stream) const {
    vZeileSimulationsobjekt(stream, p_iID, p_sName, sType());
}

std::ostream& operator<<(std::ostream& stream, Simulationsobjekt& obj) {
    obj.vAusgeben(stream);
    return stream;
}
