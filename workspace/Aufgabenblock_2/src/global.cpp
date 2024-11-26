#include <iostream>
#include <optional>
#include <iomanip>  // Für setw etc.

#include "global.h"

double dGlobaleZeit = 0.0;

void vSetStreamOptions(std::ostream& stream) {
    stream << std::resetiosflags(std::ios::left)
           << std::setiosflags(std::ios::left)
           << std::setfill(' ');
}


void vKopfSimulationsobjekt(std::ostream& stream) {
    vSetStreamOptions(stream);
    stream
        << std::setw(iIdLength) << "ID"
        << std::setw(iNameLength) << "Name"
        << std::setw(iTypeLength) << "Type"
        << std::endl;
}
void vKopfFahrzeug(std::ostream& stream) {
    vSetStreamOptions(stream);
    stream
        << std::setw(iIdLength) << "ID"
        << std::setw(iNameLength) << "Name"
        << std::setw(iTypeLength) << "Type"
        << std::setw(iGeschwindigkeitLength) << "Geschwindigkeit"
        << std::setw(iMaxGeschwindigkeitLength) << "MaxGeschwindigkeit"
        << std::setw(iGesamtstreckeLength) << "Gesamtstrecke"
        << std::setw(iAbschnittStreckeLength) << "AbschnittStrecke"
        << std::endl;
}
void vKopfPKW(std::ostream& stream) {
    vSetStreamOptions(stream);
    stream
        << std::setw(iIdLength) << "ID"
        << std::setw(iNameLength) << "Name"
        << std::setw(iTypeLength) << "Type"
        << std::setw(iGeschwindigkeitLength) << "Geschwindigkeit"
        << std::setw(iMaxGeschwindigkeitLength) << "MaxGeschwindigkeit"
        << std::setw(iGesamtstreckeLength) << "Gesamtstrecke"
        << std::setw(iAbschnittStreckeLength) << "AbschnittStrecke"
        << std::setw(iTankinhaltLength) << "Tankinhalt"
        << std::setw(iVerbrauchLength) << "Verbrauch"
        << std::setw(iGesamtverbrauchLength) << "Gesamtverbrauch"
        << std::endl;
}
void vKopfFahrrad(std::ostream& stream) {
    vSetStreamOptions(stream);
    stream
        << std::setw(iIdLength) << "ID"
        << std::setw(iNameLength) << "Name"
        << std::setw(iTypeLength) << "Type"
        << std::setw(iGeschwindigkeitLength) << "Geschwindigkeit"
        << std::setw(iMaxGeschwindigkeitLength) << "MaxGeschwindigkeit"
        << std::setw(iGesamtstreckeLength) << "Gesamtstrecke"
        << std::endl;
}
void vKopfWeg(std::ostream& stream) {
    vSetStreamOptions(stream);
    stream
        << std::setw(iIdLength) << "ID"
        << std::setw(iNameLength) << "Name"
        << std::setw(iTypeLength) << "Type"
        << std::setw(iLaengeLength) << "Laenge"
        << std::setw(iTempolimitLength) << "Tempolimit"
        << std::endl;
}

template<typename Type>
void vPrintOptional(std::ostream& stream, std::optional<Type> o, int length) {
    if (o.has_value()) {
        stream << std::setw(length) << o.value();
    } else {
        stream << std::setw(length) << "";
    }
}

void vZeileSimulationsobjekt(
    std::ostream& stream,
    std::optional<int> iId,
    std::optional<std::string> sName,
    std::optional<std::string> sType
) {
    vSetStreamOptions(stream);
    vPrintOptional(stream, iId, iIdLength);
    vPrintOptional(stream, sName, iNameLength);
    vPrintOptional(stream, sType, iTypeLength);
}
void vZeileFahrzeug(
    std::ostream& stream,
    std::optional<int> iId,
    std::optional<std::string> sName,
    std::optional<std::string> sType,
    std::optional<double> dGeschwindigkeit,
    std::optional<double> dMaxGeschwindigkeit,
    std::optional<double> dGesamtstrecke,
    std::optional<double> dAbschnittStrecke
) {
    vSetStreamOptions(stream);
    vPrintOptional(stream, iId, iIdLength);
    vPrintOptional(stream, sName, iNameLength);
    vPrintOptional(stream, sType, iTypeLength);
    vPrintOptional(stream, dGeschwindigkeit, iGeschwindigkeitLength);
    vPrintOptional(stream, dMaxGeschwindigkeit, iMaxGeschwindigkeitLength);
    vPrintOptional(stream, dGesamtstrecke, iGesamtstreckeLength);
    vPrintOptional(stream, dAbschnittStrecke, iAbschnittStreckeLength);
}
void vZeilePKW(
    std::ostream& stream,
    std::optional<int> iId,
    std::optional<std::string> sName,
    std::optional<std::string> sType,
    std::optional<double> dGeschwindigkeit,
    std::optional<double> dMaxGeschwindigkeit,
    std::optional<double> dGesamtstrecke,
    std::optional<double> dAbschnittStrecke,
    std::optional<double> dTankinhalt,
    std::optional<double> dVerbrauch,
    std::optional<double> dGesamtverbrauch
) {
    vSetStreamOptions(stream);
    vPrintOptional(stream, iId, iIdLength);
    vPrintOptional(stream, sName, iNameLength);
    vPrintOptional(stream, sType, iTypeLength);
    vPrintOptional(stream, dGeschwindigkeit, iGeschwindigkeitLength);
    vPrintOptional(stream, dMaxGeschwindigkeit, iMaxGeschwindigkeitLength);
    vPrintOptional(stream, dGesamtstrecke, iGesamtstreckeLength);
    vPrintOptional(stream, dAbschnittStrecke, iAbschnittStreckeLength);
    vPrintOptional(stream, dTankinhalt, iTankinhaltLength);
    vPrintOptional(stream, dVerbrauch, iVerbrauchLength);
    vPrintOptional(stream, dGesamtverbrauch, iGesamtverbrauchLength);
}
void vZeileFahrrad(
    std::ostream& stream,
    std::optional<int> iId,
    std::optional<std::string> sName,
    std::optional<std::string> sType,
    std::optional<double> dGeschwindigkeit,
    std::optional<double> dMaxGeschwindigkeit,
    std::optional<double> dGesamtstrecke,
    std::optional<double> dAbschnittStrecke
) {
    vSetStreamOptions(stream);
    vPrintOptional(stream, iId, iIdLength);
    vPrintOptional(stream, sName, iNameLength);
    vPrintOptional(stream, sType, iTypeLength);
    vPrintOptional(stream, dGeschwindigkeit, iGeschwindigkeitLength);
    vPrintOptional(stream, dMaxGeschwindigkeit, iMaxGeschwindigkeitLength);
    vPrintOptional(stream, dGesamtstrecke, iGesamtstreckeLength);
    vPrintOptional(stream, dAbschnittStrecke, iAbschnittStreckeLength);
}
void vZeileWeg(
    std::ostream& stream,
    std::optional<int> iId,
    std::optional<std::string> sName,
    std::optional<std::string> sType,
    std::optional<double> dLaenge,
    std::optional<double> sTempolimit
) {
    vSetStreamOptions(stream);
    vPrintOptional(stream, iId, iIdLength);
    vPrintOptional(stream, sName, iNameLength);
    vPrintOptional(stream, sType, iTypeLength);
    vPrintOptional(stream, dLaenge, iLaengeLength);
    vPrintOptional(stream, sTempolimit, iTempolimitLength);
}
