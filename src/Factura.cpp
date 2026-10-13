// Autor: Integrante 3
#include <iostream>
#include "Factura.h"

using namespace std;

Factura::Factura(Venta *v, int n, double t, string c, string qr) {
    venta = v;
    numero = n;
    total = t;
    cae = c;
    textoQR = qr;
}

char Factura::getTipo() {
    return '?';
}

string Factura::armarTexto() {
    string txt = "FACTURA " + string(1, getTipo()) + "\n";
    txt += "Numero: " + to_string(numero) + "\n";
    txt += "CAE: " + cae + "\n";
    txt += "Total: $" + to_string(total) + "\n";
    txt += "QR: " + textoQR + "\n";
    return txt;
}

FacturaA::FacturaA(Venta *v, int n, double t, string c, string qr) : Factura(v, n, t, c, qr) {}

char FacturaA::getTipo() {
    return 'A';
}

FacturaB::FacturaB(Venta *v, int n, double t, string c, string qr) : Factura(v, n, t, c, qr) {}

char FacturaB::getTipo() {
    return 'B';
}