// Autor: Integrante 3
#include "VentaService.h"
using namespace std;

double precioConIVA(const Producto& prod) {
    return prod.precioBase * (1 + prod.porcentajeIVA / 100.0);
}

char tipoComprobante(CondicionIVA cliente) {
    if (cliente == CONSUMIDOR_FINAL) return 'B';
    return 'A';   // Responsable Inscripto o Monotributo
}

// TODO (Integrante 3): implementar las 2 funciones siguientes
double subtotalItem(const ItemCarrito&) {
    return 0;
}

double totalCarrito(const ItemCarrito[], int) {
    return 0;
}
