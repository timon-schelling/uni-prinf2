#include "Losfahren.h"
#include "Fahren.h"


void Losfahren::vBearbeiten() const {
#ifdef _DEBUG
    std::cout << "Fahrzeug \"" << p_pFahrzeug.getName()
              << "\" hat das Parken auf Weg \"" << p_pWeg.getName() << "\" beendet und fährt los.\n";
#endif
    // fahrzeug.setVerhalten(std::make_unique<Fahren>(p_peg));
}
