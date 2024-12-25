#include "GestionarePolite.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

GestionarePolite::GestionarePolite() {}

GestionarePolite::~GestionarePolite() {
    for (auto polita : polite) {
        delete polita;
    }
}

void GestionarePolite::incarcaPoliteDinFisier() {
    ifstream fisier(numeFisier);
    if (!fisier.is_open())
        return;

    string linie;
    while (getline(fisier, linie)) {
        istringstream ss(linie);
        string tip, nume, prenume, marca, taraDestinatie;
        int varsta, km, capacitate, vechime, suma, durata;
        bool sanatos, accidente, sporturiExtreme;

        getline(ss, tip, ',');
        if (tip == "Auto") {
            getline(ss, nume, ',');
            getline(ss, prenume, ',');
            ss >> varsta >> marca >> km >> capacitate >> vechime >> accidente;
            polite.push_back(new PolitaAuto(Client(nume, prenume, varsta), marca, km, capacitate, vechime, accidente));
        }
        else if (tip == "Viata") {
            getline(ss, nume, ',');
            getline(ss, prenume, ',');
            ss >> varsta >> suma >> sanatos;
            polite.push_back(new PolitaViata(Client(nume, prenume, varsta), suma, sanatos));
        }
        else if (tip == "Calatorie") {
            getline(ss, nume, ',');
            getline(ss, prenume, ',');
            ss >> varsta >> taraDestinatie >> durata >> sporturiExtreme;
            polite.push_back(new PolitaCalatorie(Client(nume, prenume, varsta), taraDestinatie, durata, sporturiExtreme));
        }
    }

    fisier.close();
}

void GestionarePolite::salveazaPoliteInFisier() const {
    ofstream fisier(numeFisier);
    if (!fisier.is_open())
        return;

    for (const auto& polita : polite)
        fisier << polita->serializeaza() << endl;

    fisier.close();
}

void GestionarePolite::adaugaPolita(Polita* polita) {
    polite.push_back(polita);
}

void GestionarePolite::afiseazaToatePolitele() const {
    for (const auto& polita : polite)
        polita->afiseazaDetalii();
}
