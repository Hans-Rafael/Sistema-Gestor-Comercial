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

    // STOCK: 0 a 10 unidades | CRITICO: 11 a 20 | ADVERTENCIA: 21 a 30 | VIGENTE: mas de 30
    int estadoStock(int stock);
    
    // "STOCK", "CRITICO", "ADVERTENCIA" o "VIGENTE" (para mostrar en pantalla)
    string nombreEstadoStock(int estado);
};

#endif
