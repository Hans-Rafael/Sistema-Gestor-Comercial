#ifndef VENTASERVICE_H
#define VENTASERVICE_H

#include "Tipos.h"
#include "Producto.h"
using namespace std;

const int MAX_ITEMS_CARRITO = 50; // maximo de items por venta

struct ItemCarrito {
    Producto* producto; // apunta al producto de la lista (no es una copia)
    int cantidad;
};

// precioBase * (1 + IVA / 100)
double precioConIVA(const Producto& prod);

// 'B' para Consumidor Final, 'A' para Responsable Inscripto o Monotributo
char tipoComprobante(CondicionIVA cliente);

// precio con IVA * cantidad
double subtotalItem(const ItemCarrito& item);

// suma de los subtotales del carrito
double totalCarrito(const ItemCarrito carrito[], int cantItems);

#endif
