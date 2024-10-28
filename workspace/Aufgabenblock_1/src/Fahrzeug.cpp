#include <optional>  // Für Optionale Werte
#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include <memory>    // Für smart pointer

#include "Fahrzeug.h"

extern double dGlobaleZeit;

// Initialisierung der statischen Klassenvariable
int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug(const std::string& sName, double iMaxGeschwindigkeit)
	: p_sName(sName), p_iID(++p_iMaxID),
		p_dMaxGeschwindigkeit(iMaxGeschwindigkeit > 0 ? iMaxGeschwindigkeit : 0.0) {
#ifdef _DEBUG
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID
				<< " und Maximalgeschwindigkeit " << p_dMaxGeschwindigkeit << " wurde erstellt.\n";
#endif
}

Fahrzeug::Fahrzeug(const std::string& sName)
	: p_sName(sName), p_iID(++p_iMaxID) {
#if _DEBUG
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde erstellt.\n";
#endif
}

// Default-Konstruktor
Fahrzeug::Fahrzeug()
    : p_iID(++p_iMaxID),
      p_dMaxGeschwindigkeit(0.0),
      p_dGeschwindigkeit(0.0),
      p_dGesamtStrecke(0.0),
      p_dGesamtZeit(0.0),
      p_dZeit(0.0)
{
#if _DEBUG
	std::cout << "Fahrzeug ohne Name mit ID " << p_iID << " wurde erstellt.\n";
#endif
}

// Destruktor
Fahrzeug::~Fahrzeug() {
#if _DEBUG
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde gelöscht.\n";
#endif
}

void Fahrzeug::vSimulieren() {
	// Überprüfen, ob es Zeit für einen neuen Simulationsschritt ist
	if (p_dZeit >= dGlobaleZeit) {
        return;
    }

	// Berechnen der verstrichenen Zeit seit dem letzten Simulationsschritt
	double dDeltaZeit = dGlobaleZeit - p_dZeit;

	// Berechne die aktuelle Geschwindigkeit
	p_dGeschwindigkeit = dGeschwindigkeit();

	// Erhöhe die Gesamtstrecke basierend auf der Geschwindigkeit und der verstrichenen Zeit
	p_dGesamtStrecke += p_dGeschwindigkeit * dDeltaZeit;

	// Aktualisiere die gesamte Fahrzeit
	p_dGesamtZeit += dDeltaZeit;

	// Setze die letzte Abfertigungszeit auf die aktuelle globale Zeit
	p_dZeit = dGlobaleZeit;

}

double Fahrzeug::dGeschwindigkeit() {
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge) {
	return 0.0;  // Standardmäßig für Fahrzeuge ohne Tank (z.B. Fahrrad)
}

std::string Fahrzeug::sType() const {
	return "Fahrzeug";
}

// Getter-Funktion für den Namen (const, da sie nichts verändert)
std::string Fahrzeug::getName() const {
	return p_sName;
}

// Getter-Funktion für die ID (const, da sie nichts verändert)
int Fahrzeug::getID() const {
	return p_iID;
}

// Ganz schlechter Code style, weil Änderungen an anderen Klassen auch hier gemacht werden müssen
// einheitliche Formatierung könnte durch eine andere Methode erreicht werden
// Beispeilweise könnten alle Klassen eine Methode haben die alle daten als Key-Value Pair zurückgibt (serialisierung)
// und dann in einer anderen Methode die
// die Listen von an Key-Value Pairs von mehreren Objekten in eine Tabelle (mit passendem Kopf) umgewandelt wird
// daten die so nur bei manchen objekten vorkommen könnten dann für die anderen objekte einfach leer gelassen werden.
// übersteigt aber den Rahmen dieser Aufgabe

const int iIdLength = 10;
const int iTypeLength = 10;
const int iNameLength = 15;
const int iGeschwindigkeitLength = 17;
const int iMaxGeschwindigkeitLength = 20;
const int iGesamtstreckeLength = 15;
const int iTankinhaltLength = 12;
const int iVerbrauchLength = 10;
const int iGesamtverbrauch = 17;
// const int

const int TableLength =
	iIdLength +
	iTypeLength +
	iNameLength +
	iGeschwindigkeitLength +
	iMaxGeschwindigkeitLength +
	iGesamtstreckeLength +
	iTankinhaltLength +
	iVerbrauchLength +
	iGesamtverbrauch +
	0;

void Fahrzeug::vKopf(std::ostream& stream) {
	stream << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::left) << std::setfill(' ')
		<< std::setw(iIdLength) << "ID"
		<< std::setw(iTypeLength) << "Type"
		<< std::setw(iNameLength) << "Name"
		<< std::setw(iGeschwindigkeitLength) << "Geschwindigkeit"
		<< std::setw(iMaxGeschwindigkeitLength) << "MaxGeschwindigkeit"
		<< std::setw(iGesamtstreckeLength) << "Gesamtstrecke"
		<< std::setw(iTankinhaltLength) << "Tankinhalt"
		<< std::setw(iVerbrauchLength) << "Verbrauch"
		<< std::setw(iGesamtverbrauch) << "Gesamtverbrauch"
		<< std::endl << std::setfill('-') << std::setw(TableLength) << "" << std::endl;
}

std::string Fahrzeug::sKopf() {
	std::ostringstream stringStream;
	vKopf(stringStream);
	return stringStream.str();
}

void Fahrzeug::vZeile(
	std::ostream& stream,
	std::optional<int> iId = std::nullopt,
	std::optional<std::string> sType = std::nullopt,
	std::optional<std::string> sName = std::nullopt,
	std::optional<double> dGeschwindigkeit = std::nullopt,
	std::optional<double> dMaxGeschwindigkeit = std::nullopt,
	std::optional<double> dGesamtstrecke = std::nullopt,
	std::optional<double> dTankinhalt = std::nullopt,
	std::optional<double> dVerbrauch = std::nullopt
) {
	stream << std::resetiosflags(std::ios::left);
	stream << std::setiosflags(std::ios::left);
	stream << std::setfill(' ');

	if (iId.has_value()) {
		stream << std::setw(iIdLength) << iId.value();
	} else {
		stream << std::setw(iIdLength) << "";
	}

	if (sType.has_value()) {
		stream << std::setw(iTypeLength) << sType.value();
	} else {
		stream << std::setw(iTypeLength) << "";
	}

	if (sName.has_value()) {
		stream << std::setw(iNameLength) << sName.value();
	} else {
		stream << std::setw(iNameLength) << "";
	}

	if (dGeschwindigkeit.has_value()) {
		stream << std::setw(iGeschwindigkeitLength) << dGeschwindigkeit.value();
	} else {
		stream << std::setw(iGeschwindigkeitLength) << "";
	}

	if (dMaxGeschwindigkeit.has_value()) {
		stream << std::setw(iMaxGeschwindigkeitLength) << dMaxGeschwindigkeit.value();
	} else {
		stream << std::setw(iMaxGeschwindigkeitLength) << "";
	}

	if (dGesamtstrecke.has_value()) {
		stream << std::setw(iGesamtstreckeLength) << dGesamtstrecke.value();
	} else {
		stream << std::setw(iGesamtstreckeLength) << "";
	}

	if (dTankinhalt.has_value()) {
		stream << std::setw(iTankinhaltLength) << dTankinhalt.value();
	} else {
		stream << std::setw(iTankinhaltLength) << "";
	}

	if(dVerbrauch.has_value()) {
		stream << std::setw(iVerbrauchLength) << dVerbrauch.value();
	} else {
		stream << std::setw(iVerbrauchLength) << "";
	}

	if(dGesamtstrecke.has_value() && dVerbrauch.has_value()) {
		stream << std::setw(iGesamtverbrauch) << (dGesamtstrecke.value() / 100) * dVerbrauch.value();
	} else {
		stream << std::setw(iGesamtverbrauch) << "";
	}
}

std::ostream& operator<<(std::ostream& stream, Fahrzeug& fahrzeug) {
	fahrzeug.vAusgeben(stream);
	return stream;
}

// Modelierung hier nicht wirklich sinnvoll, fahrzeuge haben keine eindeutige größe die
// zum vergleichen logicherweise genutzt werden könnte
// Warum zum beispiel sollte statt der gesamtstrecke z.B. die Geschwindigkeit
// oder der Name zum vergleichen genutzt werden?
// besser wäre es hier eine Funktion zu haben die die Fahrzeuge nach einem bestimmten Kriterium vergleicht
bool Fahrzeug::operator<(const Fahrzeug& fahrzeug) const {
    return p_dGesamtStrecke > fahrzeug.p_dGesamtStrecke;
}

Fahrzeug& Fahrzeug::operator=(Fahrzeug& other) {
	if (this != &other) {
		p_sName = other.p_sName + " (Kopie)";
		p_dMaxGeschwindigkeit = other.p_dMaxGeschwindigkeit;

		// je nachdem was erreicht werden soll könnten hier auch noch andere werte kopiert werden
		// p_dGeschwindigkeit = other.p_dGeschwindigkeit;
		// p_dGesamtStrecke = other.p_dGesamtStrecke;
		// p_dGesamtZeit = other.p_dGesamtZeit;
		// p_dZeit = other.p_dZeit;
	}
	return *this;
}

void Fahrzeug::vAusgeben(std::ostream& stream) {
	return vZeile(stream, p_iID, sType(), p_sName, p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke);
}
