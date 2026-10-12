#include "ArcaMock.h"

string ArcaMock::generarCAE() {
    random_device rd;
    string cae = "";
    for (int i = 0; i < 14; i++) {
        cae += char('0' + (rd() % 10));
    }
    return cae;
}

string ArcaMock::generarTextoQR(char tipoFactura, int numero, double total, string cae) {
    string nro = to_string(numero);
    while (nro.length() < 8) {
        nro = "0" + nro;
    }
    long centavos = (long)(total * 100 + 0.5);
    string dec = to_string(centavos % 100);
    if (dec.length() < 2) {
        dec = "0" + dec;
    }
    return string("ARCA-QR|Factura ") + tipoFactura + "|Nro " + nro
         + "|Total " + to_string(centavos / 100) + "." + dec + "|CAE " + cae;
}