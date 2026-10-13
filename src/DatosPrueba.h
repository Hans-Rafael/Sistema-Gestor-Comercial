// Autor: Integrante 1
#ifndef DATOSPRUEBA_H
#define DATOSPRUEBA_H

#include "Inventario.h"
#include "Auth.h"
using namespace std;

// carga productos con lotes relativos a hoy (hay que llamar antes a setFechaHoy)
void cargarDatosDePrueba(Inventario& inv);

// carga dos usuarios: "encargado" / "1234" y "cajero" / "1234"
void cargarUsuariosDePrueba(Auth& auth);

#endif
