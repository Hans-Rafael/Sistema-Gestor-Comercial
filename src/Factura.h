// Autor: Integrante 3
#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include "Venta.h"

using namespace std;

// Datos fijos del emisor
const string EMISOR_RAZON_SOCIAL = "GEMAH.SA";
const string EMISOR_CUIT = "30-60473101-8";

class Factura {
protected:
    Venta *venta;
    int numero;
    double total;
    string cae;
    string cuitCliente; // solo se usa en factura A

public:
    Factura(Venta *v, int n, double t, string c, string cuit = "");
    virtual ~Factura() {}

    virtual char getTipo() { return '?'; }
    virtual string armarTexto();
    static string formatearMonto(double monto);
};

class FacturaA : public Factura {
public:
    FacturaA(Venta* venta, int numero, double total, string cae, string cuitCliente = "")
        : Factura(venta, numero, total, cae, cuitCliente) {}
    char getTipo() { return 'A'; }
};

class FacturaB : public Factura {
public:
    FacturaB(Venta *v, int n, double t, string c) 
        : Factura(v, n, t, c) {}
    char getTipo() { return 'B'; }
};

#endif