// Autor: Integrante 3
#include <iostream>
#include <random>
#include "ArcaMock.h"
using namespace std;

// TODO (Integrante 3): 14 digitos al azar (random_device rd; rd() % 10)
string ArcaMock::generarCAE() {
    return "00000000000000";
}

// TODO (Integrante 3): armar la linea de texto del QR
string ArcaMock::generarTextoQR(char, int, double, string) {
    return "";
}
