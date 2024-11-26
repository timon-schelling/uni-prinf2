#ifndef PARKEN_H
#define PARKEN_H

class Parken : public Verhalten {
private:
    double p_dStartZeit;
    bool p_bStartErreicht;

public:
    Parken(Weg& weg, double dStartZeit) : Verhalten(weg), p_dStartZeit(dStartZeit), p_bStartErreicht(false) { }
    virtual double dStrecke(Fahrzeug& fahrzeug, double dDeltaZeit) override;

};

#endif // PARKEN_H
