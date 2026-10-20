// Autor: Integrante 1
#ifndef ARCHIVOHELPER_H
#define ARCHIVOHELPER_H

#include <iostream>
#include "Inventario.h"
using namespace std;

// Persistencia opcional productos.txt y lotes.txt, separados por ';'
void guardarProductos(Inventario& inv);

// devuelve cuantos productos leyo (0 si no hay archivo o esta vacio)
int cargarProductos(Inventario& inv);

#endif
