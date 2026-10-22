// Autor: Integrante 3
#include <iostream>
#include "Venta.h"
#include "Factura.h"
#include "ArcaMock.h"
#include "Validaciones.h"
using namespace std;

int fallas = 0;
void verificar(bool cond, string nombre) {
    if (cond) cout << "OK    " << nombre << endl;
    else { cout << "FALLA " << nombre << endl; fallas++; }
}

int main() {
    Producto leche("1122334451", "Leche", 1000.00, 21.0, 10);
    Producto pan("1122334452", "Pan", 1500.00, 10.5, 5);

    Venta v(CONSUMIDOR_FINAL);
    verificar(v.agregarItem(&leche, 2), "agregarItem");
    verificar(v.agregarItem(&pan, 1), "agregarItem segundo producto");
    verificar(!v.agregarItem(&pan, 0), "agregarItem rechaza cantidad 0");
    verificar(v.precioConIVA(&leche) > 1209.99 && v.precioConIVA(&leche) < 1210.01, "precio con IVA 21%");
    verificar(v.calcularTotal() > 4077.49 && v.calcularTotal() < 4077.51, "total 2 leche + 1 pan");
    verificar(v.tipoComprobante() == 'B', "consumidor final -> factura B");
    verificar(v.calcularIVAContenido() > 577.49 && v.calcularIVAContenido() < 577.51, "IVA contenido 2 leche + 1 pan");
    verificar(v.calcularPrecioSinIVA() > 3499.99 && v.calcularPrecioSinIVA() < 3500.01, "precio sin IVA 2 leche + 1 pan");

    Venta va(RESPONSABLE_INSCRIPTO);
    verificar(va.tipoComprobante() == 'A', "responsable inscripto -> factura A");

    // ArcaMock
    string cae = ArcaMock::generarCAE();
    verificar(cae.length() == 14, "CAE de 14 digitos");
    string qr = ArcaMock::generarTextoQR('B', 1, 2475.5, cae);
    verificar(qr == "ARCA-QR|Factura B|Nro 00000001|Total 2475.50|CAE " + cae, "texto QR con formato");

    // CUIT
    verificar(cuitValido("20-12345678-6"), "CUIT valido con guiones");
    verificar(cuitValido("20123456786"), "CUIT valido sin guiones");
    verificar(!cuitValido("20-12345678-5"), "CUIT con digito verificador incorrecto");
    verificar(!cuitValido("20-1234567-5"), "CUIT con menos de 11 digitos");
    verificar(cuitValido(EMISOR_CUIT), "CUIT del emisor es valido");

    // herencia y virtual con Factura*
    Factura *f = new FacturaA(&va, 7, 100.5, cae);
    verificar(f->getTipo() == 'A', "virtual getTipo via puntero base");
    string txt = f->armarTexto();
    verificar(txt.find("FACTURA A") != string::npos, "armarTexto usa la clase derivada");
    verificar(txt.find("TOTAL: $100.50") != string::npos, "monto con dos decimales");
    verificar(txt.find("CUIT emisor: " + EMISOR_CUIT) != string::npos, "factura A muestra CUIT del emisor");
    verificar(txt.find("Razon social: " + EMISOR_RAZON_SOCIAL) != string::npos, "factura A muestra razon social");
    delete f;

    Factura *fa2 = new FacturaA(&v, 10, v.calcularTotal(), cae, "20-12345678-6");
    string txtA = fa2->armarTexto();
    verificar(txtA.find("CUIT cliente: 20-12345678-6") != string::npos, "factura A muestra CUIT del cliente");
    verificar(txtA.find("Precio neto: $3500.00") != string::npos, "factura A muestra precio neto");
    delete fa2;

    // régimen de transparencia solo en factura B
    Factura *fb = new FacturaB(&v, 8, v.calcularTotal(), cae);
    string txtB = fb->armarTexto();
    verificar(txtB.find("IVA Contenido: $577.50") != string::npos, "factura B muestra IVA contenido");
    verificar(txtB.find("Precio sin IVA: $3500.00") != string::npos, "factura B muestra precio sin IVA");
    verificar(txtB.find("Otros Impuestos") == string::npos, "factura B no muestra otros impuestos");
    delete fb;
    Factura *fa = new FacturaA(&v, 9, v.calcularTotal(), cae);
    verificar(fa->armarTexto().find("Transparencia") == string::npos, "factura A no muestra régimen de transparencia");
    delete fa;

    cout << (fallas == 0 ? "\nTODO OK" : "\nHAY FALLAS") << endl;
    return fallas;
}
