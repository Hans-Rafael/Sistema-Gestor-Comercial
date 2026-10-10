#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <string>
#include "Usuario.h"
using namespace std;

// devuelve el usuario si nombre y clave coinciden, o nullptr
Usuario* validarLogin(Usuario usuarios[], int cantidad, const string& nombre, const string& clave);

#endif
