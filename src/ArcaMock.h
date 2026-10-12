#ifndef ARCAMOCK_H
#define ARCAMOCK_H

#include <iostream>
#include <random>
#include <string>

using namespace std;

class ArcaMock {
public:
    static string generarCAE();
    static string generarTextoQR(char tipoFactura, int numero, double total, string cae);
};

#endif