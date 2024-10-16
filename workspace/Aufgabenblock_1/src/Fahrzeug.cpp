#include <iostream>  // Für Output nach cout
#include <string>    // Für String
#include "Fahrzeug.h"

// Initialisierung der statischen Klassenvariable
int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug(const std::string& name)
	: p_sName(name), p_iID(++p_iMaxID) {
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde erstellt.\n";
}

// Default-Konstruktor
Fahrzeug::Fahrzeug()
	: p_sName(""), p_iID(++p_iMaxID) {
	std::cout << "Fahrzeug ohne Name mit ID " << p_iID << " wurde erstellt.\n";
}

// Destruktor
Fahrzeug::~Fahrzeug() {
	std::cout << "Fahrzeug \"" << p_sName << "\" mit ID " << p_iID << " wurde gelöscht.\n";
}

// Getter-Funktion für den Namen (const, da sie nichts verändert)
std::string Fahrzeug::getName() const {
	return p_sName;
}

// Getter-Funktion für die ID (const, da sie nichts verändert)
int Fahrzeug::getID() const {
	return p_iID;
}
