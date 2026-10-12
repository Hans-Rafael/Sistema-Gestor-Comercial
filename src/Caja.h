// Autor: Integrante 4
#ifndef CAJA_H
#define CAJA_H

#include <iostream>
using namespace std;

// Caja del dia. No usa cin/cout: lo muestra PantallaCaja
class Caja {
private:
    bool abierta;
    double apertura;
    double ventasEfectivo;
    double gastos;
    double ingresos;

public:
    Caja() {
        abierta = false;
        apertura = 0;
        ventasEfectivo = 0;
        gastos = 0;
        ingresos = 0;
    }

    bool estaAbierta() { return abierta; }
    double getApertura() { return apertura; }
    double getVentasEfectivo() { return ventasEfectivo; }
    double getGastos() { return gastos; }
    double getIngresos() { return ingresos; }

    // abre la caja con el monto inicial; false si ya estaba abierta
    bool abrir(double montoInicial);

    // gasto / ingreso manual (monto > 0); false si la caja esta cerrada o el monto es invalido
    bool registrarGasto(double monto);
    bool registrarIngreso(double monto);

    // suma una venta cobrada en efectivo
    void registrarVentaEfectivo(double monto);

    // Esperado = Apertura + Ventas en efectivo + Ingresos - Gastos
    double efectivoEsperado();

    // Diferencia = Contado - Esperado (0 = caja cuadrada)
    double diferencia(double efectivoContado);
};

#endif
