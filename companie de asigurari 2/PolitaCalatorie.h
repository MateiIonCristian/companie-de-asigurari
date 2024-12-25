#ifndef POLITA_CALATORIE_H
#define POLITA_CALATORIE_H

#include "Polita.h"
#include <iostream>

class PolitaCalatorie : public Polita {
private:
    string taraDestinatie;
    bool sporturiExtreme;
    int durata;
    double pret;

    void calculeazaPret() {
        pret = 200 + durata * 20;
        if (sporturiExtreme) pret += 100;
    }

public:
    PolitaCalatorie(const Client& c, string tara, int durata, bool sporturi)
        : Polita(c), taraDestinatie(tara), durata(durata), sporturiExtreme(sporturi) {
        calculeazaPret();
    }

    void afiseazaDetalii() const override {
        cout << "Polita Calatorie - Client: " << client.getNumeComplet()
            << ", Destinatie: " << taraDestinatie
            << ", Durata: " << durata << " zile"
            << ", Sporturi extreme: " << (sporturiExtreme ? "Da" : "Nu")
            << ", Pret: " << pret << " lei" << endl;
    }

    string serializeaza() const override {
        return "Calatorie," + client.getNume() + "," + client.getPrenume() + "," + to_string(client.getVarsta()) + "," +
            taraDestinatie + "," + to_string(durata) + "," + (sporturiExtreme ? "1" : "0") + "," + to_string(pret);
    }
};

#endif
