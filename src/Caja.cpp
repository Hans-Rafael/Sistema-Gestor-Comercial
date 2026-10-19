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

bool Caja::abrir(double montoInicial) {
    if (abierta || montoInicial < 0) return false;
    abierta = true;
    apertura = montoInicial;
    ventasEfectivo = 0;
    ingresos = 0;
    gastos = 0;
    return true;
}

bool Caja::registrarGasto(double monto) {
    if (!abierta || monto <= 0) return false;
    gastos += monto;
    return true;
}

bool Caja::registrarIngreso(double monto) {
    if (!abierta || monto <= 0) return false;
    ingresos += monto;
    return true;
}

void Caja::registrarVentaEfectivo(double monto) {
    if (abierta && monto > 0) {
        ventasEfectivo += monto;
    }
}