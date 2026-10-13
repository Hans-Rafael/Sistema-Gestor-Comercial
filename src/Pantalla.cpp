// Autor: Integrante 5
#include <iostream>
#include "Pantalla.h"
using namespace std;

// TODO (Integrante 5): dibujar un marco de texto alrededor del titulo. Como arrancar:
//   cout << "+" << linea de '-' del largo de titulo.length() + 2 << "+" << endl;
//   cout << "| " << titulo << " |" << endl;  y repetir la linea de abajo (usar un for).
void mostrarMarco(string titulo) {
    cout << "===== " << titulo << " =====" << endl;
}

string conColor(string texto, string color) {
    return color + texto + COLOR_RESET;
}
