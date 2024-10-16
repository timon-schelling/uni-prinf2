#include <iostream>  // Für Output nach cout
#include <memory>    // Für Smartpointer
#include <vector>    // Für den Vektor
#include <string>    // Für String

#include "Fahrzeug.h"

// Funktion vAufgabe1
void vAufgabe1() {
    std::cout << "Erzeuge statische Fahrzeuge:\n";

    // Statische Fahrzeuge
    Fahrzeug f1("Auto");
    Fahrzeug f2("Motorrad");

    std::cout << "\nErzeuge dynamische Fahrzeuge:\n";

    // Dynamische Fahrzeuge mit new
    Fahrzeug* f3 = new Fahrzeug("LKW");
    Fahrzeug* f4 = new Fahrzeug("Bus");

    std::cout << "\nLösche dynamische Fahrzeuge:\n";

    // Löschen der dynamisch erzeugten Fahrzeuge
    delete f3;
    delete f4;

    std::cout << "\nErzeuge Smartpointer-Fahrzeuge:\n";

    // Smartpointer: unique_ptr und shared_ptr
    auto uniqueFahrzeug1 = std::make_unique<Fahrzeug>("E-Bike");
    auto uniqueFahrzeug2 = std::make_unique<Fahrzeug>("Elektroroller");

    auto sharedFahrzeug1 = std::make_shared<Fahrzeug>("Traktor");
    auto sharedFahrzeug2 = std::make_shared<Fahrzeug>("Zug");

    std::cout << "\nuse_count vor Zuweisung: " << sharedFahrzeug1.use_count() << "\n";

    // Erzeuge einen weiteren shared_ptr auf sharedFahrzeug1
    std::shared_ptr<Fahrzeug> sharedFahrzeug3 = sharedFahrzeug1;

    std::cout << "use_count nach Zuweisung: " << sharedFahrzeug1.use_count() << "\n";

    std::cout << "\nVersuch mit unique_ptr (nicht möglich):\n";

    // unique_ptr kann nicht kopiert werden
    // std::unique_ptr<Fahrzeug> uniqueFahrzeug3 = uniqueFahrzeug1;

    std::cout << "\nSpeichern der unique_ptr in einem Vektor:\n";

    // Vektor von unique_ptr
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeugVector;

    // Fahrzeuge in den Vektor speichern
    fahrzeugVector.push_back(std::move(uniqueFahrzeug1));
    fahrzeugVector.push_back(std::move(uniqueFahrzeug2));

    // Ausgabe der Vektor-Inhalte
    std::cout << "Im Vektor gespeicherte Fahrzeuge:\n";
    for (const auto& f : fahrzeugVector) {
        std::cout << "Fahrzeug im Vektor: Name = " << f->getName() << ", ID = " << f->getID() << "\n";
    }

    // Smartpointer werden automatisch gelöscht, wenn sie aus dem Gültigkeitsbereich fallen
}

int main() {
    vAufgabe1();
    return 0;
}
