// Autor: Integrante 4
#include <iostream>
#include "Caja.h"
#include "Validaciones.h"
#include "Pantalla.h"

using namespace std;

void pantallaAperturaCaja(Caja &caja) {
    limpiarPantalla();
    cout << "=== APERTURA DE CAJA ===" << endl;
    double monto = leerDouble("Ingrese el monto inicial de apertura: $", 0, 1000000);
    if (caja.abrir(monto)) {
        cout << "Caja abierta con exito con un monto de $" << monto << endl;
    } else {
        cout << "No se pudo abrir la caja (ya se encontraba abierta o el monto es invalido)." << endl;
    }
    cout << "Presione Enter para continuar...";
    leerLinea("");
}

void pantallaMovimientosCaja(Caja &caja) {
    limpiarPantalla();
    cout << "=== MOVIMIENTOS DE CAJA (Ingresos / Gastos) ===" << endl;
    cout << "1. Registrar Ingreso manual" << endl;
    cout << "2. Registrar Gasto manual" << endl;
    cout << "0. Volver" << endl;
    
    int op = leerEntero("Seleccione una opcion: ", 0, 2);
    if (op == 1) {
        double monto = leerDouble("Ingrese el monto del ingreso: $", 0.01, 1000000);
        if (caja.registrarIngreso(monto)) {
            cout << "Ingreso registrado correctamente." << endl;
        } else {
            cout << "Error: La caja esta cerrada o el monto es invalido." << endl;
        }
    } else if (op == 2) {
        double monto = leerDouble("Ingrese el monto del gasto: $", 0.01, 1000000);
        if (caja.registrarGasto(monto)) {
            cout << "Gasto registrado correctamente." << endl;
        } else {
            cout << "Error: La caja esta cerrada o el monto es invalido." << endl;
        }
    }
    cout << "Presione Enter para continuar...";
    leerLinea("");
}

void pantallaCierreCaja(Caja &caja) {
    limpiarPantalla();
    cout << "=== CIERRE DE CAJA (Arqueo) ===" << endl;
    cout << "Efectivo esperado en caja: $" << caja.efectivoEsperado() << endl;
    double contado = leerDouble("Ingrese el efectivo contado fisicamente: $", 0, 10000000);
    
    double dif = caja.diferencia(contado);
    cout << "-----------------------------------" << endl;
    cout << "Esperado: $" << caja.efectivoEsperado() << endl;
    cout << "Contado:  $" << contado << endl;
    if (dif == 0) {
        cout << "Diferencia: $0,00 (Caja cuadrada)" << endl;
    } else if (dif > 0) {
        cout << "Diferencia: +$" << dif << " (Sobra dinero)" << endl;
    } else {
        cout << "Diferencia: $" << dif << " (Falta dinero)" << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "Presione Enter para continuar...";
    leerLinea("");
