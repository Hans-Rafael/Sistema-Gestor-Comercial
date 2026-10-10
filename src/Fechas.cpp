// Autor: Integrante 1
#include <ctime>
#include "Fechas.h"
using namespace std;

// IMPORTANTE: todas las fechas del proyecto son texto "DD-MM-AAAA".
// No se pueden comparar con < o > (por ejemplo "05-12-2026" < "20-11-2026" daria verdadero).
// Para comparar fechas, todos tienen que usar compararFechas().

// TODO (Integrante 1): devolver la fecha de hoy como "DD-MM-AAAA".
//   1) time_t ahora = time(nullptr);
//   2) tm* f = localtime(&ahora);  -> f->tm_year + 1900, f->tm_mon + 1, f->tm_mday
//   3) armar el texto con to_string; si el mes o el dia es menor a 10, agregar un "0" delante.
// Por ahora devuelve un valor fijo.
string fechaHoy() {
    return "09-10-2026";
}

// TODO (Integrante 1): devolver hoy + n dias como "DD-MM-AAAA" (n puede ser negativo).
//   1) Sumar n * 86400 segundos (un dia) a time(nullptr).
//   2) Convertir con localtime y armar el texto igual que en fechaHoy().
// Por ahora devuelve un valor fijo.
string fechaEnDias(int) {
    return "09-10-2026";
}

// TODO (Integrante 1): dias desde hoy hasta fecha ("DD-MM-AAAA"). Negativo = ya paso.
//   1) Separar dia (posiciones 0-1), mes (3-4) y año (6-9) con substr y stoi.
//   2) Cargar un tm con esos datos y poner tm_hour = 12 (evita errores por horario de verano).
//   3) mktime() devuelve los segundos de esa fecha; hacer lo mismo con hoy.
//   4) (segundosFecha - segundosHoy) / 86400, redondeando bien.
// Por ahora devuelve 0.
int diasHasta(const string&) {
    return 0;
}

// TODO (Integrante 1): normalizar la fecha que escribe el usuario a "DD-MM-AAAA".
//   Debe aceptar "20/11/2026" y tambien "20-11-2026" (DD/MM/AAAA o DD-MM-AAAA).
//   Resultado: "20-11-2026" (siempre con guiones).
//   Usar substr: dia = posiciones 0-1, mes = 3-4, año = 6-9 (el separador se ignora).
//   Si el texto no tiene 10 caracteres, devolver "" (fecha invalida).
// Por ahora devuelve "".
string convertirFecha(const string&) {
    return "";
}

// TODO (Integrante 1): comparar dos fechas "DD-MM-AAAA".
//   Opcion simple: armar un numero con año, mes y dia (año * 10000 + mes * 100 + dia)
//   para cada fecha, y devolver la resta (primero - segundo).
//   Los demas modulos la usan para saber si un lote esta vencido y para ordenar por vencimiento (FEFO).
// Por ahora devuelve 0.
int compararFechas(const string&, const string&) {
    return 0;
}
