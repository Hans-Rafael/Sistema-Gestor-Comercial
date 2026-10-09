#ifndef ARCAMOCKSERVICE_H
#define ARCAMOCKSERVICE_H

#include <string>
using namespace std;

// 14 digitos al azar (srand se llama una sola vez en main)
string generarCAESimulado();

// una linea de texto con tipo, numero, total y CAE(Código de Autorización Electrónico.)
//"Es un número de 14 dígitos que ARCA (ex AFIP) asigna a cada factura electrónica cuando la autoriza."
string generarTextoQR(char tipoFactura, int numero, double total, const string& cae);

#endif
