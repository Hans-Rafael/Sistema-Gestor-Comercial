// Autor: Integrante 3
#ifndef ARCAMOCK_H
#define ARCAMOCK_H

#include <iostream>
using namespace std;

// Simula a ARCA (no hay conexion real)
class ArcaMock {
public:
    // CAE = Codigo de Autorizacion Electronico: 14 digitos al azar (usar <random>)
    string generarCAE();

    // una linea de texto con tipo, numero, total y CAE
    string generarTextoQR(char tipoFactura, int numero, double total, string cae);
};

#endif
