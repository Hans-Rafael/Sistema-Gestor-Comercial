// Autor: Integrante 2
#include <iostream>
#include "Alertas.h"
#include "Fechas.h"
using namespace std;

string Alertas::nombreEstado(int estado)
{
    if (estado == VENCIDO)
        return "VENCIDO";
    if (estado == CRITICO)
        return "CRITICO";
    if (estado == ADVERTENCIA)
        return "ADVERTENCIA";
    return "VIGENTE";
}

int Alertas::estadoVencimiento(string fechaVencimiento)
{
    int dias = diasHasta(fechaVencimiento);
    if (dias < 0)
        return VENCIDO;
    if (dias <= 3)
        return CRITICO;
    if (dias <= 7)
        return ADVERTENCIA;
    return VIGENTE; // VENCIDO, CRITICO... son constantes int en Alertas.h
}

