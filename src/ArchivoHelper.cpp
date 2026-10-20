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
    // >> ws salta las lineas en blanco (por ejemplo, una al final del archivo)
    while (archivoP >> ws && getline(archivoP, codigo, ';')) {
        getline(archivoP, nombre, ';');
        archivoP >> precio;
        archivoP.ignore(1);
        archivoP >> iva;
        archivoP.ignore(1);
        archivoP >> minimo;
        archivoP.ignore(1); // salta el Enter
        Producto *p = new Producto(codigo, nombre, precio, iva, minimo);
        if (inv.agregarProducto(p)) {
            leidos++;
        } else {
            // el inventario esta lleno: avisa y libera, para no perder el producto sin aviso
            cout << "[ADVERTENCIA] Inventario lleno: no se cargo el producto " << codigo << endl;
            delete p;
        }
    }
    archivoP.close();

    ifstream archivoL("lotes.txt");
    while (archivoL >> ws && getline(archivoL, codigo, ';')) {
        getline(archivoL, fecha, ';');
        archivoL >> cantidad;
        archivoL.ignore(1);
        Producto *p = inv.buscarProducto(codigo);
        if (p != NULL) {
            p->agregarLote(fecha, cantidad);
        } else {
            cout << "[ADVERTENCIA] Lote de un producto inexistente (" << codigo << "), se ignora" << endl;
        }
    }
    archivoL.close();
    return leidos;
}

bool guardarArrayProductos(Inventario& inv, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo) return false;
    //.setf es para formatear la salida, en este caso para que los precios tengan dos decimales fijos
    archivo.setf(ios::fixed);
    archivo.precision(2);// precios con dos decimales fijos, para no perder centavos al leer
    archivo << "             LISTADO DE PRODUCTOS EN INVENTARIO          " << endl;
    archivo << "=========================================================" << endl;
    for (int i = 0; i < inv.getCantidad(); i++) {
        Producto *p = inv.getProducto(i);
        archivo << "Codigo: " << p->getCodigoBarras()
                << " -- Producto: " << p->getNombre()
                << " -- Precio base: $" << p->getPrecioBase()
                << " -- IVA: " << p->getPorcentajeIVA() << "%"
                << " -- Stock total: " << inv.stockTotal(p, fechaHoy());
        if (inv.esStockCritico(p, fechaHoy())) archivo << " [ADVERTENCIA: Stock Critico]";
        archivo << endl;
    }
    archivo << "=========================================================" << endl;
    archivo << "Total de productos listados: " << inv.getCantidad() << endl;
    archivo.close();
    return true;
}
