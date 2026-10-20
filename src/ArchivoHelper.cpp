// Autor: Integrante 1
#include <iostream>
#include <fstream>
#include "ArchivoHelper.h"
#include "Fechas.h"
using namespace std;

void guardarProductos(Inventario& inv) {
    ofstream archivoP("productos.txt");
    ofstream archivoL("lotes.txt");
    // precios con dos decimales fijos, para no perder centavos al leer
    archivoP.setf(ios::fixed);
    archivoP.precision(2);
    for (int i = 0; i < inv.getCantidad(); i++) {
        Producto *p = inv.getProducto(i);
        archivoP << p->getCodigoBarras() << ";" << p->getNombre() << ";" << p->getPrecioBase() << ";"
                 << p->getPorcentajeIVA() << ";" << p->getStockMinimo() << endl;
        for (int j = 0; j < p->getCantLotes(); j++) {
            Lote *l = p->getLote(j);
            if (l->getCantidad() == 0) continue; // lote agotado: no se guarda
            archivoL << p->getCodigoBarras() << ";" << l->getFechaVencimiento() << ";" << l->getCantidad() << endl;
        }
    }
    archivoP.close();
    archivoL.close();
}

int cargarProductos(Inventario& inv) {
    ifstream archivoP("productos.txt");
    if (!archivoP) return 0; // primera vez: no existe, no es un error

    string codigo, nombre, fecha;
    double precio, iva;
    int minimo, cantidad;
    int leidos = 0;
    while (getline(archivoP, codigo, ';')) {
        getline(archivoP, nombre, ';');
        archivoP >> precio;
        archivoP.ignore(1);
        archivoP >> iva;
        archivoP.ignore(1);
        archivoP >> minimo;
        archivoP.ignore(1); // salta el Enter
        inv.agregarProducto(new Producto(codigo, nombre, precio, iva, minimo));
        leidos++;
    }
    archivoP.close();

    ifstream archivoL("lotes.txt");
    while (getline(archivoL, codigo, ';')) {
        getline(archivoL, fecha, ';');
        archivoL >> cantidad;
        archivoL.ignore(1);
        Producto *p = inv.buscarProducto(codigo);
        if (p != NULL) p->agregarLote(fecha, cantidad);
    }
    archivoL.close();
    return leidos;
}
