// Autor: Integrante 1
#include <iostream>
#include "DatosPrueba.h"
#include "Fechas.h"
using namespace std;

void cargarDatosDePrueba(Inventario& inv) {
    Producto *leche = new Producto("1122334451", "Leche Entera 1L", 1000.00, 21.0, 10);
    leche->agregarLote(fechaEnDias(-2), 5); // vencido
    leche->agregarLote(fechaEnDias(2), 4); // critico
    leche->agregarLote(fechaEnDias(40), 12); // vigente
    inv.agregarProducto(leche);

    Producto *pan = new Producto("1122334452", "Pan Lactal", 1500.00, 10.5, 5);
    pan->agregarLote(fechaEnDias(6), 8); // advertencia
    inv.agregarProducto(pan);

    Producto *yogur = new Producto("1122334453", "Yogur Natural 190g", 800.00, 21.0, 8);
    yogur->agregarLote(fechaEnDias(1), 3); // critico
    yogur->agregarLote(fechaEnDias(15), 20); // vigente
    inv.agregarProducto(yogur);

    Producto *arroz = new Producto("1122334454", "Arroz Largo Fino 1kg", 1200.00, 10.5, 10);
    arroz->agregarLote(fechaEnDias(180), 30); // vigente
    inv.agregarProducto(arroz);

    Producto *galletitas = new Producto("1122334455", "Galletitas Dulces 300g", 900.00, 21.0, 6);
    galletitas->agregarLote(fechaEnDias(-10), 7); // vencido
    galletitas->agregarLote(fechaEnDias(5), 10); // advertencia
    inv.agregarProducto(galletitas);
}

void cargarUsuariosDePrueba(Auth& auth) {
    auth.agregarUsuario(new Encargado("juan", "4321"));
    auth.agregarUsuario(new Cajero("cajero1", "1234"));
    auth.agregarUsuario(new Cajero("cajero2", "5678"));
}
