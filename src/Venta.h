// Autor: Integrante 3
#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "Producto.h"
#include "Tipos.h"

using namespace std;

const int MAX_ITEMS_VENTA = 50;

class Venta {
private:
    Producto* productos[MAX_ITEMS_VENTA];
    int cantidades[MAX_ITEMS_VENTA];
    int cantItems;
    int condicionCliente; // CONSUMIDOR_FINAL, RESPONSABLE_INSCRIPTO, MONOTRIBUTO

public:
    Venta(int condicion);
    bool agregarItem(Producto *p, int cantidad);
    int getCantidadTotalItems() { return cantItems; }
    Producto* getProductoItem(int i) { return productos[i]; }
    int getCantidadItem(int i) { return cantidades[i]; }
    double subtotalItem(int i);
    double precioConIVA(Producto *p);
    double calcularTotal();
    double calcularPrecioSinIVA();
    double calcularIVAContenido(); // IVA incluido en el precio: precio con IVA - precio sin IVA
    char tipoComprobante();
};

#endif