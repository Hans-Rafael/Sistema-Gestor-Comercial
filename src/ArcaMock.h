// Autor: Integrante 3
#ifndef ARCAMOCK_H
#define ARCAMOCK_H

#include <iostream>
using namespace std;

class ArcaMock {
public:
    static string generarCAE();
    static string generarTextoQR(char tipoFactura, int numero, double total, string cae);
};

#endif