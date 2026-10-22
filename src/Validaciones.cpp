// Autor: Integrante 5
#include <iostream>
#include <cstdlib>
#include "Validaciones.h"
using namespace std;

int leerEntero(string mensaje, int minimo, int maximo) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= minimo && valor <= maximo) {
            cin.ignore(10000, '\n');          // descarta el Enter que quedo en el buffer
            return valor;
        }
        if (cin.eof()) exit(0);               // entrada terminada: salir
        cout << "Entrada invalida. Ingrese un numero entre " << minimo << " y " << maximo << endl;
        cin.clear();                          // limpia el estado de error
        cin.ignore(10000, '\n');              // descarta lo que escribio mal
    }
}

double leerDouble(string mensaje, double minimo) {
    double valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= minimo) {
            cin.ignore(10000, '\n');
            return valor;
        }
        if (cin.eof()) exit(0);
        cout << "Entrada invalida. Ingrese un numero mayor o igual a " << minimo << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

string leerLinea(string mensaje) {
    string texto;
    while (true) {
        cout << mensaje;
        if (!getline(cin, texto)) exit(0);
        if (!texto.empty() && texto.find(';') == string::npos) return texto;
        cout << "Texto invalido (no puede estar vacio ni contener ';')" << endl;
    }
}

bool cuitValido(string cuit) {
    string digitos = "";
    for (size_t i = 0; i < cuit.length(); i++) {
        if (cuit[i] == '-') continue;
        if (cuit[i] < '0' || cuit[i] > '9') return false;
        digitos += cuit[i];
    }
    if (digitos.length() != 11) return false;

    // digito verificador: pesos 5,4,3,2,7,6,5,4,3,2 sobre los primeros 10 digitos, modulo 11
    int pesos[10] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2};
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        suma += (digitos[i] - '0') * pesos[i];
    }
    int verificador = 11 - (suma % 11);
    if (verificador == 11) verificador = 0;
    if (verificador == 10) return false; // CUIT inexistente
    return verificador == (digitos[10] - '0');
}

string leerCUIT(string mensaje) {
    while (true) {
        string cuit = leerLinea(mensaje);
        if (cuitValido(cuit)) {
            string digitos = "";
            for (size_t i = 0; i < cuit.length(); i++) {
                if (cuit[i] != '-') digitos += cuit[i];
            }
            return digitos.substr(0, 2) + "-" + digitos.substr(2, 8) + "-" + digitos.substr(10, 1);
        }
        cout << "CUIT invalido. Ingrese 11 digitos (ej: 20-12345678-5)." << endl;
    }
}

void limpiarPantalla() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    cout << "\nPresione Enter para continuar..." << endl;
    cin.get();
}
