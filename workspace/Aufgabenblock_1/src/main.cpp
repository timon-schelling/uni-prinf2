#define DEBUG 1

#include <iostream>  // Für Output nach cout
#include <memory>    // Für Smartpointer
#include <vector>    // Für den Vektor
#include <string>    // Für String
#include <algorithm>  // Für sorting

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

#include "global.h"

using namespace std;

void vTestFahrzeug() {
    // Teste die Fahrzeug-Klasse mit cpp assert
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

    // Erzeuge Fahrzeuge
    fahrzeuge.push_back(std::make_unique<Fahrzeug>("Auto 1", 100.0));
}

void vTests() {
    vTestFahrzeug();
}

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

    std::cout << "\nuse_count vor Zuweisung: " << sharedFahrzeug1.use_count() << std::endl;

    // Erzeuge einen weiteren shared_ptr auf sharedFahrzeug1
    std::shared_ptr<Fahrzeug> sharedFahrzeug3 = sharedFahrzeug1;

    std::cout << "use_count nach Zuweisung: " << sharedFahrzeug1.use_count() << std::endl;

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
        std::cout << "Fahrzeug im Vektor: Name = " << f->getName() << ", ID = " << f->getID() << std::endl;
    }

    std::cout << "\nSpeichern der shared_ptr einen Vektor:\n";

    // Vektor von shared_ptr
    std::vector<std::shared_ptr<Fahrzeug>> sharedFahrzeugVector;

    // Einfügen von shared_ptr-Fahrzeugen in den Vektor
    std::cout << "use_count vor Zuweisung ohne move: " << sharedFahrzeug1.use_count() << std::endl;
    sharedFahrzeugVector.push_back(sharedFahrzeug1);  // Normales Einfügen
    std::cout << "use_count vor Zuweisung ohne move: " << sharedFahrzeug1.use_count() << std::endl;

    std::cout << "use_count vor Zuweisung mit move: " << sharedFahrzeug1.use_count() << std::endl;
    sharedFahrzeugVector.push_back(std::move(sharedFahrzeug2));
    std::cout << "use_count vor Zuweisung mit move: " << sharedFahrzeug1.use_count() << std::endl;

    // Ausgabe der Referenzanzahl für sharedFahrzeug1
    std::cout << "use_count von sharedFahrzeug1 nach dem Einfügen: " << sharedFahrzeug1.use_count() << std::endl;

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
    std::cout << Fahrzeug::sKopf();
    for (const auto& f : fahrzeugVector) {
        f->vAusgeben(std::cout);
        std::cout << std::endl;
    }
    std::cout << std::endl;
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
        std::cout << Fahrzeug::sKopf();
        for (auto& fahrzeug : fahrzeuge) {
        	fahrzeug->vAusgeben(std::cout);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void vAktuellenStateAusgeben(const std::vector<std::unique_ptr<Fahrzeug>>& fahrzeuge) {
    std::cout << "Zeitpunkt " << dGlobaleZeit << ": " << std::endl;
    std::cout << Fahrzeug::sKopf();
    for (auto& fahrzeug : fahrzeuge) {
    	std::cout << *fahrzeug << std::endl;
    }
    std::cout << std::endl;
}

void vAufgabe_1b() {
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

    fahrzeuge.push_back(std::make_unique<PKW>("Auto 1", 100.0, 5.0, 160.0));
    fahrzeuge.push_back(std::make_unique<PKW>("Auto 2", 120.0, 6.0, 180.0));
    fahrzeuge.push_back(std::make_unique<PKW>("Auto 3", 115.0, 2.0, 280.0));
    fahrzeuge.push_back(std::make_unique<PKW>("Auto 4", 110.0, 1.2));
    fahrzeuge.push_back(std::make_unique<PKW>("Auto 5", 180.0, 3.3));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad 1", 30.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad 2", 25.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad 3", 20.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad 4", 15.0));
    fahrzeuge.push_back(std::make_unique<Fahrrad>("Fahrrad 5", 18.0));

    double zeittakt = 2.0;  // Zeittakt von 0.5 Stunden
    double endzeit = 100.0;   // Simuliere über 5 Stunden

    vAktuellenStateAusgeben(fahrzeuge);

    while (dGlobaleZeit + zeittakt <= endzeit) {
        dGlobaleZeit += zeittakt;  // Globale Zeit erhöhen

        // Simuliere jedes Fahrzeugs aus
        for (auto& fahrzeug : fahrzeuge) {
        	fahrzeug->vSimulieren();
        }

        vAktuellenStateAusgeben(fahrzeuge);
    }
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

        // Hier wird eine andere löung als in den Aufgaben gewählt,
        // da eine vergleich von doubles mit fehler nur funktioniert,
        // wenn der zeittakt der Simulation etwa 3.0 plus/minus fehler als schritt enthält
        // hier wird stattdessen einfach getankt,
        // wenn wir uns im Simulationsschritt befinden der das dritte Stunden Ende enthält

        // Tanken, wenn wir uns im Simulationsschritt befinden der das dritte Stunden Ende enthält
        // Teoretisch könnte hier auch erst ein zeitschritt bis genau 3.0 simuliert werden,
        // dann getankt und dann den restlichen zeitschritt simuliert werden
        // mit dieser Implementierung wird liegenbleiben während dieses zeitschritts nicht mit berechnet
        // vereinfachen könnte hier simulieren von allen fahrzeugen mit parameter delta zeit,
        // anstatt die globale zeit zu erhöhen und danach zu simulieren
        // nicht angegebene seiteneffekte etc. (aber wir machen ja cpp also who cares I guess)
        if (dGlobaleZeit <= 3.0 && dGlobaleZeit + zeittakt >= 3.0) {
            for (auto& fahrzeug : fahrzeuge) {
                fahrzeug->dTanken();
            }
        }

        vAktuellenStateAusgeben(fahrzeuge);
    }
}

void vAufgabe_2() {
    std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;
    int nPKWs, nFahrräder;

    // Einlesen der Anzahl der PKWs und Fahrräder
    std::cout << "Geben Sie die Anzahl der zu erzeugenden PKWs ein: ";
    std::cin >> nPKWs;
    std::cout << "Geben Sie die Anzahl der zu erzeugenden Fahrräder ein: ";
    std::cin >> nFahrräder;

    // Erzeugen der PKWs
    for (int i = 0; i < nPKWs; ++i) {
        std::string name = "PKW" + std::to_string(i + 1);
        double maxGeschwindigkeit, verbrauch;
        std::cout << "Geben Sie die maximale Geschwindigkeit für " << name << " ein: ";
        std::cin >> maxGeschwindigkeit;
        std::cout << "Geben Sie den Verbrauch (Liter/100km) für " << name << " ein: ";
        std::cin >> verbrauch;

        // PKW in den Vektor einfügen
        fahrzeuge.push_back(std::make_unique<PKW>(name, maxGeschwindigkeit, verbrauch));
    }

    // Erzeugen der Fahrräder
    for (int i = 0; i < nFahrräder; ++i) {
        std::string name = "Fahrrad" + std::to_string(i + 1);
        double maxGeschwindigkeit;
        std::cout << "Geben Sie die maximale Geschwindigkeit für " << name << " ein: ";
        std::cin >> maxGeschwindigkeit;

        // Fahrrad in den Vektor einfügen
        fahrzeuge.push_back(std::make_unique<Fahrrad>(name, maxGeschwindigkeit));
    }

    double dDauer;
    std::cout << "Geben Sie den Dauer für die Simulation ein (z.B. 0.5 für 30 Minuten): ";
    std::cin >> dDauer;

    double zeittakt;
    std::cout << "Geben Sie den Zeittakt für die Simulation ein (z.B. 0.5 für 30 Minuten): ";
    std::cin >> zeittakt;

    vAufgabe_2_runSimulation(fahrzeuge, dDauer, zeittakt);
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

void vAufgabe_3_runSimulation(std::vector<std::unique_ptr<Fahrzeug>>& fahrzeuge, double dDauer, double zeittakt) {
    double dDauerAbsolut = dGlobaleZeit + dDauer;
    while (dGlobaleZeit < dDauerAbsolut) {
        dGlobaleZeit += zeittakt;
        if (dGlobaleZeit >= dDauerAbsolut) {
            dGlobaleZeit = dDauerAbsolut;
        }
        for (auto& fahrzeug : fahrzeuge) {
            fahrzeug->vSimulieren();
        }
    }
}

void vAufgabe_3 () {
    auto pkw1 = std::make_unique<PKW>("PKW1", 100.0, 5.0, 160.0);
    auto pkw2 = std::make_unique<PKW>("PKW2", 120.0, 6.0, 180.0);
    auto pkw3 = std::make_unique<PKW>("PKW3", 115.0, 2.0, 280.0);
    auto pkw4 = std::make_unique<PKW>("PKW4", 110.0, 1.2);
    auto pkw5 = std::make_unique<PKW>("PKW5", 180.0, 3.3);

    auto pkw1copy = std::make_unique<PKW>();
    *pkw1copy = *pkw1;
    auto pkw2copy = std::make_unique<PKW>();
    *pkw2copy = *pkw2;
    auto pkw3copy = std::make_unique<PKW>();
    *pkw3copy = *pkw3;
    auto pkw4copy = std::make_unique<PKW>();
    *pkw4copy = *pkw4;
    auto pkw5copy = std::make_unique<PKW>();
    *pkw5copy = *pkw5;

    std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge;

    fahrzeuge.push_back(std::move(pkw1));
    fahrzeuge.push_back(std::move(pkw2));
    fahrzeuge.push_back(std::move(pkw3));
    fahrzeuge.push_back(std::move(pkw4));
    fahrzeuge.push_back(std::move(pkw5));

    vAktuellenStateAusgeben(fahrzeuge);

    vAufgabe_3_runSimulation(fahrzeuge, 48.0, 0.3);

    vAktuellenStateAusgeben(fahrzeuge);

    for (auto& fahrzeug : fahrzeuge) {
        fahrzeug->dTanken();
    }
    std::cout << "Alle original Fahrzeuge haben getankt.\n";

    vAktuellenStateAusgeben(fahrzeuge);

    fahrzeuge.push_back(std::move(pkw1copy));
    fahrzeuge.push_back(std::move(pkw2copy));
    fahrzeuge.push_back(std::move(pkw3copy));
    fahrzeuge.push_back(std::move(pkw4copy));
    fahrzeuge.push_back(std::move(pkw5copy));

    std::cout << "Alle kopierten Fahrzeuge wurden hinzugefügt.\n";

    vAktuellenStateAusgeben(fahrzeuge);

    vAufgabe_3_runSimulation(fahrzeuge, 48.0, 0.01);

    std::cout << "Simulation mit allen Fahrzeugen wurde durchgeführt.\n";

    vAktuellenStateAusgeben(fahrzeuge);

    std::cout << "Sortieren der Fahrzeuge nach der zurückgelegten Gesamtstrecke (absteigend):\n";

    // Sortieren der Fahrzeuge nach der zurückgelegten Gesamtstrecke absteigend
    // wollte mich hier hauptsächlich erinnern wie lambdas in cpp funktionieren
    std::sort(fahrzeuge.begin(), fahrzeuge.end(), [](const std::unique_ptr<Fahrzeug>& a, const std::unique_ptr<Fahrzeug>& b) {
        // hier wird der operator < von fahrzeug aufgerufen, der überladen wurde
        return *a < *b;
    });

    vAktuellenStateAusgeben(fahrzeuge);

    std::cout << "Sortieren der Fahrzeuge nach der zurückgelegten Gesamtstrecke (aufsteigend):\n";

    // Sortieren der Fahrzeuge nach der zurückgelegten Gesamtstrecke aufsteigend
    std::sort(fahrzeuge.begin(), fahrzeuge.end(), [](const std::unique_ptr<Fahrzeug>& a, const std::unique_ptr<Fahrzeug>& b) {
        return !(*a < *b);
    });

    vAktuellenStateAusgeben(fahrzeuge);
}

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

void vAufgabe_Probe() {

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{15};
    double dTakt = 0.3;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 229, 9.6));
    vecFahrzeuge.push_back(make_unique <Fahrrad>("BMX", 24.7));
    for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end()) {
            std::cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end()) {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}

int main() {
    // vAufgabe_1();
    // vAufgabe_1_test_table();
    // vAufgabe_1a();
    // vAufgabe_1b();
    // vAufgabe_2_withSimpleTestData();

    // // muss hier zurückgesetzt werden, da global
    // // vereinfachen könnte hier simulieren von allen fahrzeugen mit parameter delta zeit,
    // // anstatt die globale zeit zu erhöhen und danach zu simulieren
    // // nicht angegebene seiteneffekte etc. (aber wir machen ja cpp also who cares I guess)
    // dGlobaleZeit = 0.0;

    // vAufgabe_2();

    // vAufgabe_3();
    vAufgabe_Probe();
    return 0;
}
