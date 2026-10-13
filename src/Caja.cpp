// Autor: Integrante 4
#include <iostream>
#include "Caja.h"
using namespace std;

double Caja::efectivoEsperado() {
    return apertura + ventasEfectivo + ingresos - gastos;
}

double Caja::diferencia(double efectivoContado) {
    return efectivoContado - efectivoEsperado();
}

// TODO (Integrante 4): implementar las 4 funciones siguientes. Como arrancar:
//   abrir: if (abierta) return false; abierta = true; apertura = montoInicial; return true;
//   registrarGasto / registrarIngreso: if (!abierta || monto <= 0) return false;
//       gastos += monto (o ingresos += monto); return true;
//   registrarVentaEfectivo: ventasEfectivo += monto;
//   (poner nombre al parametro en vez de dejarlo sin nombre: double montoInicial, double monto)
bool Caja::abrir(double) {
    return false;
}

bool Caja::registrarGasto(double) {
    return false;
}

bool Caja::registrarIngreso(double) {
    return false;
}

void Caja::registrarVentaEfectivo(double) {
}
