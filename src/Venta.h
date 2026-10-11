// Autor: Integrante 3
#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "Tipos.h"
#include "Producto.h"
using namespace std;

// Una venta en curso: el carrito y la condicion del cliente
class Venta {
private:
    Producto *productos[MAX_ITEMS_CARRITO]; // apuntan a productos del inventario (no son copias)
    int cantidades[MAX_ITEMS_CARRITO];
    int cantItems;
    int condicionCliente; // CONSUMIDOR_FINAL por defecto

public:
    Venta() {
        cantItems = 0;
        condicionCliente = CONSUMIDOR_FINAL;
    }

    void setCondicionCliente(int c) { condicionCliente = c; }
    int getCantItems() { return cantItems; }
    Producto* getProducto(int i) { return productos[i]; }
    int getCantidad(int i) { return cantidades[i]; }

    // false si el carrito esta lleno o la cantidad es invalida
    bool agregarItem(Producto *p, int cantidad);

    // precioBase * (1 + IVA / 100)
    double precioConIVA(Producto *p);

    // 'B' para Consumidor Final, 'A' para Responsable Inscripto o Monotributo
    char tipoComprobante();

    // precio con IVA * cantidad del item i
    double subtotalItem(int i);

    // suma de los subtotales
    double total();
};

#endif
