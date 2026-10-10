#ifndef CAJASERVICE_H
#define CAJASERVICE_H

using namespace std;

// Estado de la caja del dia (sin cin/cout, lo muestra PantallaCaja)
struct EstadoCaja {
    bool abierta = false;
    double apertura = 0;
    double ventasEfectivo = 0;
    double gastos = 0;
    double ingresos = 0;
};

// abre la caja con el monto inicial; false si ya estaba abierta
bool abrirCaja(EstadoCaja& caja, double montoInicial);

// registra un gasto manual (monto > 0); false si la caja esta cerrada o el monto es invalido
bool registrarGasto(EstadoCaja& caja, double monto);

// registra un ingreso manual (monto > 0); false si la caja esta cerrada o el monto es invalido
bool registrarIngreso(EstadoCaja& caja, double monto);

// suma una venta cobrada en efectivo
void registrarVentaEfectivo(EstadoCaja& caja, double monto);

// Esperado = Apertura + Ventas en efectivo - Gastos
double calcularEfectivoEsperado(double apertura, double ventasEfectivo, double gastos);

// Diferencia = Contado - Esperado (0 = caja cuadrada)
double calcularDiferencia(double efectivoContado, double efectivoEsperado);

#endif
