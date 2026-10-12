// Autor: Integrante 1
#ifndef LOTE_H
#define LOTE_H

#include <iostream>
using namespace std;

class Lote {
private:
    string fechaVencimiento; // "DD-MM-AAAA"
    int cantidad; // unidades que quedan en este lote

public:
    Lote() {
        fechaVencimiento = "";
        cantidad = 0;
    }
    Lote(string f, int c) {
        fechaVencimiento = f;
        cantidad = c;
    }

    string getFechaVencimiento() { return fechaVencimiento; }
    int getCantidad() { return cantidad; }
    void setFechaVencimiento(string f) { fechaVencimiento = f; }
    void setCantidad(int c) { cantidad = c; }
};

#endif
