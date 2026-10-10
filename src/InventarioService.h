#ifndef INVENTARIOSERVICE_H
#define INVENTARIOSERVICE_H

#include <string>
#include "Producto.h"
using namespace std;

// devuelve nullptr si no existe
Producto* buscarProducto(Producto lista[], int cantidad, const string& codigo);

// devuelve false si el producto ya tiene MAX_LOTES lotes
bool agregarLote(Producto& prod, const string& vencimiento, int cantidad);

// suma solo los lotes NO vencidos
int stockTotal(const Producto& prod, const string& hoy);

// devuelve false si no alcanza el stock
bool descontarStockFEFO(Producto& prod, int cantidad, const string& hoy);

// true si stockTotal <= stockMinimo
bool esStockCritico(const Producto& prod, const string& hoy);

#endif
