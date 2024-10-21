#include <optional>  // Für Optionale Werte
#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.

#include "Fahrzeug.h"

extern double dGlobaleZeit;

// Initialisierung der statischen Klassenvariable
int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug(const std::string& name, double maxGeschwindigkeit)
	: p_sName(name), p_iID(++p_iMaxID),
		p_dMaxGeschwindigkeit(maxGeschwindigkeit > 0 ? maxGeschwindigkeit : 0.0) {
#ifdef _DEBUG
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID
				<< " und Maximalgeschwindigkeit " << p_dMaxGeschwindigkeit << " wurde erstellt.\n";
#endif
}

Fahrzeug::Fahrzeug(const std::string& name)
	: p_sName(name), p_iID(++p_iMaxID) {
#if _DEBUG
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde erstellt.\n";
#endif
}

// Default-Konstruktor
Fahrzeug::Fahrzeug()
	: p_sName(""), p_iID(++p_iMaxID) {
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

const int IDLength = 10;
const int TypeLength = 10;
const int NameLength = 20;
const int GeschwindigkeitLength = 17;
const int MaxGeschwindigkeitLength = 20;
const int GesamtstreckeLength = 15;
const int TankinhaltLength = 10;
// const int

const int TableLength =
	IDLength +
	TypeLength +
	NameLength +
	GeschwindigkeitLength +
	MaxGeschwindigkeitLength +
	GesamtstreckeLength +
	TankinhaltLength +
	0;

std::string Fahrzeug::sKopf() {
	std::ostringstream stringStream;
	stringStream << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::left) << std::setfill(' ')
			<< std::setw(IDLength) << "ID"
			<< std::setw(TypeLength) << "Type"
	    	<< std::setw(NameLength) << "Name"
			<< std::setw(GeschwindigkeitLength) << "Geschwindigkeit"
	    	<< std::setw(MaxGeschwindigkeitLength) << "MaxGeschwindigkeit"
	        << std::setw(GesamtstreckeLength) << "Gesamtstrecke"
			<< std::setw(TankinhaltLength) << "Tankinhalt"
	        << "\n" << std::setfill('-') << std::setw(TableLength) << "" << "\n";
	return stringStream.str();
}

std::string Fahrzeug::sZeile(
	std::optional<int> id = std::nullopt,
	std::optional<std::string> type = std::nullopt,
	std::optional<std::string> name = std::nullopt,
	std::optional<double> geschwindigkeit = std::nullopt,
	std::optional<double> maxGeschwindigkeit = std::nullopt,
	std::optional<double> gesamtstrecke = std::nullopt,
	std::optional<double> tankinhalt = std::nullopt
) {
	std::ostringstream stream;
	stream << std::resetiosflags(std::ios::left);
	stream << std::setiosflags(std::ios::left);
	stream << std::setfill(' ');

	if (id.has_value()) {
		stream << std::setw(IDLength) << id.value();
	} else {
		stream << std::setw(IDLength) << "";
	}

	if (type.has_value()) {
		stream << std::setw(TypeLength) << type.value();
	} else {
		stream << std::setw(TypeLength) << "";
	}

	if (name.has_value()) {
		stream << std::setw(NameLength) << name.value();
	} else {
		stream << std::setw(NameLength) << "";
	}

	if (geschwindigkeit.has_value()) {
		stream << std::setw(MaxGeschwindigkeitLength) << geschwindigkeit.value();
	} else {
		stream << std::setw(MaxGeschwindigkeitLength) << "";
	}

	if (maxGeschwindigkeit.has_value()) {
		stream << std::setw(MaxGeschwindigkeitLength) << maxGeschwindigkeit.value();
	} else {
		stream << std::setw(MaxGeschwindigkeitLength) << "";
	}

	if (gesamtstrecke.has_value()) {
		stream << std::setw(GesamtstreckeLength) << gesamtstrecke.value();
	} else {
		stream << std::setw(GesamtstreckeLength) << "";
	}

	if (tankinhalt.has_value()) {
		stream << std::setw(TankinhaltLength) << tankinhalt.value();
	} else {
		stream << std::setw(TankinhaltLength) << "";
	}

	return stream.str();
}

std::string Fahrzeug::sAusgeben() {
	return sZeile(p_iID, sType(), p_sName, p_dGeschwindigkeit, p_dMaxGeschwindigkeit, p_dGesamtStrecke);
}
