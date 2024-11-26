#ifndef LOSFAHREN_H
#define LOSFAHREN_H

#include "Fahrausnahme.h"
#include <iostream>

class Losfahren : public Fahrausnahme {
public:
    Losfahren(Fahrzeug& f, Weg& w) : Fahrausnahme(f, w) {}

    virtual void vBearbeiten() const override {
        std::cout << "Fahrzeug \"" << fahrzeug.getName()
                  << "\" hat gestartet auf Weg \"" << weg.getName() << "\".\n";
    }

    virtual const char* what() const noexcept override {
        return "Losfahren Ausnahme";
    }
};

#endif // LOSFAHREN_H
