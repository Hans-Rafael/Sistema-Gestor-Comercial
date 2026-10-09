#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
using namespace std;

// repiten hasta que la entrada sea valida
int leerEntero(const string& mensaje, int minimo, int maximo);
double leerDouble(const string& mensaje, double minimo);
string leerLinea(const string& mensaje); // no vacio y sin ';'
void limpiarPantalla();

#endif
