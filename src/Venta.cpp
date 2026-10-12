#include "Venta.h"

double Venta::precioConIVA(Producto *p) {
    return p->precioBase * (1 + p->porcentajeIVA / 100.0);
}

char Venta::tipoComprobante() {
    if (condicionCliente == CONSUMIDOR_FINAL) return 'B';
    return 'A';   // Responsable Inscripto o Monotributo
}