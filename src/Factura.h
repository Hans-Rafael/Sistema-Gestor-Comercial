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
    Factura(Venta *v, int n, double t, string c, string qr) {
        venta = v;
        numero = n;
        total = t;
        cae = c;
        textoQR = qr;
    }

    virtual ~Factura() {}

    virtual char getTipo() {
        return '?';
    }

    virtual string armarTexto() {
        string txt = "FACTURA " + to_string(getTipo()) + "\n";
        txt += "Numero: " + to_string(numero) + "\n";
        txt += "CAE: " + cae + "\n";
        txt += "Total: $" + to_string(total) + "\n";
        txt += "QR: " + textoQR + "\n";
        return txt;
    }
};

class FacturaA : public Factura {
public:
    FacturaA(Venta *v, int n, double t, string c, string qr) : Factura(v, n, t, c, qr) {}
    
    char getTipo() override {
        return 'A';
    }
};

class FacturaB : public Factura {
public:
    FacturaB(Venta *v, int n, double t, string c, string qr) : Factura(v, n, t, c, qr) {}
    
    char getTipo() override {
        return 'B';
    }
};

#endif