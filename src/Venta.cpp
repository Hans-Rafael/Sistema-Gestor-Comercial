// Autor: Integrante 3
#include "Venta.h"

using namespace std;

Venta::Venta(int condicion) {
    cantItems = 0;
    condicionCliente = condicion;
    for (int i = 0; i < MAX_ITEMS_VENTA; i++) {
        productos[i] = NULL;
        cantidades[i] = 0;
    }
}

bool Venta::agregarItem(Producto *p, int cantidad) {
    if (p == NULL || cantidad <= 0 || cantItems >= MAX_ITEMS_VENTA) {
        return false;
    }
    productos[cantItems] = p;
    cantidades[cantItems] = cantidad;
    cantItems++;
    return true;
}

double Venta::precioConIVA(Producto *p) {
    if (p == NULL) return 0.0;
    return p->getPrecioBase() * (1.0 + (p->getPorcentajeIVA() / 100.0));
}

double Venta::subtotalItem(int i) {
    if (i < 0 || i >= cantItems || productos[i] == NULL) return 0.0;
    return precioConIVA(productos[i]) * cantidades[i];
}

double Venta::calcularTotal() {
    double total = 0.0;
    for (int i = 0; i < cantItems; i++) {
        total += subtotalItem(i);
    }
    return total;
}

double Venta::calcularPrecioSinIVA() {
    double neto = 0.0;
    for (int i = 0; i < cantItems; i++) {
        neto += productos[i]->getPrecioBase() * cantidades[i];
    }
    return neto;
}

double Venta::calcularIVAContenido() {
    double iva = 0.0;
    for (int i = 0; i < cantItems; i++) {
        iva += productos[i]->getPrecioBase() * (productos[i]->getPorcentajeIVA() / 100.0) * cantidades[i];
    }
    return iva;
}

char Venta::tipoComprobante() {
    if (condicionCliente == CONSUMIDOR_FINAL) return 'B';
    return 'A'; // Responsable Inscripto o Monotributo
}