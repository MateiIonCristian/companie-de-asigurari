#include <iostream>
#include "PolitaAuto.h"
#include "PolitaViata.h"
#include "PolitaCalatorie.h"
#include "GestionarePolite.h"

using namespace std;

void meniu() {
    GestionarePolite gestiune;
    gestiune.incarcaPoliteDinFisier();

    int optiune;
    do {
        cout << "\nMeniu:\n";
        cout << "1. Adauga polita auto\n";
        cout << "2. Adauga polita de viata\n";
        cout << "3. Adauga polita de calatorie\n";
        cout << "4. Afiseaza toate politele\n";
        cout << "5. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        string nume, prenume, marca, taraDestinatie;
        int varsta, km, capacitate, vechime, suma, durata;
        bool accidente, sanatos, sporturiExtreme;

        switch (optiune) {
        case 1:
            cout << "Introduceti detaliile pentru polita auto:\n";
            cout << "Nume client: "; cin >> nume;
            cout << "Prenume client: "; cin >> prenume;
            cout << "Varsta client: "; cin >> varsta;
            cout << "Marca masina: "; cin >> marca;
            cout << "Kilometri: "; cin >> km;
            cout << "Capacitate cilindrica: "; cin >> capacitate;
            cout << "Vechime sofer (ani): "; cin >> vechime;
            cout << "A avut accidente? (1 - Da, 0 - Nu): "; cin >> accidente;

            gestiune.adaugaPolita(
                new PolitaAuto(Client(nume, prenume, varsta), marca, km, capacitate, vechime, accidente));
            break;

        case 2:
            cout << "Introduceti detaliile pentru polita de viata:\n";
            cout << "Nume client: "; cin >> nume;
            cout << "Prenume client: "; cin >> prenume;
            cout << "Varsta client: "; cin >> varsta;
            cout << "Suma asigurata: "; cin >> suma;
            cout << "Este clientul sanatos? (1 - Da, 0 - Nu): "; cin >> sanatos;

            gestiune.adaugaPolita(
                new PolitaViata(Client(nume, prenume, varsta), suma, sanatos));
            break;

        case 3:
            cout << "Introduceti detaliile pentru polita de calatorie:\n";
            cout << "Nume client: "; cin >> nume;
            cout << "Prenume client: "; cin >> prenume;
            cout << "Varsta client: "; cin >> varsta;
            cout << "Tara destinatie: "; cin >> taraDestinatie;
            cout << "Durata calatorie (zile): "; cin >> durata;
            cout << "Sporturi extreme? (1 - Da, 0 - Nu): "; cin >> sporturiExtreme;

            gestiune.adaugaPolita(
                new PolitaCalatorie(Client(nume, prenume, varsta), taraDestinatie, durata, sporturiExtreme));
            break;

        case 4:
            gestiune.afiseazaToatePolitele();
            break;

        case 5:
            cout << "Iesire...\n";
            break;

        default:
            cout << "Optiune invalida!\n";
        }
    } while (optiune != 5);

    gestiune.salveazaPoliteInFisier();
}

int main() {
    meniu();
    return 0;
}
