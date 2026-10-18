// Autor: Integrante 3
#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "Tipos.h"
#include "Producto.h"

using namespace std;

class Venta {
private:
    Producto *productos[MAX_ITEMS_CARRITO];
    int cantidades[MAX_ITEMS_CARRITO];
    int cantItems;
    int condicionCliente; // CONSUMIDOR_FINAL, RESPONSABLE_INSCRIPTO, etc.
    int medioPago;        // EFECTIVO, TARJETA, TRANSFERENCIA

public:
    Venta(int condicion, int pago) {
        cantItems = 0;
        condicionCliente = condicion;
        medioPago = pago;
    }

    bool agregarItem(Producto *p, int cantidad);

    void setCondicionCliente(int c) { condicionCliente = c; }
    void setMedioPago(int m) { medioPago = m; }
    int getCantItems() { return cantItems; }
    Producto* getProductoItem(int i) { return productos[i]; }
    int getCantidadItem(int i) { return cantidades[i]; }
    int getCondicionCliente() { return condicionCliente; }
    int getMedioPago() { return medioPago; }

    double precioConIVA(Producto *p);
    char tipoComprobante();
    double subtotalItem(int i);
    double total();
};

#endif