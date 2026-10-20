// Autor: Integrante 3
#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include "Venta.h"

using namespace std;

class Factura {
protected:
    Venta *venta;
    int numero;
    double total;
    string cae;

public:
    Factura(Venta *v, int n, double t, string c);
    virtual ~Factura() {}

    virtual char getTipo() { return '?'; }
    virtual string armarTexto();
};

class FacturaA : public Factura {
public:
    FacturaA(Venta* venta, int numero, double total, string cae)
        : Factura(venta, numero, total, cae) {}
    char getTipo() { return 'A'; }
};

class FacturaB : public Factura {
public:
    FacturaB(Venta *v, int n, double t, string c) 
        : Factura(v, n, t, c) {}
    char getTipo() { return 'B'; }
};

#endif