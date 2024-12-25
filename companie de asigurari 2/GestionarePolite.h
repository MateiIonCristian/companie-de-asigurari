#pragma once
#include <vector>
#include "PolitaAuto.h"
#include "PolitaViata.h"
#include "PolitaCalatorie.h"

class GestionarePolite {
private:
    std::vector<Polita*> polite;
    const std::string numeFisier = "polite.txt";

public:
    GestionarePolite();
    ~GestionarePolite();

    void incarcaPoliteDinFisier();
    void salveazaPoliteInFisier() const;
    void adaugaPolita(Polita* polita);
    void afiseazaToatePolitele() const;
};
