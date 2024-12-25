#ifndef POLITA_H
#define POLITA_H

#include "Client.h"

class Polita {
protected:
    Client client;

public:
    Polita(const Client& c) : client(c) {}
    virtual ~Polita() {}

    virtual void afiseazaDetalii() const = 0;
    virtual string serializeaza() const = 0;
    Client getClient() const { return client; }
};

#endif
