#ifndef FAHRAUSNAHME_H
#define FAHRAUSNAHME_H

#include <exception>
#include "Fahrzeug.h"
#include "Weg.h"

class Fahrausnahme : public std::exception {
protected:
    Fahrzeug& fahrzeug;
    Weg& weg;

public:
    Fahrausnahme(Fahrzeug& f, Weg& w) : fahrzeug(f), weg(w) {}
    virtual void vBearbeiten() const = 0;

    // Optional: Überschreiben der what()-Methode
    virtual const char* what() const noexcept override = 0;
};

#endif // FAHRAUSNAHME_H
