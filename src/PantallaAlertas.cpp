// Autor: Integrante 2
#include <iostream>
#include "Alertas.h"
#include "Inventario.h"
#include "Fechas.h"
#include "Validaciones.h"
#include "Pantalla.h"
using namespace std;

// TODO (Integrante 2): consola de alertas (opcion 3). Como arrancar:
//   Alertas alertas;
//   Seccion 1 - recorrer inv.getProducto(i) y sus lotes (getLote(j)); saltear lotes con cantidad 0;
//     estado = alertas.estadoVencimiento(fecha); si no es VIGENTE mostrar producto, lote, fecha
//     y alertas.nombreEstado(estado), con conColor(...) (rojo/amarillo, ver Pantalla.h).
//   Seccion 2 - productos con inv.esStockCritico(p, fechaHoy()) -> mostrar nombre y inv.stockTotal.
//   Al final pausar(). Opcional: exportar a CSV con ofstream.
//   Sin cin/cout en Alertas ni Inventario: solo aca.
void pantallaAlertas(Inventario&) {
    cout << "(pendiente: Integrante 2 - alertas)" << endl;
}
