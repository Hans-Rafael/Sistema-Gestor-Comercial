// Autor: Integrante 5
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
using namespace std;

// repiten hasta que la entrada sea valida
int leerEntero(string mensaje, int minimo, int maximo);
double leerDouble(string mensaje, double minimo);
string leerLinea(string mensaje); // no vacio y sin ';'
bool cuitValido(string cuit); // 11 digitos (con o sin guiones) y digito verificador correcto
string leerCUIT(string mensaje); // repite hasta un CUIT valido; devuelve "XX-XXXXXXXX-X"
void limpiarPantalla();
void pausar(); // "Presione Enter para continuar..."

#endif
