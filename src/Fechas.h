// Autor: Integrante 1
#ifndef FECHAS_H
#define FECHAS_H

#include <iostream>
using namespace std;

// Todas las fechas del proyecto son texto "DD-MM-AAAA" (Ej: "09-10-2026").
// NO compararlas con < o > (daria resultados incorrectos): usar compararFechas.
// No usamos <ctime>: la fecha de "hoy" se la pide main al usuario con setFechaHoy.

void setFechaHoy(string fecha); // guarda la fecha de hoy (ya validada con convertirFecha)
string fechaHoy(); // "09-10-2026"
string fechaEnDias(int n); // hoy + n dias (n puede ser negativo)
int diasHasta(string fecha); // dias desde hoy (negativo = ya paso)

// "20/11/2026" o "20-11-2026" -> "20-11-2026" (devuelve "" si es invalida)
string convertirFecha(string ddmmaaaa);

// negativo si a es anterior a b, 0 si son iguales, positivo si a es posterior a b
int compararFechas(string a, string b);

#endif
