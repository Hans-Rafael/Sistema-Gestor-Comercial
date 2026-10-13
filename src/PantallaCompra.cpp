// Autor: Integrante 2
#include <iostream>
#include "Inventario.h"
#include "Fechas.h"
#include "Validaciones.h"
#include "Pantalla.h"
using namespace std;

// TODO (Integrante 2): recibir mercaderia como lote (opcion 2). Como arrancar (escenario 2):
//   string codigo = leerLinea("Codigo de barras: ");
//   Producto *p = inv.buscarProducto(codigo);
//   if (p == NULL) { cout << "Producto inexistente" << endl; return; }   // controlar NULL
//   int cant = leerEntero("Cantidad: ", 1, 100000);
//   string venc = convertirFecha(leerLinea("Vencimiento (DD/MM/AAAA): "));   // "" si es invalida: repetir
//   if (!p->agregarLote(venc, cant)) cout << "No hay lugar para mas lotes" << endl;
void pantallaCompra(Inventario&) {
    cout << "(pendiente: Integrante 2 - compra / lote)" << endl;
}
