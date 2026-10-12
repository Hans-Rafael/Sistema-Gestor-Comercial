#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <string>
#include "Producto.h"
#include "Tipos.h"

using namespace std;

const int MAX_CARRITO = 50;

class Venta {
private:
    Producto *productosCarrito[MAX_CARRITO];
    int cantidadesCarrito[MAX_CARRITO];
    int cantItems;
    int condicionCliente; // CONSUMIDOR_FINAL, etc.
    int medioPago;        // EFECTIVO, TARJETA, TRANSFERENCIA

public:
    Venta(int condicion, int pago) {
        cantItems = 0;
        condicionCliente = condicion;
        medioPago = pago;
    }

    bool agregarItem(Producto *p, int cantidad) {
        if (cantItems >= MAX_CARRITO) return false;
        productosCarrito[cantItems] = p;
        cantantidadesCarrito(cantidad); // corregido abajo
        cantItems++;
        return true;
    }
    
    // Método auxiliar corregido para la cantidad
    void setCantidadItem(int i, int c) {
        cantidadesCarrito[i] = c;
    }

    int getCantItems() { return cantItems; }
    Producto* getProductoItem(int i) { return productosCarrito[i]; }
    int getCantidadItem(int i) { return cantidadesCarrito[i]; }
    int getCondicionCliente() { return condicionCliente; }
    int getMedioPago() { return medioPago; }

    double precioConIVA(Producto *p);
    char tipoComprobante();
    double calcularTotal();
};

#endif