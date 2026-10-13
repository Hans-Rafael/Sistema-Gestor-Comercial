// Autor: Integrante 2
#include <iostream>
#include "Alertas.h"
#include "Fechas.h"
using namespace std;

// TODO (Integrante 2): clasificar segun diasHasta (seccion 4 de la guia). Como arrancar:
//   int dias = diasHasta(fechaVencimiento);
//   if (dias < 0)  return VENCIDO;
//   if (dias <= 3) return CRITICO;
//   if (dias <= 7) return ADVERTENCIA;
//   return VIGENTE;
// Nota: Alertas.h declara estadoStock / nombreEstadoStock que la guia NO pide
//   (el stock critico es stockTotal <= stockMinimo, via Inventario::esStockCritico).
//   Decidir con el equipo si se quitan o se implementan.
int Alertas::estadoVencimiento(string) {
    return VIGENTE;
}

string Alertas::nombreEstado(int estado) {
    if (estado == VENCIDO) return "VENCIDO";
    if (estado == CRITICO) return "CRITICO";
    if (estado == ADVERTENCIA) return "ADVERTENCIA";
    return "VIGENTE";
}
