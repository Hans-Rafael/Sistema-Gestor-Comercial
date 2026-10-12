#include <iostream>
#include <string>
#include "Inventario.h"
#include "Venta.h"
#include "ArcaMock.h"
#include "Factura.h"
#include "Validaciones.h"
#include "Tipos.h"

using namespace std;

void pantallaVenta(Inventario &inventario, Caja &caja) {
    limpiarPantalla();
    cout << "=== MODULO DE VENTAS ===" << endl;

    int condicion = leerEntero("Condicion cliente (0: Consumidor Final, 1: Resp Inscripto, 2: Monotributo): ", 0, 2);
    int medioPago = leerEntero("Medio de pago (0: Efectivo, 1: Tarjeta, 2: Transferencia): ", 0, 2);

    Venta venta(condicion, medioPago);

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
        double total = 0;
        for (int i = 0; i < venta.getCantItems(); i++) {
            total += venta.precioConIVA(venta.getProductoItem(i)) * venta.getCantidadItem(i);
        }

        string cae = ArcaMock::generarCAE();
        string qr = ArcaMock::generarTextoQR(venta.tipoComprobante(), 1, total, cae);

        Factura *f;
        if (venta.tipoComprobante() == 'A') {
            f = new FacturaA(&venta, 1, total, cae, qr);
        } else {
            f = new FacturaB(&venta, 1, total, cae, qr);
        }

        limpiarPantalla();
        cout << f->armarTexto() << endl;

        if (medioPago == EFECTIVO) {
            double pagoCon = leerDouble("Efectivo con el que paga: ", 0, 9999999.99);
            double vuelto = pagoCon - total;
            cout << "Vuelto: $" << vuelto << endl;
            caja.agregarVentaEfectivo(total); // Asumiendo el método correspondiente de caja
        }

        delete f;
    } else {
        cout << "No se registraron ventas." << endl;
    }

    cout << "\nPresione Enter para volver al menu...";
    cin.get();
}