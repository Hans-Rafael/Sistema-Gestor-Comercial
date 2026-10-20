// Autor: Integrante 4
#include <iostream>
#include "Caja.h"
#include "Auth.h"
#include "Usuario.h"
using namespace std;

int fallas = 0;
void verificar(bool cond, string nombre) {
    if (cond) cout << "OK    " << nombre << endl;
    else { cout << "FALLA " << nombre << endl; fallas++; }
}

int main() {
    // no se puede registrar nada con la caja cerrada
    Caja caja;
    verificar(!caja.registrarGasto(100), "no registra gasto con caja cerrada");
    verificar(!caja.registrarIngreso(100), "no registra ingreso con caja cerrada");

    // escenario 5 de la guia: 50.000 + 98.000 - 5.500 = 142.500
    verificar(caja.abrir(50000), "abre la caja con 50000");
    verificar(!caja.abrir(1000), "no abre dos veces");
    caja.registrarVentaEfectivo(98000);
    verificar(caja.registrarGasto(5500), "registra gasto 5500");
    verificar(!caja.registrarGasto(-10), "no registra gasto negativo");
    verificar(caja.efectivoEsperado() == 142500, "esperado = 142500");
    verificar(caja.diferencia(142500) == 0, "contado igual al esperado: caja cuadrada");
    verificar(caja.diferencia(142000) == -500, "contado menor: diferencia negativa");

    // Auth: login con usuarios de prueba
    Auth auth(3);
    auth.agregarUsuario(new Encargado("encargado", "1234"));
    auth.agregarUsuario(new Cajero("cajero", "1234"));
    Usuario *u = auth.validarLogin("cajero", "1234");
    verificar(u != NULL && u->getRol() == "Cajero", "login de cajero devuelve Cajero");
    verificar(auth.validarLogin("encargado", "1234")->esEncargado(), "login de encargado (herencia + virtual)");
    verificar(auth.validarLogin("encargado", "0000") == NULL, "clave incorrecta devuelve NULL");
    verificar(auth.validarLogin("nadie", "1234") == NULL, "usuario inexistente devuelve NULL");

    cout << (fallas == 0 ? "\nTODO OK" : "\nHAY FALLAS") << endl;
    return fallas;
}
