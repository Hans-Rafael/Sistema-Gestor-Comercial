// Autor: Integrante 1
#ifndef EXPORTADOR_H
#define EXPORTADOR_H

#include <iostream>
#include "Inventario.h"
using namespace std;

// Exporta los lotes vencidos, criticos o por vencer a un CSV separado por ';'
// devuelve false si no se pudo crear el archivo
bool exportarAlertasCSV(Inventario& inv, string archivo);

#endif
