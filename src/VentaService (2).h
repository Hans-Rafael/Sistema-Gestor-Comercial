#ifndef VENTASERVICE_H
#define VENTASERVICE_H

#include <string>
#include "Producto.h"
using namespace std;

// Modulo Ventas (Integrante 3)
double precioConIVA(const Producto& prod);
char tipoComprobante(CondicionIVA cliente);

#endif