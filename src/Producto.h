// Autor: Integrante 1
#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include "Tipos.h"
#include "Lote.h"
using namespace std;

class Producto {
private:
    string codigoBarras; // 10 digitos simulados. Ej: "7791234567"
    string nombre; // Ej: "Leche Entera 1L" (sin ';' adentro)
    double precioBase; // precio SIN IVA. Ej: 1000.00
    double porcentajeIVA; // Ej: 21.0 o 10.5
    int stockMinimo; // Ej: 10 (critico si stock <= 10)
    Lote lotes[MAX_LOTES]; // partidas compradas
    int cantLotes; // cuantos lotes hay cargados

public:
    Producto() {
        codigoBarras = "";
        nombre = "";
        precioBase = 0;
        porcentajeIVA = 21.0;
        stockMinimo = 0;
        cantLotes = 0;
    }
    Producto(string codigo, string n, double precio, double iva, int minimo) {
        codigoBarras = codigo;
        nombre = n;
        precioBase = precio;
        porcentajeIVA = iva;
        stockMinimo = minimo;
        cantLotes = 0;
    }

    string getCodigoBarras() { return codigoBarras; }
    string getNombre() { return nombre; }
    double getPrecioBase() { return precioBase; }
    double getPorcentajeIVA() { return porcentajeIVA; }
    int getStockMinimo() { return stockMinimo; }
    int getCantLotes() { return cantLotes; }

    void setNombre(string n) { nombre = n; }
    void setPrecioBase(double p) { precioBase = p; }
    void setPorcentajeIVA(double iva) { porcentajeIVA = iva; }
    void setStockMinimo(int m) { stockMinimo = m; }

    // devuelve un puntero al lote i (0 a cantLotes-1): los cambios se guardan en el producto
    Lote* getLote(int i) { return &lotes[i]; }

    // reutiliza un lote agotado (cantidad 0); devuelve false si ya hay MAX_LOTES lotes
    bool agregarLote(string vencimiento, int cantidad) {
        for (int i = 0; i < cantLotes; i++) {
            if (lotes[i].getCantidad() == 0) {
                lotes[i].setFechaVencimiento(vencimiento);
                lotes[i].setCantidad(cantidad);
                return true;
            }
        }
        if (cantLotes >= MAX_LOTES) return false;
        lotes[cantLotes].setFechaVencimiento(vencimiento);
        lotes[cantLotes].setCantidad(cantidad);
        cantLotes++;
        return true;
    }
};

#endif
