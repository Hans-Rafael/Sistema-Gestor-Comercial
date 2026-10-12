// Autor: Integrante 4
#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include "Tipos.h"
#include "Usuario.h"
using namespace std;

// Guarda los usuarios (puntero a la clase base: pueden ser Cajero o Encargado).
// NO se copia: siempre se pasa por referencia (Auth& auth).
class Auth {
private:
    Usuario **usuarios;
    int capacidad;
    int cantidad;

public:
    Auth(int cap);
    ~Auth();

    // se queda con el puntero (lo libera en el destructor); false si esta lleno
    bool agregarUsuario(Usuario *u);

    // devuelve el usuario si nombre y clave coinciden, o NULL
    Usuario* validarLogin(string nombre, string clave);
};

#endif
