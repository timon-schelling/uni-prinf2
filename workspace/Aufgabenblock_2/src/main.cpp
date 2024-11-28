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
#include "Kreuzung.h"

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

void vAufgabe_6a() {
    std::random_device seed;
    static std::mt19937 device(seed());
    // oder seed mit festem Wert
    // std::mt19937 device(0);
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

void vAufgabe7() {
    bInitialisiereGrafik(1000, 600);

    auto kr1 = std::make_shared<Kreuzung>("Kr1");
    auto kr2 = std::make_shared<Kreuzung>("Kr2", 1000.0);
    auto kr3 = std::make_shared<Kreuzung>("Kr3");
    auto kr4 = std::make_shared<Kreuzung>("Kr4");

    Kreuzung::vVerbinde("Kr1_Kr2", "Kr2_Kr1", 40.0, kr1, kr2, Tempolimit::Innerorts);
    Kreuzung::vVerbinde("Kr2_Kr3a", "Kr3_Kr2a", 115.0, kr2, kr3, Tempolimit::Autobahn);
    Kreuzung::vVerbinde("Kr2_Kr3b", "Kr3_Kr2b", 40.0, kr2, kr3, Tempolimit::Innerorts);
    Kreuzung::vVerbinde("Kr2_Kr4", "Kr4_Kr2", 55.0, kr2, kr4, Tempolimit::Innerorts);
    Kreuzung::vVerbinde("Kr3_Kr4", "Kr4_Kr3", 85.0, kr3, kr4, Tempolimit::Autobahn);
    Kreuzung::vVerbinde("Kr4_Kr4a", "Kr4_Kr4b", 130.0, kr4, kr4, Tempolimit::Landstrasse);

    int koordinatenStrasse1[] = { 680, 40, 680, 300 };
    int koordinatenStrasse2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
    int koordinatenStrasse3[] = { 680, 300, 680, 570 };
    int koordinatenStrasse4[] = { 680, 300, 320, 300 };
    int koordinatenStrasse5[] = { 680, 570, 500, 570, 350, 510, 320, 400, 320, 300 };
    int koordinatenStrasse6[] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };

    bZeichneStrasse("Kr1_Kr2", "Kr2_Kr1", 40, 2, koordinatenStrasse1);
    bZeichneStrasse("Kr2_Kr3a", "Kr3_Kr2a", 115, 6, koordinatenStrasse2);
    bZeichneStrasse("Kr2_Kr3b", "Kr3_Kr2b", 40, 2, koordinatenStrasse3);
    bZeichneStrasse("Kr2_Kr4", "Kr4_Kr2", 55, 2, koordinatenStrasse4);
    bZeichneStrasse("Kr3_Kr4", "Kr4_Kr3", 85, 5, koordinatenStrasse5);
    bZeichneStrasse("Kr4_Kr4a", "Kr4_Kr4b", 130, 7, koordinatenStrasse6);

    bZeichneKreuzung(680, 40);
    bZeichneKreuzung(680, 300);
    bZeichneKreuzung(680, 570);
    bZeichneKreuzung(320, 300);

    auto pkw1 = std::make_unique<PKW>("Auto1", 180.0, 5.0, 50.0);
    auto pkw2 = std::make_unique<PKW>("Auto2", 80.0, 4.0, 60.0);
    auto pkw3 = std::make_unique<PKW>("Auto3", 120.0, 6.0, 70.0);
    auto pkw4 = std::make_unique<PKW>("Auto4", 110.0, 5.5, 80.0);
    auto pkw5 = std::make_unique<PKW>("Auto5", 90.0, 4.5, 90.0);
    auto pkw6 = std::make_unique<PKW>("Auto6", 130.0, 6.5, 100.0);

    kr1->vAnnahme(std::move(pkw1), 0.0);
    kr1->vAnnahme(std::move(pkw2), 1.0);
    kr1->vAnnahme(std::move(pkw3), 2.0);
    kr1->vAnnahme(std::move(pkw4), 3.0);
    kr1->vAnnahme(std::move(pkw5), 4.0);
    kr1->vAnnahme(std::move(pkw6), 5.0);

    std::vector<std::shared_ptr<Kreuzung>> kreuzungen = { kr1, kr2, kr3, kr4 };

    for (dGlobaleZeit = 0.0; dGlobaleZeit <= 100.0; dGlobaleZeit += 0.02) {
        for (auto& kreuzung : kreuzungen) {
            kreuzung->vSimulieren();
            kreuzung->vZeichnen();
        }

        vSetzeZeit(dGlobaleZeit);
        vSleep(100);
    }

    vBeendeGrafik();
}

int main() {
    // vAufgabe_4();
    // vAufgabe_5();
    // vAufgabe_6();
    // vAufgabe_6_debugLosfahren();
    // vAufgabe_6_UI();
    vAufgabe7();
    // vAufgabe_6a();
    return 0;
}
