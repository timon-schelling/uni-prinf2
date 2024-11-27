#ifndef FAHRAUSNAHME_H
#define FAHRAUSNAHME_H

#include <exception>
#include "Fahrzeug.h"
#include "Weg.h"

class Fahrausnahme : public std::exception {
protected:
    Fahrzeug& p_pFahrzeug;
    Weg& p_pWeg;

public:
    Fahrausnahme(Fahrzeug& f, Weg& w) : p_pFahrzeug(f), p_pWeg(w) {}
    virtual void vBearbeiten() const = 0;

    // Optional: Überschreiben der what()-Methode
    virtual const char* what() const noexcept override = 0;
};

#endif // FAHRAUSNAHME_H
