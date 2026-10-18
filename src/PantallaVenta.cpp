// Autor: Integrante 3
#include <iostream>
#include "Inventario.h"
#include "Venta.h"
#include "ArcaMock.h"
#include "Factura.h"
#include "Fechas.h"
#include "Validaciones.h"
#include "Tipos.h"
#include "Caja.h"

using namespace std;

void pantallaVenta(Inventario &inventario, Caja &caja) {
    limpiarPantalla();
    cout << "=== MODULO DE VENTAS ===" << endl;

    int condicion = leerEntero("Condicion cliente (0: Consumidor Final, 1: Resp Inscripto, 2: Monotributo): ", 0, 2);
    Venta venta(condicion, EFECTIVO);

    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        string codigo = leerLinea("Ingrese codigo de barras del producto (10 digitos): ");
        Producto *p = inventario.buscarProducto(codigo);

        if (p == NULL) {
            cout << "Producto no encontrado." << endl;
        } else {
            cout << "Producto: " << p->getNombre() << endl;
            int cantidad = leerEntero("Ingrese cantidad a vender: ", 1, 1000);

            if (inventario.descontarFEFO(p, cantidad, fechaHoy())) {
                venta.agregarItem(p, cantidad);
                cout << "Item agregado al carrito y stock descontado con FEFO." << endl;

                if (inventario.esStockCritico(p, fechaHoy())) {
                    cout << "[ADVERTENCIA: Stock Critico]" << endl;
                }
            } else {
                cout << "Stock insuficiente o lotes vencidos." << endl;
            }
        }

        cout << "Desea agregar otro producto? (s/n): ";
        cin >> continuar;
        cin.ignore(10000, '\n');
    }

    if (venta.getCantItems() > 0) {
        int medioPago = leerEntero("Medio de pago (0: Efectivo, 1: Tarjeta, 2: Transferencia): ", 0, 2);
        venta.setMedioPago(medioPago);

        double total = venta.total();
        static int ultimoNumero = 0; // numeracion de facturas durante la sesion
        int numero = ++ultimoNumero;

        string cae = ArcaMock::generarCAE();
        string qr = ArcaMock::generarTextoQR(venta.tipoComprobante(), numero, total, cae);

        Factura *f;
        if (venta.tipoComprobante() == 'A') {
            f = new FacturaA(&venta, numero, total, cae, qr);
        } else {
            f = new FacturaB(&venta, numero, total, cae, qr);
        }

        limpiarPantalla();
        cout << f->armarTexto() << endl;

        if (medioPago == EFECTIVO) {
            double pagoCon = leerDouble("Efectivo con el que paga: ", total); // no puede ser menor al total
            cout << "Vuelto: $" << (pagoCon - total) << endl;
            caja.registrarVentaEfectivo(total);
        }

        delete f;
    } else {
        cout << "No se registraron ventas." << endl;
    }

    cout << "\nPresione Enter para volver al menu...";
    cin.get();
}
