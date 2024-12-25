#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client {
private:
    string nume;
    string prenume;
    int varsta;

public:
    Client(string n, string p, int v) : nume(n), prenume(p), varsta(v) {}

    string getNumeComplet() const { return nume + " " + prenume; }
    int getVarsta() const { return varsta; }
    string getNume() const { return nume; }
    string getPrenume() const { return prenume; }
};

#endif
