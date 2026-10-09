#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

struct Usuario {
    string nombre; // usuario para el login
    string clave;
    bool esEncargado = false; // false = cajero (roles: opcional)
};

#endif
