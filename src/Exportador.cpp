// Autor: Integrante 1
#include <iostream>
#include <fstream>
#include "Exportador.h"
#include "Alertas.h"
#include "Fechas.h"
using namespace std;

bool exportarAlertasCSV(Inventario& inv, string archivo) {
    ofstream salida(archivo.c_str());
    if (!salida) return false;

    Alertas alertas;
    salida << "producto;codigo;vence;cantidad;estado" << endl;
    for (int i = 0; i < inv.getCantidad(); i++) {
        Producto *p = inv.getProducto(i);
        for (int j = 0; j < p->getCantLotes(); j++) {
            Lote *l = p->getLote(j);
            if (l->getCantidad() == 0) continue;
            int estado = alertas.estadoVencimiento(l->getFechaVencimiento());
            if (estado == VIGENTE) continue;
            salida << p->getNombre() << ";" << p->getCodigoBarras() << ";" << l->getFechaVencimiento() << ";"
                   << l->getCantidad() << ";" << alertas.nombreEstado(estado) << endl;
        }
    }
    salida.close();
    return true;
}
