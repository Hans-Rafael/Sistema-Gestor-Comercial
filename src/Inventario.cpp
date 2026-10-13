// Autor: Integrante 2
#include <iostream>
#include <cstdlib>
#include "Inventario.h"
#include "Fechas.h"
using namespace std;

Inventario::Inventario(int cap) {
    capacidad = cap;
    cantidad = 0;
    productos = new Producto*[capacidad];
}

Inventario::~Inventario() {
    for (int i = 0; i < cantidad; i++) {
        delete productos[i];
    }
    delete[] productos;
}

bool Inventario::agregarProducto(Producto *p) {
    if (cantidad >= capacidad) return false;
    productos[cantidad] = p;
    cantidad++;
    return true;
}

Producto* Inventario::buscarProducto(string codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (productos[i]->getCodigoBarras() == codigo) return productos[i];
    }
    return NULL;
}

// TODO (Integrante 2): sumar solo los lotes NO vencidos. Como arrancar:
//   int total = 0;
//   for (int i = 0; i < p->getCantLotes(); i++) {
//       Lote *l = p->getLote(i);   // puntero, NO copia
//       if (compararFechas(l->getFechaVencimiento(), hoy) >= 0) total += l->getCantidad();
//   }
//   return total;
int Inventario::stockTotal(Producto *, string) {
    return 0;
}

// TODO (Integrante 2): FEFO. Pasos (la guia, seccion 7, trae el codigo completo):
//   0) si cantidad <= 0 o stockTotal(p, hoy) < cantidad -> return false
//   1) ordenar los lotes con burbuja: si compararFechas(a, b) > 0 intercambiar (Lote aux = *a; *a = *b; *b = aux;)
//   2) recorrer los lotes: saltear los vencidos (compararFechas(fecha, hoy) < 0)
//      sacar = el menor entre l->getCantidad() y lo que falta; l->setCantidad(...); cantidad -= sacar;
//   Ojo: 3 unidades en un lote y 4 en otro, una venta de 5 debe funcionar.
bool Inventario::descontarFEFO(Producto *, int, string) {
    return false;
}

// TODO (Integrante 2): return stockTotal(p, hoy) <= p->getStockMinimo();
bool Inventario::esStockCritico(Producto *, string) {
    return false;
}
