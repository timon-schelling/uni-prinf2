#define DEBUG 1

#include <iostream>  // Für Output nach cout
#include <memory>    // Für Smartpointer
#include <vector>    // Für den Vektor
#include <string>    // Für String

#include "Fahrzeug.h"

extern double dGlobaleZeit;

// Funktion vAufgabe1
void vAufgabe_1() {
    std::cout << "\n\nAufgabe 1:\n";

    std::cout << "Erzeuge statische Fahrzeuge:\n";

    // Statische Fahrzeuge
    Fahrzeug f1("Auto 1");
    Fahrzeug f2("Motorrad 1");
    Fahrzeug f3("Auto 2");
    Fahrzeug f4("Motorrad 2");


    std::cout << "\nErzeuge dynamische Fahrzeuge:\n";

    // Dynamische Fahrzeuge mit new
    Fahrzeug* f5 = new Fahrzeug("LKW 1");
    Fahrzeug* f6 = new Fahrzeug("Bus 1");
    Fahrzeug* f7 = new Fahrzeug("LKW 2");
    Fahrzeug* f8 = new Fahrzeug("Bus 2");

    std::cout << "\nLösche dynamische Fahrzeuge:\n";

    // Löschen der dynamisch erzeugten Fahrzeuge, f5-8 werden hier gelöscht (natürlich hier free gemeint)
    delete f5;
    delete f6;
    delete f7;
    delete f8;

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

    // Fahrzeuge in den Vektor speichern ohne move nicht möglich,
    // weil "ownership" vom unique pointer übertragen werden muss
    // fahrzeugVector.push_back(uniqueFahrzeug1);
    // fahrzeugVector.push_back(uniqueFahrzeug2);

    // Fahrzeuge in den Vektor speichern
    fahrzeugVector.push_back(std::move(uniqueFahrzeug1));
    fahrzeugVector.push_back(std::move(uniqueFahrzeug2));

    // Ausgabe der Vektor-Inhalte
    std::cout << "Im Vektor gespeicherte Fahrzeuge:\n";
    for (const auto& f : fahrzeugVector) {
        std::cout << "Fahrzeug im Vektor: Name = " << f->getName() << ", ID = " << f->getID() << "\n";
    }

    std::cout << "\nSpeichern der shared_ptr einen Vektor:\n";

    // Vektor von shared_ptr
    std::vector<std::shared_ptr<Fahrzeug>> sharedFahrzeugVector;

    // Einfügen von shared_ptr-Fahrzeugen in den Vektor
    std::cout << "use_count vor Zuweisung ohne move: " << sharedFahrzeug1.use_count() << "\n";
    sharedFahrzeugVector.push_back(sharedFahrzeug1);  // Normales Einfügen
    std::cout << "use_count vor Zuweisung ohne move: " << sharedFahrzeug1.use_count() << "\n";

    std::cout << "use_count vor Zuweisung mit move: " << sharedFahrzeug1.use_count() << "\n";
    sharedFahrzeugVector.push_back(std::move(sharedFahrzeug2));
    std::cout << "use_count vor Zuweisung mit move: " << sharedFahrzeug1.use_count() << "\n";

    // Ausgabe der Referenzanzahl für sharedFahrzeug1
    std::cout << "use_count von sharedFahrzeug1 nach dem Einfügen: " << sharedFahrzeug1.use_count() << "\n";

    // Smartpointer werden automatisch "gelöscht", wenn sie aus dem Gültigkeitsbereich fallen
    // uniqueFahrzeug1, uniqueFahrzeug2, sharedFahrzeug1, sharedFahrzeug2 werden hier gelöscht (natürlich hier free gemeint)
    // f1-4 werden hier gelöscht (natürlich hier free gemeint)
    // wie im debugger zu sehen ist, werden daten im speicher zwar am ende des scopes als frei im allocator makiert,
    // aber nicht wirklich gelöscht oder überschrieben
    // besonders zu bedenken in verbindung mit use after free bugs
}

void vAufgabe_1_test_table() {

    std::cout << "\nAufgabe 2:\n";


    // Fahrzeug Vector
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeugVector;

    // Fahrzeuge erzeugen und in den Vektor speichern
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Auto 1", 100.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Auto 2", 120.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Auto 3", 115.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Auto 4", 110.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Auto 5", 180.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Fahrrad 1", 30.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Fahrrad 2", 25.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Fahrrad 3", 20.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Fahrrad 4", 15.0));
    fahrzeugVector.push_back(std::make_unique<Fahrzeug>("Fahrrad 5", 18.0));

    // Ausgabe der Fahrzeuge
    std::cout << "\nFahrzeuge im Vektor:\n";
    std::cout << Fahrzeug::vKopf();
    for (const auto& f : fahrzeugVector) {
        std::cout << f->vAusgabe() << "\n";
    }
    std::cout << "\n";
}


void vAufgabe_1a() {
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

    // Daten für 3 Fahrzeuge von der Konsole einlesen
    for (int i = 0; i < 3; ++i) {
        std::string name;
        double maxGeschwindigkeit;

        std::cout << "Geben Sie den Namen des Fahrzeugs " << i + 1 << " ein: ";
        std::cin >> name;
        std::cout << "Geben Sie die Maximalgeschwindigkeit des Fahrzeugs " << i + 1 << " ein: ";
        std::cin >> maxGeschwindigkeit;

        // Fahrzeug mit make_unique erzeugen und in den Vektor einfügen
        fahrzeuge.push_back(std::make_unique<Fahrzeug>(name, maxGeschwindigkeit));
    }



    // Simulation über eine Zeitspanne
    double zeittakt = 0.1;  // Zeittakt von 0.5 Stunden
    double endzeit = 100.0;   // Simuliere über 5 Stunden

    while (dGlobaleZeit + zeittakt < endzeit) {
        dGlobaleZeit += zeittakt;  // Globale Zeit erhöhen

        // Simuliere jedes Fahrzeugs aus
        for (auto& fahrzeug : fahrzeuge) {
        	fahrzeug->vSimulieren();
        }

        // Aktuellen State ausgebens
        std::cout << "Zeitpunkt " << dGlobaleZeit << ": " << std::endl;
        std::cout << Fahrzeug::vKopf();
        for (auto& fahrzeug : fahrzeuge) {
        	std::cout << fahrzeug->vAusgabe() << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
//    vAufgabe_1();
//    vAufgabe_1_test_table();
	vAufgabe_1a();
    return 0;
}
