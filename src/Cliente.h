// Autor: Integrante 1
#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Tipos.h"
using namespace std;

class Cliente {
private:
    string nombre; // sin ';' adentro
    string cuit; // texto, Ej: "20-12345678-9"
    int condicion; // CONSUMIDOR_FINAL, RESPONSABLE_INSCRIPTO o MONOTRIBUTO

public:
    Cliente() {
        nombre = "Consumidor Final";
        cuit = "";
        condicion = CONSUMIDOR_FINAL;
    }
    Cliente(string n, string c, int cond) {
        nombre = n;
        cuit = c;
        condicion = cond;
    }

    string getNombre() { return nombre; }
    string getCuit() { return cuit; }
    int getCondicion() { return condicion; }
    void setNombre(string n) { nombre = n; }
    void setCuit(string c) { cuit = c; }
    void setCondicion(int cond) { condicion = cond; }
};

#endif
