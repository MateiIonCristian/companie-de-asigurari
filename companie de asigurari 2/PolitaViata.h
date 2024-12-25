#ifndef POLITA_VIATA_H
#define POLITA_VIATA_H

#include "Polita.h"
#include <iostream>

class PolitaViata : public Polita {
private:
    int sumaAsigurata;
    bool sanatos;
    double pret;

    void calculeazaPret() {
        pret = sumaAsigurata * 0.05;
        if (!sanatos) pret += 200;
    }

public:
    PolitaViata(const Client& c, int suma, bool san)
        : Polita(c), sumaAsigurata(suma), sanatos(san) {
        calculeazaPret();
    }

    void afiseazaDetalii() const override {
        if (!sanatos) {
            cout << "Polita Viata - Client: " << client.getNumeComplet()
                << " a fost respinsa din cauza starii de sanatate." << endl;
        }
        else {
            cout << "Polita Viata - Client: " << client.getNumeComplet()
                << ", Suma asigurata: " << sumaAsigurata
                << ", Pret: " << pret << " lei" << endl;
        }
    }

    string serializeaza() const override {
        return "Viata," + client.getNume() + "," + client.getPrenume() + "," + to_string(client.getVarsta()) + "," +
            to_string(sumaAsigurata) + "," + (sanatos ? "1" : "0") + "," + to_string(pret);
    }
};

#endif
