#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "Tipos.h"
#include "Lote.h"
using namespace std;

struct Producto {
    string codigoBarras; // 10 digitos simulados. Ej: "7791234567"
    string nombre; // Ej: "Leche Entera 1L" (sin ';' adentro)
    double precioBase; // precio SIN IVA. Ej: 1000.00
    double porcentajeIVA; // Ej: 21.0 o 10.5
    int stockMinimo; // Ej: 10 (critico si stock <= 10)
    Lote lotes[MAX_LOTES]; // partidas compradas
    int cantLotes = 0; // cuantos lotes hay cargados
};

#endif
