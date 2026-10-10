#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Tipos.h"
using namespace std;

struct Cliente {
    string nombre; // sin ';' adentro
    string cuit; // texto, Ej: "20-12345678-9"
    CondicionIVA condicion = CONSUMIDOR_FINAL; // por defecto Consumidor Final
};

#endif
