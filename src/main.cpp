// Autor: Integrante 5
#include <iostream>
#include <cstdlib>
#include "Inventario.h"
#include "Auth.h"
#include "Caja.h"
#include "DatosPrueba.h"
#include "Validaciones.h"
#include "Pantalla.h"
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
    // no usamos <ctime>: la fecha de hoy se escribe a mano
    string fecha = "";
    while (fecha == "") {
        fecha = convertirFecha(leerLinea("Fecha de hoy (DD-MM-AAAA): "));
        if (fecha == "") cout << "Fecha invalida" << endl;
    }
    setFechaHoy(fecha);

    Inventario inventario(CAPACIDAD_PRODUCTOS);
    Auth auth(CAPACIDAD_USUARIOS);
    Caja caja;
    cargarDatosDePrueba(inventario);
    cargarUsuariosDePrueba(auth);

    // TODO (Integrante 5): login con auth.validarLogin y apertura de caja con caja.abrir

    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 0, 5);
        switch (opcion) {
            case 1: pantallaVenta(inventario, caja); break;
            case 2: pantallaCompra(inventario); break;
            case 3: pantallaAlertas(inventario); break;
            case 4: pantallaMovimientosCaja(caja); break;
            case 5: pantallaCierreCaja(caja); break;
            case 0: cout << "Hasta luego" << endl; break;
        }
    } while (opcion != 0);
    return 0;
}
