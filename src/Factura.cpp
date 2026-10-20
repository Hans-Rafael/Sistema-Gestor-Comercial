// Autor: Integrante 3
#include "Factura.h"
#include <string>
using namespace std;

Factura::Factura(Venta *v, int n, double t, string c, string qr) {
    venta = v;
    numero = n;
    total = t;
    cae = c;
    textoQR = qr;
}

string Factura::armarTexto() {
    string texto = "";
    
    // Encabezado con tipo de factura en carácter
    texto += "========================================\n";
    texto += "            FACTURA " + string(1, getTipo()) + "\n";
    texto += "========================================\n";
    texto += "Nro. Comprobante: " + to_string(numero) + "\n";
    texto += "----------------------------------------\n";
    texto += "CANT  PRODUCTO             SUBTOTAL\n";
    texto += "----------------------------------------\n";

    // 1. Mostrar ítems
    if (venta != NULL) {
        for (int i = 0; i < venta->getCantidadTotalItems(); i++) {
            Producto *p = venta->getProductoItem(i);
            int cant = venta->getCantidadItem(i);
            double sub = venta->subtotalItem(i);

            // Formatear decimales del subtotal a mano
            long centavosSub = (long)(sub * 100 + 0.5);
            string decSub = to_string(centavosSub % 100);
            if (decSub.length() < 2) decSub = "0" + decSub;
            string subFormateado = to_string(centavosSub / 100) + "." + decSub;

            string nombre = p ? p->getNombre() : "Producto";
            if (nombre.length() > 20) nombre = nombre.substr(0, 20);

            texto += to_string(cant) + "x   " + nombre + "  $" + subFormateado + "\n";
        }
    }

    // 2. Formatear Total a mano
    long centavosTotal = (long)(total * 100 + 0.5);
    string decTotal = to_string(centavosTotal % 100);
    if (decTotal.length() < 2) decTotal = "0" + decTotal;
    string totalFormateado = to_string(centavosTotal / 100) + "." + decTotal;

    // Pie
    texto += "----------------------------------------\n";
    texto += "TOTAL: $" + totalFormateado + "\n";
    texto += "CAE: " + cae + "\n";
    texto += "QR: " + textoQR + "\n";
    texto += "========================================\n";

    return texto;
}