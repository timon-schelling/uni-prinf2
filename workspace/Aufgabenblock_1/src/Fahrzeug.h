class Fahrzeug {
private:
    std::string p_sName;
    const int p_iID;
    static int p_iMaxID;

public:
    // Konstruktor mit Initialisierungsliste
    Fahrzeug(const std::string& name);

    // Default-Konstruktor
    Fahrzeug();

    // Destruktor
    ~Fahrzeug();

    // Getter-Funktion für den Namen (const, da sie nichts verändert)
    std::string getName() const;

    // Getter-Funktion für die ID (const, da sie nichts verändert)
    int getID() const;
};

