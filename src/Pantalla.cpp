// Autor: Integrante 5
#include <iostream>
#include "Pantalla.h"
using namespace std;

// TODO (Integrante 5): dibujar un marco de texto alrededor del titulo
void mostrarMarco(const string& titulo) {
    cout << "===== " << titulo << " =====" << endl;
}

string conColor(const string& texto, const string& color) {
    return color + texto + COLOR_RESET;
}
