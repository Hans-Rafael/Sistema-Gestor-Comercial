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

// TODO (Integrante 2): sumar los lotes con compararFechas(vencimiento, hoy) >= 0
int Inventario::stockTotal(Producto *, string) {
    return 0;
}

// TODO (Integrante 2): ordenar lotes por vencimiento (burbuja con compararFechas),
//   saltear vencidos y descontar lote por lote (la guia trae la version completa)
bool Inventario::descontarFEFO(Producto *, int, string) {
    return false;
}

// TODO (Integrante 2): stockTotal(p, hoy) <= p->getStockMinimo()
bool Inventario::esStockCritico(Producto *, string) {
    return false;
}
