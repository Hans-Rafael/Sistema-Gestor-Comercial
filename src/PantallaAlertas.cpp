// Autor: Integrante 2
#include <iostream>
#include "Alertas.h"
#include "Inventario.h"
#include "Fechas.h"
#include "Validaciones.h"
#include "Pantalla.h"
#include "Exportador.h"
using namespace std;

void pantallaAlertas(Inventario& inv) {   // opcion 3: consola de alertas
    Alertas alertas;
    limpiarPantalla();
    mostrarMarco("ALERTAS");

    // Seccion 1: lotes vencidos, criticos y por vencer (los VIGENTES no se muestran)
    cout << "--- Lotes vencidos / criticos / por vencer ---" << endl;
    int avisos = 0;
    for (int i = 0; i < inv.getCantidad(); i++) {
        Producto *p = inv.getProducto(i);
        for (int j = 0; j < p->getCantLotes(); j++) {
            Lote *l = p->getLote(j);
            if (l->getCantidad() == 0) continue;   // lote agotado
            int estado = alertas.estadoVencimiento(l->getFechaVencimiento());
            if (estado == VIGENTE) continue;

            string texto = p->getNombre() + " | vence " + l->getFechaVencimiento()
                         + " | cant: " + to_string(l->getCantidad())
                         + " | " + alertas.nombreEstado(estado);
            if (estado == VENCIDO || estado == CRITICO) cout << conColor(texto, COLOR_ROJO) << endl;
            else cout << conColor(texto, COLOR_AMARILLO) << endl;
            avisos++;
        }
    }
    if (avisos == 0) cout << "No hay lotes vencidos ni por vencer" << endl;

    // Seccion 2: productos con stock critico (stock valido <= stock minimo)
    cout << "\n--- Productos con stock critico ---" << endl;
    int criticos = 0;
    for (int i = 0; i < inv.getCantidad(); i++) {
        Producto *p = inv.getProducto(i);
        if (inv.esStockCritico(p, fechaHoy())) {
            string texto = p->getNombre() + " | stock: " + to_string(inv.stockTotal(p, fechaHoy()))
                         + " (minimo " + to_string(p->getStockMinimo()) + ")";
            cout << conColor(texto, COLOR_ROJO) << endl;
            criticos++;
        }
    }
    if (criticos == 0) cout << "No hay productos con stock critico" << endl;

    // if (leerEntero("\nExportar la lista de lotes a alertas.csv? (1 = Si, 0 = No): ", 0, 1) == 1) {
    //     if (exportarAlertasCSV(inv, "alertas.csv")) cout << "Archivo alertas.csv generado." << endl;
    //     else cout << "No se pudo crear alertas.csv" << endl;
    // }

    pausar();
}
