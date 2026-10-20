// Autor: Integrante 5
// Uso: printf 'abc\n11\n5\n...' | ./test_validaciones  (cada lectura debe volver con el valor correcto)
#include <iostream>
#include "Validaciones.h"
using namespace std;

int fallas = 0;
void verificar(bool cond, string nombre) {
    if (cond) cout << "OK    " << nombre << endl;
    else { cout << "FALLA " << nombre << endl; fallas++; }
}

int main() {
    // entrada: "abc" y "11" fuera de rango, luego "5"
    int entero = leerEntero("Numero 1..10: ", 1, 10);
    verificar(entero == 5, "leerEntero descarta texto y fuera de rango");

    // entrada: "-3" (menor al minimo), luego "2.5"
    double monto = leerDouble("Monto >= 0.01: ", 0.01);
    verificar(monto == 2.5, "leerDouble acepta decimales validos");

    // entrada: "" (vacio), luego "con;puntoycoma", luego "Yerba"
    string texto = leerLinea("Texto: ");
    verificar(texto == "Yerba", "leerLinea rechaza vacio y ';'");

    cout << (fallas == 0 ? "\nTODO OK" : "\nHAY FALLAS") << endl;
    return fallas;
}
