#ifndef CAJASERVICE_H
#define CAJASERVICE_H

using namespace std;

// Esperado = Apertura + Ventas en efectivo - Gastos
double calcularEfectivoEsperado(double apertura, double ventasEfectivo, double gastos);

// Diferencia = Contado - Esperado (0 = caja cuadrada)
double calcularDiferencia(double efectivoContado, double efectivoEsperado);

#endif
