// Autor: Integrante 1
// Prueba de Fechas, Producto/Lote, Usuario y DatosPrueba.
// Compilar: g++ -Wall -Wextra -Isrc pruebas/test_integrante1.cpp src/Fechas.cpp src/Inventario.cpp src/Auth.cpp src/DatosPrueba.cpp -o prueba
#include <iostream>
#include "Fechas.h"
#include "Producto.h"
#include "Usuario.h"
#include "Inventario.h"
#include "Auth.h"
#include "DatosPrueba.h"
using namespace std;

int errores = 0;

void verificar(string nombre, bool ok) {
    if (ok) cout << "OK    " << nombre << endl;
    else {
        cout << "ERROR " << nombre << endl;
        errores++;
    }
}

int main() {
    setFechaHoy("09-10-2026");
    verificar("fechaHoy", fechaHoy() == "09-10-2026");
    verificar("fechaEnDias(2)", fechaEnDias(2) == "11-10-2026");
    verificar("fechaEnDias(-10)", fechaEnDias(-10) == "29-09-2026");
    verificar("fechaEnDias(23) cruza de mes", fechaEnDias(23) == "01-11-2026");
    verificar("diasHasta futuro", diasHasta("20-11-2026") == 42);
    verificar("diasHasta pasado", diasHasta("07-10-2026") == -2);
    verificar("convertirFecha con /", convertirFecha("20/11/2026") == "20-11-2026");
    verificar("convertirFecha invalida", convertirFecha("2011/2026") == "");
    verificar("convertirFecha mes 13", convertirFecha("10-13-2026") == "");
    verificar("compararFechas no usa texto", compararFechas("05-12-2026", "20-11-2026") > 0);
    verificar("compararFechas iguales", compararFechas("01-01-2026", "01-01-2026") == 0);

    Producto p("7791234567", "Leche", 1000, 21.0, 10);
    verificar("agregarLote", p.agregarLote("20-11-2026", 24) && p.getCantLotes() == 1);
    p.getLote(0)->setCantidad(5);
    verificar("getLote modifica el original", p.getLote(0)->getCantidad() == 5);
    for (int i = 1; i < MAX_LOTES; i++) p.agregarLote("20-11-2026", 1);
    verificar("agregarLote lleno devuelve false", !p.agregarLote("20-11-2026", 1));

    Usuario *u = new Encargado("ana", "1");
    verificar("polimorfismo getRol", u->getRol() == "Encargado" && u->esEncargado());
    delete u;

    Inventario inv(CAPACIDAD_PRODUCTOS);
    cargarDatosDePrueba(inv);
    verificar("5 productos de prueba", inv.getCantidad() == 5);
    Producto *leche = inv.buscarProducto("7791234567");
    verificar("buscarProducto", leche != NULL && leche->getNombre() == "Leche Entera 1L");
    verificar("buscarProducto inexistente", inv.buscarProducto("0000000000") == NULL);
    verificar("leche tiene 3 lotes (vencido, critico, vigente)", leche->getCantLotes() == 3
              && diasHasta(leche->getLote(0)->getFechaVencimiento()) == -2);

    Auth auth(CAPACIDAD_USUARIOS);
    cargarUsuariosDePrueba(auth);

    cout << (errores == 0 ? "TODO OK" : "HAY ERRORES") << endl;
    return errores;
}
