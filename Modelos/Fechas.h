#ifndef FECHAS_H
#define FECHAS_H

#include <string>
using namespace std;

string fechaHoy(); // "2026-10-09"
string fechaEnDias(int n); // hoy + n dias (n puede ser negativo)
int diasHasta(const string& fechaISO); // dias desde hoy (negativo = ya paso)
string convertirFecha(const string& ddmmaaaa); // "20/11/2026" -> "2026-11-20"

#endif
