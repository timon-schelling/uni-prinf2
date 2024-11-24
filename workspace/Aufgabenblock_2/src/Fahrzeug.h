// Prüfen, ob die Header-Datei bereits eingebunden wurde, Wenn nicht, dann einbinden und
// hier die Definitionen vornehmen, damit sie nicht doppelt eingebunden wird.
// Dies ermöglicht es, die Header-Datei in mehreren Dateien zu verwenden, ohne dass es zu
// Konflikten kommt.
// Funktionsweise:
// `#ifndef` steht für "if not defined" und fügt den folgenden Code nur ein, wenn die Konstante
// noch nicht definiert ist.
// `#define` definiert die Konstante, die in ifndef verwendet wird.
// zusammen bedeuten sie, dass der folgende Code nur einmal vom Präprozessor eingefügt wird.
#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <optional>
#include <string>
#include <limits>
#include <memory>
#include <iostream>

class Fahrzeug {
private:
    static int p_iMaxID; // Statische Klassenvariable, die die höchste aktuell vergebene ID speichert
    void vInit(); // Initialisierungsfunktion, die von den Konstruktoren aufgerufen wird

protected:
    int p_iID; // ID des Fahrzeugs

    std::string p_sName; // Name des Fahrzeugs
    double p_dMaxGeschwindigkeit = 0.0; // Maximale Geschwindigkeit des Fahrzeugs (in km/h)
    double p_dGeschwindigkeit = 0.0; // Aktuelle Geschwindigkeit des Fahrzeugs (in km/h)
    double p_dGesamtStrecke = 0.0; // Gesamtstrecke, die das Fahrzeug zurückgelegt hat (in km)
    double p_dGesamtZeit = 0.0; // Gesamtzeit, die das Fahrzeug unterwegs war (in h)
    double p_dZeit = 0.0; // Letzte Abfertigungszeit des Fahrzeugs (in h)

public:

    // Konstruktor mit Name und MaxGeschwindigkeit
    Fahrzeug(const std::string& sName, double dMaxGeschwindigkeit);

    // Konstruktor mit Name
    Fahrzeug(const std::string& sName);

    // Default-Konstruktor
    Fahrzeug();

    // Destruktor
    ~Fahrzeug();

    // Simulationsfunktion, virtuell, da sie in den abgeleiteten Klassen überschrieben wird
    virtual void vSimulieren();

    // Berechnet die aktuelle Geschwindigkeit des Fahrzeugs
    virtual double dGeschwindigkeit();

    // Tanken-Funktion, virtuell, da sie in den abgeleiteten Klassen überschrieben wird
    // schlechte Abbildung der Realität, da fahrräder nicht tanken können
    // würde man eigentlich anders modellieren
    virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());

    // Funktion soll für jeden fahrzeugtyp eine identifizierbaren Typen Beschreibung ausgeben
    // Muss in den abgeleiteten Klassen überschrieben werden, kosmetisches Feature für die Ausgabe
    virtual std::string sType() const;

    // Getter-Funktion für den Namen (const, da sie nichts verändert)
    std::string getName() const;

    // Getter-Funktion für die ID (const, da sie nichts verändert)
    int getID() const;

    // geforderte von der Aufgabenstellung obwohl weniger sinnvoll als vKopf(osstream)
    static std::string sKopf();

    // Statische Funktion, die den Tabellenkopf für die Ausgabe der Fahrzeuge erstellt
    static void vKopf(std::ostream& stream = std::cout);

    // Statische Funktion, die die daten eines Fahrzeugs als formatierte Tabellenzeile ausgibt
    // Hauptzweck ist, vermeidung von doppeltem code in den abgeleiteten klassen
    static void vZeile(
        std::ostream& stream,
        std::optional<int> iId,
        std::optional<std::string> sType,
        std::optional<std::string> sName,
        std::optional<double> dGeschwindigkeit,
        std::optional<double> dMaxGeschwindigkeit,
        std::optional<double> dGesamtstrecke,
        std::optional<double> dTankinhalt,
        std::optional<double> dVerbrauch
    );

    // Gibt die Daten des Fahrzeugs als formatierte Tabellenzeile in den übergebenen Stream aus
    virtual void vAusgeben(std::ostream& stream);

    // Vergleichsoperator kleiner als
    bool operator<(const Fahrzeug& f) const;

    // Verhindert das Kopieren Der Copy-Konstruktor wird gelöscht (delete),
    // weil es nicht sinnvoll ist, dass zwei verschiedene Fahrzeugobjekte dieselbe ID oder Ressource teilen.
    // Würden wir den Copy-Konstruktor nicht löschen, könnte es passieren,
    // dass mehrere Fahrzeuge dieselbe ID haben, was zu Verwirrung führt.
    Fahrzeug(const Fahrzeug&) = delete;

    // Ohne eigenen Zuweisungsoperator würde der Compiler einen impliziten Zuweisungsoperator generieren,
    // der alle Membervariablen kopiert, einschließlich der ID.
    // gleiche Begründung wie beim Copy-Konstruktor (siehe oben)
    Fahrzeug& operator=(Fahrzeug& other);
};

// Operator zum Ausgeben eines Fahrzeugs in einen Stream
std::ostream& operator<<(std::ostream& stream, Fahrzeug& fahrzeug);

#endif // FAHRZEUG_H
