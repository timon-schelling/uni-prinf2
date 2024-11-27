#ifndef STRECKENENDE_H
#define STRECKENENDE_H

#include "Fahrausnahme.h"
#include <iostream>

class Streckenende : public Fahrausnahme {
public:
    Streckenende(Fahrzeug& f, Weg& w) : Fahrausnahme(f, w) {}

    virtual void vBearbeiten() const override;

    virtual const char* what() const noexcept override {
        return "Streckenende Ausnahme";
    }
};

#endif // STRECKENENDE_H
