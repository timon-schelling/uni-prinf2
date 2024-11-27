#include <iostream>  // Für Output nach cout
#include <iomanip>   // Für setw etc.
#include <memory>    // Für Smartpointer
#include <vector>    // Für den Vektor
#include <string>    // Für String
#include <algorithm>  // Für sorting

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"

#include "global.h"

using namespace std;

void vAufgabe_4() {
    // Erzeugen eines Weges
    Weg weg1("Autobahn A1", 100.0, Tempolimit::Autobahn);

    // Ausgabe des Weges
    Weg::vKopf();
    std::cout << weg1 << std::endl;
}

void vAufgabe_5() {
    // Erzeugen eines Weges
    Weg weg1("Autobahn A1", 1000.0, Tempolimit::Autobahn);

    // Erzeugen von Fahrzeugen
    auto pkw1 = std::make_unique<PKW>("BMW", 150.0, 8.5, 60.0);
    auto fahrrad1 = std::make_unique<Fahrrad>("Mountainbike", 30.0);
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 55.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 58.0); // Parkendes Fahrzeug

    // Fahrzeuge auf den Weg setzen
    weg1.vAnnahme(std::move(pkw1));
    weg1.vAnnahme(std::move(fahrrad1));
    weg1.vAnnahme(std::move(pkw2));
    weg1.vAnnahme(std::move(pkw3), 5.0); // Startzeitpunkt bei 5.0

    Weg::vKopf();
    std::cout << weg1 << std::endl;
    // Simulation des Weges
    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 10.0; dGlobaleZeit += 1.0) {
        weg1.vSimulieren();
        std::cout << std::endl;
        PKW::vKopf();
        for (auto& fahrzeug : weg1.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
        }
    }
}

void vAufgabe_6() {
    // Erzeugen von Wegen
    Weg weg1("Autobahn_A1", 1000.0, Tempolimit::Autobahn);
    Weg weg2("Landstrasse_L1", 500.0, Tempolimit::Landstrasse);

    // Erzeugen von Fahrzeugen
    auto pkw1 = std::make_unique<PKW>("BMW", 500.0, 1, 100.0);
    auto fahrrad1 = std::make_unique<Fahrrad>("Mountainbike", 30.0);
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 55.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 58.0); // Parkendes Fahrzeug

    // Fahrzeuge auf die Wege setzen
    weg1.vAnnahme(std::move(pkw1));
    weg1.vAnnahme(std::move(fahrrad1));
    weg2.vAnnahme(std::move(pkw2));
    weg2.vAnnahme(std::move(pkw3), 5.0); // Startzeitpunkt bei 5.0

    Weg::vKopf();
    std::cout << weg1 << std::endl;
    std::cout << weg2 << std::endl;

    // Simulation der Wege
    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 10.0; dGlobaleZeit += 1.0) {
        std::cout << std::endl;
        std::cout << "Zeit: " << dGlobaleZeit << std::endl;
        weg1.vSimulieren();
        weg2.vSimulieren();
        PKW::vKopf();
        for (auto& fahrzeug : weg1.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
        }
        for (auto& fahrzeug : weg2.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
        }
    }
}

void vAufgabe_6_debugLosfahren(double timeStep) {
    // Erzeugen von Wegen
    Weg weg1("Autobahn_A1", 10000.0, Tempolimit::Autobahn);
    Weg weg2("Landstrasse_L1", 5000.0, Tempolimit::Landstrasse);

    // Erzeugen von Fahrzeugen
    auto pkw1 = std::make_unique<PKW>("BMW", 500.0, 1, 100.0);
    auto fahrrad1 = std::make_unique<Fahrrad>("Mountainbike", 30.0);
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 55.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 58.0); // Parkendes Fahrzeug

    // Fahrzeuge auf die Wege setzen
    weg1.vAnnahme(std::move(pkw1));
    weg1.vAnnahme(std::move(fahrrad1));
    weg2.vAnnahme(std::move(pkw2));
    weg2.vAnnahme(std::move(pkw3), 3.0); // Startzeitpunkt bei 3.0

    Weg::vKopf();
    std::cout << weg1 << std::endl;
    std::cout << weg2 << std::endl;

    // Simulation der Wege
    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 10.0; dGlobaleZeit += timeStep) {
        std::cout << std::endl;
        std::cout << "Zeit: " << dGlobaleZeit << std::endl;
        weg1.vSimulieren();
        weg2.vSimulieren();
        PKW::vKopf();
        for (auto& fahrzeug : weg1.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
        }
        for (auto& fahrzeug : weg2.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
        }
    }
}

void vAufgabe_6_debugLosfahren() {
	std::cout << std::endl << "Simulation mit Zeittakt 0.25" << std::endl;
	vAufgabe_6_debugLosfahren(0.25);
	dGlobaleZeit = 0.0; // Reset global time
	std::cout << std::endl << "Simulation mit Zeittakt 0.3" << std::endl;
	vAufgabe_6_debugLosfahren(0.3);
}

void vAufgabe_6_UI() {
    // Initialisiere Grafik
    bInitialisiereGrafik(800, 600);

     // Erzeugen von Wegen
     Weg weg1("Hinweg", 1500.0, Tempolimit::Autobahn);
     Weg weg2("Rueckweg", 1500.0, Tempolimit::Landstrasse);

     // Erzeugen von Fahrzeugen
     auto pkw1 = std::make_unique<PKW>("BMW", 200.0, 1, 100.0);
     auto fahrrad1 = std::make_unique<Fahrrad>("Mountainbike", 30.0);
     auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 55.0);
     auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 58.0); // Parkendes Fahrzeug

     // Fahrzeuge auf die Wege setzen
     weg1.vAnnahme(std::move(pkw1));
     weg1.vAnnahme(std::move(fahrrad1));
     weg2.vAnnahme(std::move(pkw2));
     weg2.vAnnahme(std::move(pkw3), 5.0); // Startzeitpunkt bei 5.0

     // Zeichne die Straße
     int koordinaten[] = { 100, 200, 700, 400 };
     bZeichneStrasse("Hinweg", "Rueckweg", 500, 2, koordinaten);

     Weg::vKopf();
     std::cout << weg1 << std::endl;
     std::cout << weg2 << std::endl;

     // Simulation der Wege
     for (dGlobaleZeit = 0.0; dGlobaleZeit <= 12.0; dGlobaleZeit += 0.1) {
         std::cout << std::endl;
         std::cout << "Zeit: " << dGlobaleZeit << std::endl;
         weg1.vSimulieren();
         weg2.vSimulieren();
         PKW::vKopf();
         for (auto& fahrzeug : weg1.getFahrzeuge()) {
             std::cout << *fahrzeug << std::endl;
             if (auto pkw = dynamic_cast<PKW*>(fahrzeug.get())) {
                 bZeichnePKW(pkw->getName(), "Hinweg", pkw->getAbschnittStrecke() / weg1.getLaenge(), pkw->dGeschwindigkeit(), pkw->getTankinhalt());
             } else if (auto fahrrad = dynamic_cast<Fahrrad*>(fahrzeug.get())) {
                 bZeichneFahrrad(fahrrad->getName(), "Hinweg", fahrrad->getAbschnittStrecke() / weg1.getLaenge(), fahrrad->dGeschwindigkeit());
             }
         }
         for (auto& fahrzeug : weg2.getFahrzeuge()) {
             std::cout << *fahrzeug << std::endl;
             if (auto pkw = dynamic_cast<PKW*>(fahrzeug.get())) {
                 bZeichnePKW(pkw->getName(), "Rueckweg", pkw->getAbschnittStrecke() / weg2.getLaenge(), pkw->dGeschwindigkeit(), pkw->getTankinhalt());
             } else if (auto fahrrad = dynamic_cast<Fahrrad*>(fahrzeug.get())) {
                 bZeichneFahrrad(fahrrad->getName(), "Rueckweg", fahrrad->getAbschnittStrecke() / weg2.getLaenge(), fahrrad->dGeschwindigkeit());
             }
         }
         vSetzeZeit(dGlobaleZeit);
         vSleep(200); // 1 Sekunde warten
     }

    // Beende Grafik
    vBeendeGrafik();
}

int main() {
    // vAufgabe_4();
    // vAufgabe_5();
    // vAufgabe_6();
    // vAufgabe_6_debugLosfahren();
    vAufgabe_6_UI();
    return 0;
}
