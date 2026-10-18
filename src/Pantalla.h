// Autor: Integrante 5
#ifndef PANTALLA_H
#define PANTALLA_H

#include <iostream>
#include "Inventario.h"
#include "Caja.h"
using namespace std;

// codigos de color ANSI
const string COLOR_ROJO = "\033[31m";
const string COLOR_AMARILLO = "\033[33m";
const string COLOR_VERDE = "\033[32m";
const string COLOR_RESET = "\033[0m";

void mostrarMarco(string titulo);
string conColor(string texto, string color);

// pantallas de cada modulo (cada responsable las escribe en su PantallaXxx.cpp)
void pantallaVenta(Inventario& inv, Caja& caja);
void pantallaCompra(Inventario& inv);
void pantallaAlertas(Inventario& inv);
void pantallaMovimientosCaja(Caja& caja); // opcion 4
void pantallaCierreCaja(Caja& caja); // opcion 5
void pantallaListar(Inventario& inv); // opcion 6
void pantallaBuscar(Inventario& inv); // opcion 7
void pantallaAltaProducto(Inventario& inv); // opcion 8

#endif
