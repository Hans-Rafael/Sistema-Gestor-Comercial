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

// monto con dos decimales: 1210.5 -> "1210.50" (to_string daria "1210.500000")
static string formatearMonto(double monto) {
    long centavos = (long)(monto * 100 + 0.5);
    string dec = to_string(centavos % 100);
    if (dec.length() < 2) dec = "0" + dec;
    return to_string(centavos / 100) + "." + dec;
}

string Factura::armarTexto() {
    string txt = "FACTURA " + string(1, getTipo()) + "\n";
    txt += "Numero: " + to_string(numero) + "\n";
    txt += "CAE: " + cae + "\n";
    txt += "Total: $" + formatearMonto(total) + "\n";
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