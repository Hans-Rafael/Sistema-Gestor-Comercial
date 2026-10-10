#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include "VentaService.h"
using namespace std;

// arma el texto del comprobante para mostrar o guardar (no usa cout)
string armarFactura(char tipoFactura, int numero, const ItemCarrito carrito[], int cantItems,
                    double total, const string& cae, const string& textoQR);

#endif
