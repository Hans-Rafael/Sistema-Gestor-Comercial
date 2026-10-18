// Autor: Integrante 5
#include <iostream>
#include "Pantalla.h"
using namespace std;

// marco de texto alrededor del titulo
void mostrarMarco(string titulo) {
    string linea = "+";
    for (int i = 0; i < (int)titulo.length() + 2; i++) linea += "-";
    linea += "+";
    cout << linea << endl;
    cout << "| " << titulo << " |" << endl;
    cout << linea << endl;
}

string conColor(string texto, string color) {
    return color + texto + COLOR_RESET;
}
