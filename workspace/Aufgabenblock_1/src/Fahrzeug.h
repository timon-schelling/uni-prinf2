class Fahrzeug {
private:
	static int p_iMaxID;

    const int p_iID;

    std::string p_sName;
    double p_dMaxGeschwindigkeit = 0.0;
    double p_dGesamtStrecke = 0.0;
    double p_dGesamtZeit = 0.0;
    double p_dZeit = 0.0;

public:

    /// Konstruktor mit Name und MaxGeschwindigkeit
    Fahrzeug(const std::string& sName, double dMaxGeschwindigkeit);

    // Konstruktor mit Name
    Fahrzeug(const std::string& sName);

    // Default-Konstruktor
    Fahrzeug();

    // Destruktor
    ~Fahrzeug();

    // Getter-Funktion für den Namen (const, da sie nichts verändert)
    std::string getName() const;

    // Getter-Funktion für die ID (const, da sie nichts verändert)
    int getID() const;

    static std::string vKopf();

    std::string vAusgabe();
};
