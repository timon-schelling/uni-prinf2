#include "Streckenende.h"

#include "Weg.h"

void Streckenende::vBearbeiten() const {
#ifdef _DEBUG
    std::cout << "Fahrzeug \"" << p_pFahrzeug.getName()
              << "\" hat das Streckenende auf Weg \"" << p_pWeg.getName() << "\" erreicht.\n";
#endif
    p_pWeg.pAbgabe(p_pFahrzeug);
}
