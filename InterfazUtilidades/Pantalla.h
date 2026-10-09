#ifndef PANTALLA_H
#define PANTALLA_H

#include <string>
#include "Producto.h"
using namespace std;

// codigos de color ANSI
const string COLOR_ROJO = "\033[31m";
const string COLOR_AMARILLO = "\033[33m";
const string COLOR_VERDE = "\033[32m";
const string COLOR_RESET = "\033[0m";

void mostrarMarco(const string& titulo);
string conColor(const string& texto, const string& color);

// pantallas de cada modulo (cada responsable las escribe en su PantallaXxx.cpp)
void pantallaVenta(Producto lista[], int cantidad);
void pantallaCompra(Producto lista[], int cantidad);
void pantallaAlertas(Producto lista[], int cantidad);

#endif
