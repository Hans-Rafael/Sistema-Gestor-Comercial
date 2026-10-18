// Autor: Integrante 4
#include <iostream>
#include <cstdlib>
#include "Auth.h"
using namespace std;

Auth::Auth(int cap) {
    capacidad = cap;
    cantidad = 0;
    usuarios = new Usuario*[capacidad];
}

Auth::~Auth() {
    for (int i = 0; i < cantidad; i++) {
        delete usuarios[i];
    }
    delete[] usuarios;
}

bool Auth::agregarUsuario(Usuario *u) {
    if (cantidad >= capacidad) return false;
    usuarios[cantidad] = u;
    cantidad++;
    return true;
}

Usuario* Auth::validarLogin(string nombre, string clave) {
    for (int i = 0; i < cantidad; i++) {
        if (usuarios[i]->getNombre() == nombre && usuarios[i]->claveCorrecta(clave)) {
            return usuarios[i];
        }
    }
    return NULL;
}
