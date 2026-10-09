#ifndef LOTE_H
#define LOTE_H

#include <string>
using namespace std;

struct Lote {
    string fechaVencimiento; // "AAAA-MM-DD"
    int cantidad; // unidades que quedan en este lote
};

#endif
