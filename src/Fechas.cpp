// Autor: Integrante 1
#include <iostream>
#include "Fechas.h"
using namespace std;

string fechaActual = "01-01-2026"; // se cambia con setFechaHoy

// lee 'largo' digitos desde la posicion 'inicio'; -1 si hay algo que no es digito
int numeroEn(string texto, int inicio, int largo) {
    int valor = 0;
    for (int i = inicio; i < inicio + largo; i++) {
        if (texto[i] < '0' || texto[i] > '9') return -1;
        valor = valor * 10 + (texto[i] - '0');
    }
    return valor;
}

// dias transcurridos desde el 01-01-1970 hasta la fecha (algoritmo de calendario civil)
long diasDesdeBase(int a, int m, int d) {
    if (m <= 2) a--;
    long era = (a >= 0 ? a : a - 399) / 400;
    long yoe = a - era * 400;
    long doy = (153 * (m > 2 ? m - 3 : m + 9) + 2) / 5 + d - 1;
    long doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
    return era * 146097 + doe - 719468;
}

// pasa de dias desde 1970 a texto "DD-MM-AAAA"
string textoDesdeDias(long z) {
    z += 719468;
    long era = (z >= 0 ? z : z - 146096) / 146097;
    long doe = z - era * 146097;
    long yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
    long doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    long mp = (5 * doy + 2) / 153;
    int d = doy - (153 * mp + 2) / 5 + 1;
    int m = mp < 10 ? mp + 3 : mp - 9;
    int a = yoe + era * 400 + (m <= 2 ? 1 : 0);

    string dd = to_string(d);
    string mm = to_string(m);
    if (d < 10) dd = "0" + dd;
    if (m < 10) mm = "0" + mm;
    return dd + "-" + mm + "-" + to_string(a);
}

long diasDeTexto(string fecha) {
    return diasDesdeBase(numeroEn(fecha, 6, 4), numeroEn(fecha, 3, 2), numeroEn(fecha, 0, 2));
}

void setFechaHoy(string fecha) {
    fechaActual = fecha;
}

string fechaHoy() {
    return fechaActual;
}

string fechaEnDias(int n) {
    return textoDesdeDias(diasDeTexto(fechaActual) + n);
}

int diasHasta(string fecha) {
    return (int)(diasDeTexto(fecha) - diasDeTexto(fechaActual));
}

// dias que tiene el mes m del anio a (controla los bisiestos)
int diasDelMes(int m, int a) {
    if (m == 2) {
        bool bisiesto = (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
        return bisiesto ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

string convertirFecha(string ddmmaaaa) {
    if (ddmmaaaa.length() != 10) return "";
    int d = numeroEn(ddmmaaaa, 0, 2);
    int m = numeroEn(ddmmaaaa, 3, 2);
    int a = numeroEn(ddmmaaaa, 6, 4);
    if (m < 1 || m > 12 || a < 1900) return "";
    if (d < 1 || d > diasDelMes(m, a)) return "";
    if (ddmmaaaa[2] != '/' && ddmmaaaa[2] != '-') return "";
    if (ddmmaaaa[5] != '/' && ddmmaaaa[5] != '-') return "";
    return ddmmaaaa.substr(0, 2) + "-" + ddmmaaaa.substr(3, 2) + "-" + ddmmaaaa.substr(6, 4);
}

int compararFechas(string a, string b) {
    long x = numeroEn(a, 6, 4) * 10000 + numeroEn(a, 3, 2) * 100 + numeroEn(a, 0, 2);
    long y = numeroEn(b, 6, 4) * 10000 + numeroEn(b, 3, 2) * 100 + numeroEn(b, 0, 2);
    return (int)(x - y);
}
