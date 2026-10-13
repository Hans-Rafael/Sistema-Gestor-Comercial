// Autor: Integrante 3
#include <iostream>
#include "Venta.h"
using namespace std;

bool Venta::agregarItem(Producto *p, int cantidad) {
    if (p == NULL || cantidad <= 0 || cantItems >= MAX_ITEMS_CARRITO) return false;
    productos[cantItems] = p;
    cantidades[cantItems] = cantidad;
    cantItems++;
    return true;
}

double Venta::precioConIVA(Producto *p) {
    return p->getPrecioBase() * (1 + p->getPorcentajeIVA() / 100.0);
}

char Venta::tipoComprobante() {
    if (condicionCliente == CONSUMIDOR_FINAL) return 'B';
    return 'A';   // Responsable Inscripto o Monotributo
}

double Venta::subtotalItem(int idx) {
    if (idx < 0 || idx >= cantItems) return 0;
    return precioConIVA(productos[idx]) * cantidades[idx];
}

double Venta::total() {
    double suma = 0;
    for (int i = 0; i < cantItems; i++) {
        suma += subtotalItem(i);
    }
    return suma;
}