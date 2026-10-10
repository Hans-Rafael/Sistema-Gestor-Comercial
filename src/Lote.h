#ifndef LOTE_H
#define LOTE_H

#include <string>
using namespace std;

struct Lote {
    string fechaVencimiento; // "DD-MM-AAAA"
    int cantidad; // unidades que quedan en este lote
};

#endif
