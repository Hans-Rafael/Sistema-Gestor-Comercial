// Autor: Integrante 2
#include <iostream>
#include <cctype>
#include <cstdlib>
#include "Inventario.h"
#include "Fechas.h"
using namespace std;

Inventario::Inventario(int cap)
{
    capacidad = cap;
    cantidad = 0;
    productos = new Producto *[capacidad];
}

Inventario::~Inventario()
{
    for (int i = 0; i < cantidad; i++)
    {
        delete productos[i];
    }
    delete[] productos;
}

Producto *Inventario::buscarProducto(string codigo)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i]->getCodigoBarras() == codigo)
            return productos[i];
    }
    return NULL;
}
bool Inventario::agregarProducto(Producto *p)
{
    if (cantidad >= capacidad)
        return false;
    productos[cantidad] = p;
    cantidad++;
    return true;
}

// suma solo los lotes NO vencidos
int Inventario::stockTotal(Producto *p, string hoy)
{
    int total = 0;
    for (int i = 0; i < p->getCantLotes(); i++)
    {
        Lote *l = p->getLote(i);
        if (compararFechas(l->getFechaVencimiento(), hoy) >= 0)
            total += l->getCantidad();
    }
    return total;
}

// FEFO: primero el que vence antes; saltea vencidos y reparte entre varios lotes
bool Inventario::descontarFEFO(Producto *p, int cantidad, string hoy)
{
    if (cantidad <= 0 || stockTotal(p, hoy) < cantidad)
        return false;
    int n = p->getCantLotes();
    // 1) ordenar lotes (burbuja): el que vence primero va primero
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            Lote *a = p->getLote(j);
            Lote *b = p->getLote(j + 1);
            if (compararFechas(a->getFechaVencimiento(), b->getFechaVencimiento()) > 0)
            {
                Lote aux = *a;
                *a = *b;
                *b = aux;
            }
        }
    }
    // 2) descontar lote por lote hasta completar la cantidad
    for (int i = 0; i < n && cantidad > 0; i++)
    {
        Lote *l = p->getLote(i);
        if (compararFechas(l->getFechaVencimiento(), hoy) < 0)
            continue; // saltear vencidos
        int sacar = l->getCantidad();
        if (cantidad < sacar)
            sacar = cantidad; // el menor entre lo que hay y lo que falta
        l->setCantidad(l->getCantidad() - sacar);
        cantidad -= sacar;
    }
    return true;
}

bool Inventario::esStockCritico(Producto *p, string hoy)
{
    return stockTotal(p, hoy) <= p->getStockMinimo();
}

// auxiliar: devuelve true si nombre contiene texto (sin usar find ni regex)
// la busqueda ignora mayusculas y minusculas: "ar" encuentra "Arroz"
bool contieneTexto(string nombre, string texto) {
    int n = nombre.length();
    int t = texto.length();
    for (int i = 0; i + t <= n; i++) {
        bool igual = true;
        for (int j = 0; j < t && igual; j++) {
            if (tolower(nombre[i + j]) != tolower(texto[j])) igual = false;
        }
        if (igual) return true;
    }
    return false;
}

int Inventario::buscarPorNombre(string texto, int desde) {
    for (int i = desde; i < cantidad; i++) {
        if (contieneTexto(productos[i]->getNombre(), texto)) return i;
    }
    return -1;
}
