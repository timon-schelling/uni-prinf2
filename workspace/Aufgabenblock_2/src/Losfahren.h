#ifndef LOSFAHREN_H
#define LOSFAHREN_H

#include <iostream>
using namespace std;

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme {
public:
    Losfahren(Fahrzeug& f, Weg& w) : Fahrausnahme(f, w) {}

    virtual void vBearbeiten() const override;

    virtual const char* what() const noexcept override {
        return "Losfahren Ausnahme";
    }
};

#endif // LOSFAHREN_H
