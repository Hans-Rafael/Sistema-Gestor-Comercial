// Autor: Integrante 4
#include <iostream>
#include "Caja.h"
#include "Validaciones.h"
#include "Pantalla.h"
using namespace std;

// TODO (Integrante 4): registrar gasto o ingreso manual (opcion 4). Como arrancar:
//   int tipo = leerEntero("1. Gasto  2. Ingreso  0. Volver: ", 0, 2);
//   double monto = leerDouble("Monto: ", 0.01);
//   caja.registrarGasto(monto) o caja.registrarIngreso(monto); avisar si devuelve false.
void pantallaMovimientosCaja(Caja&) {
    cout << "(pendiente: Integrante 4 - movimientos de caja)" << endl;
}

// TODO (Integrante 4): arqueo y cierre de caja (opcion 5). Escenario 5:
//   double contado = leerDouble("Efectivo contado: ", 0);
//   mostrar caja.efectivoEsperado() y d = caja.diferencia(contado);
//   si d == 0 (comparar con una diferencia pequena, no con ==) -> "Caja cuadrada".
void pantallaCierreCaja(Caja&) {
    cout << "(pendiente: Integrante 4 - cierre de caja)" << endl;
}
