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
#include "ArchivoHelper.h"
using namespace std;

void Menu()
{
    cout << "===== GESTOR DE NEGOCIO =====" << endl;
    cout << "1. Nueva venta" << endl;
    cout << "2. Ingresar compra / lote" << endl;
    cout << "3. Consola de alertas" << endl;
    cout << "4. Movimientos de caja" << endl;
    cout << "5. Cierre de caja" << endl;
    cout << "6. Listar productos" << endl;
    cout << "7. Buscar producto" << endl;
    cout << "8. Alta de producto" << endl;
    cout << "0. Salir" << endl;
}

int main()
{
    // no usamos <ctime>: la fecha de hoy se escribe a mano
    string entrada, fecha = "";

    while (fecha == "")
    {
        // fecha = convertirFecha(leerLinea("Fecha de hoy (DD-MM-AAAA): "));
        cout << "Fecha de hoy (DD-MM-AAAA): ";
        getline(cin, entrada);
        fecha = convertirFecha(entrada);
        if (fecha == "")
            cout << "Fecha invalida" << endl;
    }
    setFechaHoy(fecha);

    Inventario inventario(CAPACIDAD_PRODUCTOS);
    Auth auth(CAPACIDAD_USUARIOS);
    Caja caja;
    // productos.txt se carga si existe; si no existe, el inventario arranca vacio
    cargarProductos(inventario);
    cargarUsuariosDePrueba(auth);

    // login: Usuario es de Auth, no se hace delete
    Usuario *usuario = NULL;
    while (usuario == NULL)
    {
        // en lineas separadas: el orden de evaluacion de los argumentos no esta definido
        string nombreUsuario = leerLinea("Usuario: ");
        string clave = leerLinea("Clave: ");
        usuario = auth.validarLogin(nombreUsuario, clave);
        if (usuario == NULL)
            cout << "Usuario o clave incorrectos" << endl;
    }
    cout << "\nBienvenido " << usuario->getNombre() << " (" << usuario->getRol() << ")\n"
         << endl;
    caja.abrir(leerDouble("Monto de apertura: ", 0));
    cout << endl;
    int opcion;
    do
    {
        Menu();
        opcion = leerEntero("Opcion: ", 0, 8);
        switch (opcion)
        {
        case 1:
            pantallaVenta(inventario, caja);
            break;
        case 2:
            pantallaCompra(inventario);
            break;
        case 3:
            pantallaAlertas(inventario);
            break;
        case 4:
            pantallaMovimientosCaja(caja);
            break;
        case 5:
            pantallaCierreCaja(caja);
            break;
        case 6:
            pantallaListar(inventario);
            break;
        case 7:
            pantallaBuscar(inventario);
            break;
        case 8:
            pantallaAltaProducto(inventario);
            break;
        case 0:
            cout << "Hasta luego" << endl;
            break;
        }
    } while (opcion != 0);
    guardarProductos(inventario);
    return 0;
}
