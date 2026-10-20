// Autor: Integrante 2
#include <iostream>
#include "Inventario.h"
#include "Fechas.h"
#include "Validaciones.h"
#include "Pantalla.h"
using namespace std;

void pantallaCompra(Inventario &inv)
{ // opcion 2: recibir mercaderia como lote
    string codigo = leerLinea("Codigo de barras: ");
    Producto *p = inv.buscarProducto(codigo);
    limpiarPantalla();
    if (p == NULL)
    {
        cout << "Producto inexistente" << endl;
        return;
    }
    cout << "Producto: " << p->getNombre() << endl;
    int cant = leerEntero("Cantidad: ", 1, 100000);

    // repite hasta tener una fecha valida y que no este ya vencida
    string venc = "";
    while (venc == "")
    {
        venc = convertirFecha(leerLinea("Vencimiento (DD/MM/AAAA): "));
        if (venc == "")
        {
            cout << "Fecha invalida" << endl;
        }
        else if (compararFechas(venc, fechaHoy()) < 0)
        {
            cout << "La fecha ya paso" << endl;
            venc = "";
        }
    }

    if (!p->agregarLote(venc, cant))
    {
        cout << "No hay lugar para mas lotes de este producto" << endl;
        return;
    }
    cout << "Lote cargado (vence " << venc << "). Stock actual: " << inv.stockTotal(p, fechaHoy()) << endl;
    
}
