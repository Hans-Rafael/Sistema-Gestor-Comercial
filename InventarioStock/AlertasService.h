#ifndef ALERTASSERVICE_H
#define ALERTASSERVICE_H

#include <string>
using namespace std;

enum EstadoVencimiento { VENCIDO, CRITICO, ADVERTENCIA, VIGENTE };

// VENCIDO: antes de hoy | CRITICO: 0 a 3 dias | ADVERTENCIA: 4 a 7 | VIGENTE: mas de 7
EstadoVencimiento estadoVencimiento(const string& fechaVencimiento);

#endif
