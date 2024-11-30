#include <iostream>
using namespace std;

#include "Weg.h"
#include "Kreuzung.h"
#include "Streckenende.h"

extern double dGlobaleZeit;

void Streckenende::vBearbeiten() const {
    auto pFahrzeugPtr = p_pWeg.pAbgabe(p_pFahrzeug);
    auto pKreuzung = p_pWeg.getZielKreuzung();

    pKreuzung->vTanken(*pFahrzeugPtr);
    auto pNeuerWeg = pKreuzung->pZufaelligerWeg(p_pWeg);

    std::cout << "ZEIT : " << dGlobaleZeit << std::endl;
    std::cout << "KREUZUNG : " << pKreuzung->getName() << " " << pKreuzung->getTankstelle() << std::endl;
    std::cout << "WECHSEL : " << p_pWeg.getName() << " → " << pNeuerWeg->getName() << std::endl;
    std::cout << "FAHRZEUG : " << pFahrzeugPtr->getName() << std::endl;
    std::cout << std::endl;

    pFahrzeugPtr->vNeueStrecke(*pNeuerWeg);
    pNeuerWeg->vAnnahme(std::move(pFahrzeugPtr));
}
