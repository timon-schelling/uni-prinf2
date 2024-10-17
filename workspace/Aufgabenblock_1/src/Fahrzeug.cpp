// #define DEBUG 1

#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include <iomanip>   // Für setw etc.
#include "Fahrzeug.h"

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

// Getter-Funktion für den Namen (const, da sie nichts verändert)
std::string Fahrzeug::getName() const {
	return p_sName;
}

// Getter-Funktion für die ID (const, da sie nichts verändert)
int Fahrzeug::getID() const {
	return p_iID;
}

const int IDLength = 10;
const int NameLength = 20;
const int MaxGeschwindigkeitLength = 20;
const int GesamtstreckeLength = 13;

const int TableLength = IDLength + NameLength + MaxGeschwindigkeitLength + GesamtstreckeLength;

std::string Fahrzeug::vKopf() {
	std::ostringstream stringStream;
	stringStream << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::left) << std::setfill(' ')
			<< std::setw(IDLength) << "ID"
	    	<< std::setw(NameLength) << "Name"
	    	<< std::setw(MaxGeschwindigkeitLength) << "MaxGeschwindigkeit"
	        << std::setw(GesamtstreckeLength) << "Gesamtstrecke"
	        << "\n" << std::setfill('-') << std::setw(TableLength) << "" << "\n";
	return stringStream.str();
}

std::string Fahrzeug::vAusgabe() {
	std::ostringstream stringStream;
	stringStream << std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::left) << std::setfill(' ')
			<< std::setw(IDLength) << p_iID
	    	<< std::setw(NameLength) << p_sName
	    	<< std::setw(MaxGeschwindigkeitLength) << p_dMaxGeschwindigkeit
	        << std::setw(GesamtstreckeLength) << p_dGesamtStrecke;
	return stringStream.str();
}
