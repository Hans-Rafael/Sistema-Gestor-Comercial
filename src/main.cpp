// Autor: Integrante 5
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Producto.h"
#include "DatosPrueba.h"
#include "Validaciones.h"
#include "Pantalla.h"
#include "Usuario.h"
#include "AuthService.h"
#include "CajaService.h"
#include "InventarioService.h"
#include "AlertasService.h"
#include "VentaService.h"
#include "Fechas.h"
using namespace std;

void mostrarMenu() {
    cout << "===== GESTOR DE NEGOCIO =====" << endl;
    cout << "1. Nueva venta" << endl;
    cout << "2. Ingresar compra / lote" << endl;
    cout << "3. Consola de alertas" << endl;
    cout << "4. Movimientos de caja" << endl;
    cout << "5. Cierre de caja" << endl;
    cout << "0. Salir" << endl;
}

int main() {
    srand(time(nullptr));                              // una sola vez, para el CAE al azar
    Producto productos[MAX_PRODUCTOS];
    int cantProductos = cargarDatosDePrueba(productos);
    EstadoCaja caja;

    // TODO (Integrante 5): login con validarLogin y apertura de caja con abrirCaja

    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 0, 5);
        switch (opcion) {
            case 1: pantallaVenta(productos, cantProductos);  break;
            case 2: pantallaCompra(productos, cantProductos); break;
            case 3: pantallaAlertas(productos, cantProductos); break;
            case 4: pantallaMovimientosCaja(caja); break;
            case 5: pantallaCierreCaja(caja); break;
            case 0: cout << "Hasta luego" << endl; break;
        }
    } while (opcion != 0);
    return 0;
}
