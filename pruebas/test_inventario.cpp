// Autor: Integrante 2
#include <iostream>
#include "Inventario.h"
#include "Fechas.h"
using namespace std;

int fallas = 0;
void verificar(bool cond, string nombre) {
    if (cond) cout << "OK    " << nombre << endl;
    else { cout << "FALLA " << nombre << endl; fallas++; }
}

int main() {
    setFechaHoy("09-10-2026");
    Inventario inv(5);

    // FEFO con varios lotes: 3 en un lote y 4 en otro, venta de 5
    Producto *p = new Producto("1111111111", "Prueba FEFO", 100, 21, 2);
    p->agregarLote("20-10-2026", 4);   // vence despues
    p->agregarLote("12-10-2026", 3);   // vence antes
    inv.agregarProducto(p);
    verificar(inv.stockTotal(p, fechaHoy()) == 7, "stockTotal suma lotes no vencidos");
    verificar(inv.descontarFEFO(p, 5, fechaHoy()), "descontarFEFO reparte entre lotes");
    verificar(inv.stockTotal(p, fechaHoy()) == 2, "queda stock 2 tras vender 5");
    verificar(p->getLote(0)->getFechaVencimiento() == "12-10-2026" || p->getLote(1)->getFechaVencimiento() == "12-10-2026", "lote que vence antes sigue presente");
    verificar(!inv.descontarFEFO(p, 3, fechaHoy()), "no vende mas que el stock");
    verificar(inv.esStockCritico(p, fechaHoy()), "stock 2 <= minimo 2 es critico");

    // lotes vencidos no cuentan ni se venden
    Producto *q = new Producto("2222222222", "Vencido Test", 50, 10.5, 1);
    q->agregarLote("01-10-2026", 10);  // vencido
    q->agregarLote("15-10-2026", 2);
    inv.agregarProducto(q);
    verificar(inv.stockTotal(q, fechaHoy()) == 2, "stockTotal ignora vencidos");
    verificar(!inv.descontarFEFO(q, 5, fechaHoy()), "no descuenta de vencidos");
    verificar(inv.descontarFEFO(q, 2, fechaHoy()), "descuenta 2 de lotes vigentes");

    // busquedas
    verificar(inv.buscarProducto("1111111111") == p, "buscarProducto por codigo");
    verificar(inv.buscarProducto("0000000000") == NULL, "buscarProducto devuelve NULL si no existe");
    verificar(inv.buscarPorNombre("FEFO", 0) == 0, "buscarPorNombre encuentra parte del nombre");
    verificar(inv.buscarPorNombre("fefo", 0) == 0, "buscarPorNombre ignora mayusculas");

    cout << (fallas == 0 ? "\nTODO OK" : "\nHAY FALLAS") << endl;
    return fallas;
}
