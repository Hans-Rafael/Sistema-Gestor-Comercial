// Autor: Integrante 2
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include "Producto.h"
using namespace std;

// Guarda los productos en memoria dinamica (new / delete).
// NO se copia un Inventario: siempre se pasa por referencia (Inventario& inv).
class Inventario {
private:
    Producto **productos;
    int capacidad;
    int cantidad;

public:
    Inventario(int cap);
    ~Inventario();

    // el Inventario se queda con el puntero (y lo libera en el destructor); false si esta lleno
    bool agregarProducto(Producto *p);
    int getCantidad() { return cantidad; }
    Producto* getProducto(int i) { return productos[i]; }

    // devuelve NULL si no existe
    Producto* buscarProducto(string codigo);

    // suma solo los lotes NO vencidos
    int stockTotal(Producto *p, string hoy);

    // devuelve false si no alcanza el stock
    bool descontarFEFO(Producto *p, int cantidad, string hoy);

    // true si stockTotal <= stockMinimo
    bool esStockCritico(Producto *p, string hoy);
};

#endif
