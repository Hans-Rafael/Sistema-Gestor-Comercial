// Autor: Integrante 4
#include <iostream>
#include "Caja.h"
#include "Validaciones.h"
#include "Pantalla.h"
using namespace std;

// monto con dos decimales: 1210.5 -> "$1210.50" (to_string daria "1210.500000")
static string formatearPesos(double monto) {
    string signo = "";
    if (monto < 0) {
        signo = "-";
        monto = -monto;
    }
    long centavos = (long)(monto * 100 + 0.5);
    string dec = to_string(centavos % 100);
    if (dec.length() < 2) dec = "0" + dec;
    return signo + "$" + to_string(centavos / 100) + "." + dec;
}

void pantallaAperturaCaja(Caja &caja) {
    limpiarPantalla();
    cout << "=== APERTURA DE CAJA ===" << endl;
    double monto = leerDouble("Ingrese el monto inicial de apertura: $", 0);
    if (caja.abrir(monto)) {
        cout << "Caja abierta con exito con un monto de " << formatearPesos(monto) << endl;
    } else {
        cout << "No se pudo abrir la caja (ya se encontraba abierta o el monto es invalido)." << endl;
    }
    pausar();
}

void pantallaMovimientosCaja(Caja &caja) {
    limpiarPantalla();
    cout << "=== MOVIMIENTOS DE CAJA (Ingresos / Gastos) ===" << endl;
    cout << "1. Registrar ingreso manual" << endl;
    cout << "2. Registrar gasto manual" << endl;
    cout << "0. Volver" << endl;

    int op = leerEntero("Seleccione una opcion: ", 0, 2);
    if (op == 1) {
        double monto = leerDouble("Ingrese el monto del ingreso: $", 0.01);
        if (caja.registrarIngreso(monto)) {
            cout << "Ingreso registrado correctamente." << endl;
        } else {
            cout << "Error: la caja esta cerrada o el monto es invalido." << endl;
        }
    } else if (op == 2) {
        double monto = leerDouble("Ingrese el monto del gasto: $", 0.01);
        if (caja.registrarGasto(monto)) {
            cout << "Gasto registrado correctamente." << endl;
        } else {
            cout << "Error: la caja esta cerrada o el monto es invalido." << endl;
        }
    }
    if (op != 0) pausar();
}

void pantallaCierreCaja(Caja &caja) {
    limpiarPantalla();
    cout << "=== CIERRE DE CAJA (Arqueo) ===" << endl;
    cout << "Efectivo esperado en caja: " << formatearPesos(caja.efectivoEsperado()) << endl;
    double contado = leerDouble("Ingrese el efectivo contado fisicamente: $", 0);

    double dif = caja.diferencia(contado);
    cout << "-----------------------------------" << endl;
    cout << "Esperado: " << formatearPesos(caja.efectivoEsperado()) << endl;
    cout << "Contado:  " << formatearPesos(contado) << endl;
    // los doubles no se comparan con ==: se toma como cuadrada una diferencia menor a medio centavo
    if (dif > -0.005 && dif < 0.005) {
        cout << "Diferencia: $0,00 (Caja cuadrada)" << endl;
    } else if (dif > 0) {
        cout << "Diferencia: +" << formatearPesos(dif) << " (Sobra dinero)" << endl;
    } else {
        cout << "Diferencia: " << formatearPesos(dif) << " (Falta dinero)" << endl;
    }
    cout << "-----------------------------------" << endl;
    pausar();
}
