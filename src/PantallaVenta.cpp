// Autor: Integrante 3
#include <iostream>
#include <fstream>
#include <string>
#include "Pantalla.h"
#include "Validaciones.h"
#include "Venta.h"
#include "Factura.h"
#include "ArcaMock.h"
#include "Caja.h"
#include "Fechas.h"
#include "Inventario.h"

using namespace std;

static int proximoNumeroFactura = 1;

void guardarFacturaEnTxt(Factura* f, int numeroFactura) {
    string nombreArchivo = "factura_" + to_string(numeroFactura) + ".txt";
    ofstream archivo(nombreArchivo.c_str());

    if (archivo.is_open()) {
        archivo << f->armarTexto();
        archivo.close();
        cout << "[OK] Factura guardada correctamente en " << nombreArchivo << endl;
    } else {
        cout << "[ERROR] No se pudo crear el archivo de la factura." << endl;
    }
}
void pantallaVenta(Inventario& inventario, Caja& caja) {
    limpiarPantalla();
    cout << "========================================" << endl;
    cout << "               NUEVA VENTA              " << endl;
    cout << "========================================" << endl;

    // Menú vertical para la condición fiscal
    cout << "Condicion del cliente:" << endl;
    cout << "  0 = Consumidor Final" << endl;
    cout << "  1 = Responsable Inscripto" << endl;
    cout << "  2 = Monotributo" << endl;
    int condicion = leerEntero("Ingrese una opcion: ", 0, 2);
    
    Venta venta(condicion);

    bool agregando = true;
    while (agregando) {
        string codigo = leerLinea("Ingrese codigo de barras (10 digitos) [0 para terminar]: ");
        if (codigo == "0") break;

        Producto *p = inventario.buscarProducto(codigo);
        if (p == NULL) {
            cout << "[ERROR] Producto no encontrado." << endl;
            continue;
        }

        int stockDisponible = inventario.stockTotal(p, fechaHoy());
        cout << "Producto: " << p->getNombre() << " | Stock disponible: " << stockDisponible << endl;

        if (stockDisponible <= 0) {
            cout << "[ERROR] Producto sin stock disponible." << endl;
            continue;
        }

        int cantidad = leerEntero("Cantidad a llevar: ", 1, stockDisponible);

        // controlar el carrito antes de tocar el stock: si no hay lugar, no queda stock descontado sin item
        if (venta.getCantidadTotalItems() >= MAX_ITEMS_VENTA) {
            cout << "[ERROR] El carrito esta lleno." << endl;
            agregando = false;
            continue;
        }

        // FEFO primero: si no se puede descontar, el item no entra al carrito
        if (!inventario.descontarFEFO(p, cantidad, fechaHoy())) {
            cout << "[ERROR] No se pudo descontar el stock (lotes vencidos o insuficientes)." << endl;
            continue;
        }
        venta.agregarItem(p, cantidad); // no falla: la capacidad se controlo arriba

        if (inventario.esStockCritico(p, fechaHoy())) {
            cout << "[ADVERTENCIA: Stock Critico]" << endl;
        }

        int seguir = leerEntero("Agregar otro producto? (1 = Si, 0 = No): ", 0, 1);
        if (seguir == 0) agregando = false;
    }

    if (venta.getCantidadTotalItems() == 0) {
        cout << "Venta cancelada (carrito vacio)." << endl;
        return;
    }

    double totalVenta = venta.calcularTotal();

    long centavos = (long)(totalVenta * 100 + 0.5);
    string dec = to_string(centavos % 100);
    if (dec.length() < 2) dec = "0" + dec;
    cout << "\nTotal a pagar: $" << to_string(centavos / 100) << "." << dec << endl;

    // Menú vertical para el medio de pago
    cout << "\nMedio de pago:" << endl;
    cout << "  0 = Efectivo" << endl;
    cout << "  1 = Tarjeta" << endl;
    cout << "  2 = Transferencia" << endl;
    int medioPago = leerEntero("Ingrese una opcion: ", 0, 2);

    double vuelto = 0.0;
    if (medioPago == 0) { // Efectivo
        double abonado = leerDouble("Monto entregado por el cliente: $", 0.01);

        // Validar pago no menor al total
        while (abonado < totalVenta) {
            cout << "[ERROR] El monto entregado es menor al total ($" << to_string(centavos / 100) << "." << dec << ")." << endl;
            abonado = leerDouble("Ingrese un monto valido: $", 0.01);
        }

        vuelto = abonado - totalVenta;
        caja.registrarVentaEfectivo(totalVenta);
    }

    // Numero de factura incremental
    int numFacturaActual = proximoNumeroFactura++;
    string cae = ArcaMock::generarCAE();
    char tipoComp = venta.tipoComprobante();
    
Factura *factura = NULL;
    if (tipoComp == 'A') {
        factura = new FacturaA(&venta, numFacturaActual, totalVenta, cae);
    } else {
        factura = new FacturaB(&venta, numFacturaActual, totalVenta, cae);
    }

    limpiarPantalla();
    cout << factura->armarTexto() << endl;

    if (medioPago == 0) {
        long cVuelto = (long)(vuelto * 100 + 0.5);
        string decVuelto = to_string(cVuelto % 100);
        if (decVuelto.length() < 2) decVuelto = "0" + decVuelto;
        cout << "Vuelto al cliente: $" << to_string(cVuelto / 100) << "." << decVuelto << endl;
    }
// Opción para guardar la factura en archivo txt solicitada por el equipo
    int opcionTxt = leerEntero("\nDesea imprimir/guardar la factura en archivo .txt? (1 = Si, 2 = No): ", 1, 2);
    if (opcionTxt == 1) {
        guardarFacturaEnTxt(factura, numFacturaActual);
    }
    delete factura;
    cout << "\nVenta realizada con exito!" << endl;
}