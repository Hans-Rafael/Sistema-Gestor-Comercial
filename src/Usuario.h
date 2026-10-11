// Autor: Integrante 1
#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

// Clase base. Cajero y Encargado heredan de ella (herencia + virtual)
class Usuario {
protected:
    string nombre; // usuario para el login
    string clave;

public:
    Usuario(string n, string c) {
        nombre = n;
        clave = c;
    }
    virtual ~Usuario() {}

    string getNombre() { return nombre; }
    bool claveCorrecta(string c) { return clave == c; }

    virtual string getRol() { return "Usuario"; }
    virtual bool esEncargado() { return false; }
};

class Cajero : public Usuario {
public:
    Cajero(string n, string c) : Usuario(n, c) {}
    string getRol() { return "Cajero"; }
};

class Encargado : public Usuario {
public:
    Encargado(string n, string c) : Usuario(n, c) {}
    string getRol() { return "Encargado"; }
    bool esEncargado() { return true; }
};

#endif
