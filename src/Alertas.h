// Autor: Integrante 2
#ifndef ALERTAS_H
#define ALERTAS_H

#include <iostream>
using namespace std;

const int VENCIDO = 0;
const int CRITICO = 1;
const int ADVERTENCIA = 2;
const int VIGENTE = 3;

class Alertas {
public:
    // VENCIDO: antes de hoy | CRITICO: 0 a 3 dias | ADVERTENCIA: 4 a 7 | VIGENTE: mas de 7
    int estadoVencimiento(string fechaVencimiento);

    // "VENCIDO", "CRITICO", "ADVERTENCIA" o "VIGENTE" (para mostrar en pantalla)
    string nombreEstado(int estado);
};

#endif
