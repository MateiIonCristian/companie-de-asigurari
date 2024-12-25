#ifndef POLITA_AUTO_H
#define POLITA_AUTO_H

#include "Polita.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class PolitaAuto : public Polita {
private:
    string marcaMasina;
    int kilometri;
    int capacitateCilindrica;
    int vechimeSofer;
    bool aAvutAccidente;
    string clasaBonusMalus;
    double pret;

    void calculeazaBonusMalus() {
        if (vechimeSofer < 2 || aAvutAccidente)
            clasaBonusMalus = "B0";
        else {
            int bonus = min(8, vechimeSofer);
            clasaBonusMalus = "B" + to_string(bonus);
        }
    }

    void calculeazaPret() {
        pret = 1000 + (kilometri / 1000) * 100 + capacitateCilindrica * 10;
        if (clasaBonusMalus == "B0") pret += 500;
    }

public:
    PolitaAuto(const Client& c, string marca, int km, int capacitate, int vechime, bool accidente)
        : Polita(c), marcaMasina(marca), kilometri(km), capacitateCilindrica(capacitate),
        vechimeSofer(vechime), aAvutAccidente(accidente) {
        calculeazaBonusMalus();
        calculeazaPret();
    }

    void afiseazaDetalii() const override {
        cout << "Polita Auto - Client: " << client.getNumeComplet()
            << ", Masina: " << marcaMasina
            << ", Bonus-Malus: " << clasaBonusMalus
            << ", Pret: " << pret << " lei" << endl;
    }

    string serializeaza() const override {
        return "Auto," + client.getNume() + "," + client.getPrenume() + "," + to_string(client.getVarsta()) + "," +
            marcaMasina + "," + to_string(kilometri) + "," + to_string(capacitateCilindrica) + "," +
            to_string(vechimeSofer) + "," + (aAvutAccidente ? "1" : "0") + "," + to_string(pret);
    }
};

#endif
