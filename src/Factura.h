// Autor: Integrante 3
#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <string>
#include "Venta.h"
#include "Tipos.h"

using namespace std;

class Factura {
protected:
    Venta *venta;
    int numero;
    double total;
    string cae;
    string textoQR;

public:
    Factura(Venta *v, int n, double t, string c, string qr);
    virtual ~Factura() {}
    virtual char getTipo();
    virtual string armarTexto();
};

class FacturaA : public Factura {
public:
    FacturaA(Venta *v, int n, double t, string c, string qr);
    char getTipo() override;
};

class FacturaB : public Factura {
public:
    FacturaB(Venta *v, int n, double t, string c, string qr);
    char getTipo() override;
};

#endif