// Autor: Integrante 4
#include "CajaService.h"
using namespace std;

double calcularEfectivoEsperado(double apertura, double ventasEfectivo, double gastos) {
    return apertura + ventasEfectivo - gastos;
}

double calcularDiferencia(double efectivoContado, double efectivoEsperado) {
    return efectivoContado - efectivoEsperado;
}

// TODO (Integrante 4): implementar las 4 funciones siguientes
bool abrirCaja(EstadoCaja&, double) {
    return false;
}

bool registrarGasto(EstadoCaja&, double) {
    return false;
}

bool registrarIngreso(EstadoCaja&, double) {
    return false;
}

void registrarVentaEfectivo(EstadoCaja&, double) {
}
