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

#include "global.h"

using namespace std;

void vAktuellenStateAusgeben(const std::vector<std::unique_ptr<Fahrzeug>>& fahrzeuge) {
    std::cout << "Zeitpunkt " << dGlobaleZeit << ": " << std::endl;
    std::cout << PKW::sKopf();

    for (auto& fahrzeug : fahrzeuge) {
    	std::cout << *fahrzeug << std::endl;
    }
    std::cout << std::endl;
}

void vAufgabe_2_runSimulation(std::vector<std::unique_ptr<Fahrzeug>>& fahrzeuge, double dDauer, double zeittakt) {
    vAktuellenStateAusgeben(fahrzeuge);
    // Simulation über mehrere Zeitschritte
    while (dGlobaleZeit < dDauer) {  // Simuliere bis dDauer
        dGlobaleZeit += zeittakt;
        if (dGlobaleZeit >= dDauer) {
            dGlobaleZeit = dDauer;
        }
        // Simuliere alle Fahrzeuge
        for (auto& fahrzeug : fahrzeuge) {
            fahrzeug->vSimulieren();
        }
        // Tanken
        if (dGlobaleZeit <= 3.0 && dGlobaleZeit + zeittakt >= 3.0) {
            for (auto& fahrzeug : fahrzeuge) {
                fahrzeug->dTanken();
            }
        }
        vAktuellenStateAusgeben(fahrzeuge);
    }
}

void vAufgabe_2_withSimpleTestData() {
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

    // Erzeugen der PKWs
    fahrzeuge.push_back(std::make_unique<PKW>("PKW1", 100.0, 5.0, 160.0));
    fahrzeuge.push_back(std::make_unique<PKW>("PKW2", 120.0, 6.0, 180.0));
    fahrzeuge.push_back(std::make_unique<PKW>("PKW3", 115.0, 2.0, 280.0));
    fahrzeuge.push_back(std::make_unique<PKW>("PKW4", 110.0, 1.2));
    fahrzeuge.push_back(std::make_unique<PKW>("PKW5", 180.0, 3.3));

    // Erzeugen der Fahrräder
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad1", 30.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad2", 25.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad3", 20.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad4", 15.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad5", 18.0));

    vAufgabe_2_runSimulation(fahrzeuge, 10.0, 0.3);
}


void vAufgabe_4() {
    // Erzeugen eines Weges
    Weg weg1("Autobahn A1", 100.0, Tempolimit::Autobahn);

    // Ausgabe des Weges
    Weg::vKopf();
    std::cout << weg1 << std::endl;
}


int main() {
    vAufgabe_2_withSimpleTestData();
    vAufgabe_4();
    return 0;
}
