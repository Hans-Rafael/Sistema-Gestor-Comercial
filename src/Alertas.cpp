// Autor: Integrante 2
#include <iostream>
#include "Alertas.h"
#include "Fechas.h"
using namespace std;

// TODO (Integrante 2): clasificar segun diasHasta (seccion 4 de la guia)
int Alertas::estadoVencimiento(string) {
    return VIGENTE;
}

string Alertas::nombreEstado(int estado) {
    if (estado == VENCIDO) return "VENCIDO";
    if (estado == CRITICO) return "CRITICO";
    if (estado == ADVERTENCIA) return "ADVERTENCIA";
    return "VIGENTE";
}
