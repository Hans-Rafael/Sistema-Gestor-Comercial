// Autor: Integrante 2
#include <iostream>
#include "Inventario.h"
#include "Fechas.h"
#include "Validaciones.h"
#include "Pantalla.h"
#include "ArchivoHelper.h"
using namespace std;

void mostrarProducto(Inventario& inv, Producto *p) {
    cout << p->getCodigoBarras() << " | " << p->getNombre()
         << " | $" << p->getPrecioBase() << " + IVA " << p->getPorcentajeIVA() << "%"
         << " | Stock: " << inv.stockTotal(p, fechaHoy());
    if (inv.esStockCritico(p, fechaHoy())) cout << " [Stock Critico]";
    cout << endl;
}
 
void pantallaListar(Inventario& inv) {            // opcion 6
    if (inv.getCantidad() == 0) { cout << "No hay productos" << endl; return; }
    cout << "  Codigo   |-->  Producto  |-->  Precio base + IVA  |-->  Stock total\n" << endl;
    for (int i = 0; i < inv.getCantidad(); i++) mostrarProducto(inv, inv.getProducto(i));

    if (leerEntero("\nDesea exportar/guardar este listado en el archivo listado_productos.txt? (1 = Si, 2 = No): ", 1, 2) == 1) {
        if (guardarArrayProductos(inv, "listado_productos.txt")) cout << "Listado guardado en listado_productos.txt" << endl;
        else cout << "[ERROR] No se pudo crear listado_productos.txt" << endl;
    }
}
 
void pantallaBuscar(Inventario& inv) {            // opcion 7
    int modo = leerEntero("Buscar por 1) codigo  2) nombre: ", 1, 2);
    if (modo == 1) {
        Producto *p = inv.buscarProducto(leerLinea("Codigo: "));
        if (p == NULL) cout << "No existe ese codigo" << endl;
        else mostrarProducto(inv, p);
    } else {
        string texto = leerLinea("Nombre (o parte): ");
        int i = inv.buscarPorNombre(texto, 0);
        if (i == -1) cout << "Sin resultados" << endl;
        while (i != -1) {
            mostrarProducto(inv, inv.getProducto(i));
            i = inv.buscarPorNombre(texto, i + 1);
        }
    }
}
 
void pantallaAltaProducto(Inventario& inv) {      // opcion 8
    string codigo = leerLinea("Codigo de barras (10 digitos): ");
    if (codigo.length() != 10) { cout << "El codigo debe tener 10 digitos" << endl; return; }
    if (inv.buscarProducto(codigo) != NULL) { cout << "Ese codigo ya existe" << endl; return; }
    string nombre = leerLinea("Nombre: ");
    double precio = leerDouble("Precio sin IVA: ", 0.01);
    int opIva = leerEntero("IVA (1 = 21%, 2 = 10,5%): ", 1, 2);
    double iva = 21.0;
    if (opIva == 2) iva = 10.5;
    int minimo = leerEntero("Stock minimo: ", 0, 9999);
    int cantidad = leerEntero("Stock inicial (0 = sin stock): ", 0, 9999);
    Producto *p = new Producto(codigo, nombre, precio, iva, minimo);
    if (cantidad > 0) {
        string venc = convertirFecha(leerLinea("Vencimiento (DD/MM/AAAA): "));
        if (venc == "") { cout << "Fecha invalida" << endl; delete p; return; }
        p->agregarLote(venc, cantidad);
    }
    if (!inv.agregarProducto(p)) { cout << "Inventario lleno" << endl; delete p; return; }
    cout << "Producto agregado" << endl;
}
