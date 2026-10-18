// Autor: Integrante 1
#include <iostream>
#include "Fechas.h"
#include "Producto.h"
#include "Usuario.h"
#include "Inventario.h"
#include "DatosPrueba.h"
using namespace std;

int fallas = 0;
void verificar(bool cond, string nombre) {
    if (cond) cout << "OK    " << nombre << endl;
    else { cout << "FALLA " << nombre << endl; fallas++; }
}

int main() {
    setFechaHoy("09-10-2026");

    // fechas
    verificar(convertirFecha("20/11/2026") == "20-11-2026", "convertirFecha barra a guion");
    verificar(convertirFecha("31/02/2026") == "", "convertirFecha rechaza 31/02");
    verificar(compararFechas("20-11-2026", "09-10-2026") > 0, "compararFechas posterior");
    verificar(compararFechas("09-10-2026", "20-11-2026") < 0, "compararFechas anterior");
    verificar(compararFechas("09-10-2026", "09-10-2026") == 0, "compararFechas igual");
    verificar(diasHasta("11-10-2026") == 2, "diasHasta 2 dias");
    verificar(diasHasta("07-10-2026") == -2, "diasHasta negativo si ya paso");
    verificar(fechaEnDias(-2) == "07-10-2026", "fechaEnDias negativo");
    verificar(fechaEnDias(40) == "18-11-2026", "fechaEnDias cruza de mes");

    // producto y lotes
    Producto p("3333333333", "Test", 100, 21, 5);
    for (int i = 0; i < MAX_LOTES; i++) p.agregarLote("01-01-2027", 1);
    verificar(!p.agregarLote("01-01-2027", 1), "agregarLote devuelve false al llegar a MAX_LOTES");
    p.getLote(0)->setCantidad(0);
    verificar(p.agregarLote("05-05-2027", 9), "agregarLote reutiliza un lote agotado");

    // herencia y virtual
    Usuario *u = new Cajero("cajero", "1234");
    Usuario *e = new Encargado("encargado", "1234");
    verificar(u->getRol() == "Cajero", "virtual: Cajero via puntero base");
    verificar(!u->esEncargado() && e->esEncargado(), "esEncargado distingue roles");
    verificar(e->claveCorrecta("1234") && !e->claveCorrecta("0000"), "claveCorrecta");
    delete u;
    delete e;

    // datos de prueba
    Inventario inv(CAPACIDAD_PRODUCTOS);
    cargarDatosDePrueba(inv);
    verificar(inv.getCantidad() == 5, "cargarDatosDePrueba carga 5 productos");

    cout << (fallas == 0 ? "\nTODO OK" : "\nHAY FALLAS") << endl;
    return fallas;
}
