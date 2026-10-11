// Autor: Integrante 5
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
using namespace std;

// repiten hasta que la entrada sea valida
int leerEntero(string mensaje, int minimo, int maximo);
double leerDouble(string mensaje, double minimo);
string leerLinea(string mensaje); // no vacio y sin ';'
void limpiarPantalla();
void pausar(); // "Presione Enter para continuar..."

#endif
