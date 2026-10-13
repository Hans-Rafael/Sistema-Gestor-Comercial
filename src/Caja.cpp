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

// TODO (Integrante 4): implementar las 4 funciones siguientes
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
