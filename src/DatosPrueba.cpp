// Autor: Integrante 1
#include "DatosPrueba.h"
#include "InventarioService.h"
#include "Fechas.h"
using namespace std;

// llena el array y devuelve cuantos productos cargo
// NOTA: las lineas de agregarLote estan comentadas hasta que el Integrante 2 termine
// InventarioService.cpp. Cuando llegue, descomentarlas (quitar las //).
int cargarDatosDePrueba(Producto lista[]) {
    int cant = 0;

    Producto leche;
    leche.codigoBarras = "7791234567";
    leche.nombre = "Leche Entera 1L";
    leche.precioBase = 1000.00;
    leche.porcentajeIVA = 21.0;
    leche.stockMinimo = 10;
    // agregarLote(leche, fechaEnDias(-2), 5); // vencido
    // agregarLote(leche, fechaEnDias(2), 4); // critico
    // agregarLote(leche, fechaEnDias(40), 12); // vigente
    lista[cant] = leche;
    cant++;

    Producto pan;
    pan.codigoBarras = "7799876543";
    pan.nombre = "Pan Lactal";
    pan.precioBase = 1500.00;
    pan.porcentajeIVA = 10.5;
    pan.stockMinimo = 5;
    // agregarLote(pan, fechaEnDias(6), 8); // advertencia
    lista[cant] = pan;
    cant++;

    Producto yogur;
    yogur.codigoBarras = "7795551234";
    yogur.nombre = "Yogur Natural 190g";
    yogur.precioBase = 800.00;
    yogur.porcentajeIVA = 21.0;
    yogur.stockMinimo = 8;
    // agregarLote(yogur, fechaEnDias(1), 3); // critico
    // agregarLote(yogur, fechaEnDias(15), 20); // vigente
    lista[cant] = yogur;
    cant++;

    Producto arroz;
    arroz.codigoBarras = "7792223344";
    arroz.nombre = "Arroz Largo Fino 1kg";
    arroz.precioBase = 1200.00;
    arroz.porcentajeIVA = 10.5;
    arroz.stockMinimo = 10;
    // agregarLote(arroz, fechaEnDias(180), 30); // vigente
    lista[cant] = arroz;
    cant++;

    Producto galletitas;
    galletitas.codigoBarras = "7793334455";
    galletitas.nombre = "Galletitas Dulces 300g";
    galletitas.precioBase = 900.00;
    galletitas.porcentajeIVA = 21.0;
    galletitas.stockMinimo = 6;
    // agregarLote(galletitas, fechaEnDias(-10), 7); // vencido
    // agregarLote(galletitas, fechaEnDias(5), 10); // advertencia
    lista[cant] = galletitas;
    cant++;

    return cant;
}
