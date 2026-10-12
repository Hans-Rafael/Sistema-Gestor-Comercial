#include "Venta.h"

double Venta::precioConIVA(Producto *p) {
    return p->getPrecioBase() * (1 + p->getPorcentajeIVA() / 100.0);
}

char Venta::tipoComprobante() {
    if (condicionCliente == CONSUMIDOR_FINAL) return 'B';
    return 'A';   // Responsable Inscripto o Monotributo
}