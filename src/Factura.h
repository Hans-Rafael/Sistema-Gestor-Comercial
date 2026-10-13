// Autor: Integrante 3
#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include "Venta.h"
using namespace std;

// Clase base. FacturaA y FacturaB heredan de ella; armarTexto es virtual
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

    virtual char getTipo() { return '?'; }

    // arma el texto del comprobante (no usa cout): lo muestra PantallaVenta
    virtual string armarTexto();
};

class FacturaA : public Factura {
public:
    FacturaA(Venta *v, int n, double t, string c, string qr) : Factura(v, n, t, c, qr) {}
    char getTipo() { return 'A'; }
};

class FacturaB : public Factura {
public:
    FacturaB(Venta *v, int n, double t, string c, string qr) : Factura(v, n, t, c, qr) {}
    char getTipo() { return 'B'; }
};

#endif
