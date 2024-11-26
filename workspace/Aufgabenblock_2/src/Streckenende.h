#ifndef STRECKENENDE_H
#define STRECKENENDE_H

#include "Fahrausnahme.h"
#include <iostream>

class Streckenende : public Fahrausnahme {
public:
    Streckenende(Fahrzeug& f, Weg& w) : Fahrausnahme(f, w) {}

    virtual void vBearbeiten() const override {
        std::cout << "Fahrzeug \"" << fahrzeug.getName()
                  << "\" hat das Streckenende auf Weg \"" << weg.getName() << "\" erreicht.\n";
    }

    virtual const char* what() const noexcept override {
        return "Streckenende Ausnahme";
    }
};

#endif // STRECKENENDE_H
