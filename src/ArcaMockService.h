#ifndef ARCAMOCKSERVICE_H
#define ARCAMOCKSERVICE_H

#include <string>
using namespace std;

// 14 digitos al azar (srand se llama una sola vez en main)
string generarCAESimulado();

// una linea de texto con tipo, numero, total y CAE
// CAE = Codigo de Autorizacion Electronico: numero de 14 digitos que ARCA asigna a cada factura
string generarTextoQR(char tipoFactura, int numero, double total, const string& cae);

#endif
