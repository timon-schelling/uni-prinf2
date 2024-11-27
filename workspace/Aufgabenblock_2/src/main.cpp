#include <iostream>  // Für Output nach cout
#include <iomanip>   // Für setw etc.
#include <memory>    // Für Smartpointer
#include <vector>    // Für den Vektor
#include <string>    // Für String
#include <algorithm>  // Für sorting
#include <random>    // Für Zufallszahlen

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"

#include "global.h"

#include "vertagt_liste.h"

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
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 40.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 70.0); // Parkendes Fahrzeug

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
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 35.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 88.0); // Parkendes Fahrzeug

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
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 35.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 80.0); // Parkendes Fahrzeug

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
    bInitialisiereGrafik(900, 600);

    // Erzeugen von Wegen
    Weg weg1("Hinweg", 500.0, Tempolimit::Autobahn);
    Weg weg2("Rueckweg", 500.0, Tempolimit::Landstrasse);

    // Erzeugen von Fahrzeugen
    auto pkw1 = std::make_unique<PKW>("BMW", 120.0, 1, 100.0);
    auto fahrrad1 = std::make_unique<Fahrrad>("Mountainbike", 30.0);
    auto pkw2 = std::make_unique<PKW>("Audi", 130.0, 7.0, 35.0);
    auto pkw3 = std::make_unique<PKW>("Mercedes", 140.0, 7.5, 80.0); // Parkendes Fahrzeug

    // Fahrzeuge auf die Wege setzen
    weg1.vAnnahme(std::move(pkw1));
    weg1.vAnnahme(std::move(fahrrad1));
    weg2.vAnnahme(std::move(pkw2));
    weg2.vAnnahme(std::move(pkw3), 2.0); // Startzeitpunkt bei 5.0

    // Zeichne die Straße
    int koordinaten[] = { 100, 400, 800, 400 };
    bZeichneStrasse("Hinweg", "Rueckweg", 700, 2, koordinaten);

    Weg::vKopf();
    std::cout << weg1 << std::endl;
    std::cout << weg2 << std::endl;

    // Simulation der Wege
    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 8.0; dGlobaleZeit += 0.1) {
        std::cout << std::endl;
        std::cout << "Zeit: " << dGlobaleZeit << std::endl;
        weg1.vSimulieren();
        weg2.vSimulieren();
        PKW::vKopf();
        for (auto& fahrzeug : weg1.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
            fahrzeug->vZeichnen(weg1);
        }
        for (auto& fahrzeug : weg2.getFahrzeuge()) {
            std::cout << *fahrzeug << std::endl;
            fahrzeug->vZeichnen(weg2);
        }
        vSetzeZeit(dGlobaleZeit);
        vSleep(100); // 1 Sekunde warten
    }

    // Beende Grafik
    vBeendeGrafik();
}

void vAufgabe_6a()
{
    std::random_device seed;
    static std::mt19937 device(seed());
    std::uniform_int_distribution<int> dist(1, 10);

    vertagt::VListe<int> liste;

    for (int i = 0; i < 10; ++i)
    {
        int zuf = dist(device);
        liste.push_back(zuf);
    }

    liste.vAktualisieren();

    std::cout << "Initiale Liste:" << std::endl;
    for (auto it = liste.begin(); it != liste.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (auto it = liste.begin(); it != liste.end(); ++it)
    {
        if (*it > 5)
        {
            liste.erase(it);
        }
    }

    std::cout << "Liste nach erase() vor vAktualisieren():" << std::endl;
    for (auto it = liste.begin(); it != liste.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    liste.vAktualisieren();

    std::cout << "Liste nach vAktualisieren():" << std::endl;
    for (auto it = liste.begin(); it != liste.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    liste.push_front(0);
    liste.push_back(11);

    std::cout << "Liste nach Einfügen von 0 und 11 vor vAktualisieren():" << std::endl;
    for (auto it = liste.begin(); it != liste.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    liste.vAktualisieren();

    std::cout << "Liste nach vAktualisieren()" << std::endl;
    for (auto it = liste.begin(); it != liste.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    // vAufgabe_4();
    // vAufgabe_5();
    // vAufgabe_6();
    // vAufgabe_6_debugLosfahren();
    // vAufgabe_6_UI();
    vAufgabe_6a();
    return 0;
}
