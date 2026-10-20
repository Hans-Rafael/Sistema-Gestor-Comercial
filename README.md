# Sistema-Gestor-Comercial
Sistema de Gestión Comercial y POS en C++ con control de stock FEFO, facturación electrónica simulada (ARCA) y gestión de caja.

## Estructura

Todo el codigo esta en `src/` (los `.h` y los `.cpp`, incluido `main.cpp`).

## Compilar y ejecutar

Desde la raiz del proyecto:

```bash
make        # compila todo y genera el ejecutable "gestor"
make run    # compila y ejecuta
make clean  # borra los archivos generados
```

- Linux: `make`
- Windows (MinGW): `mingw32-make` en lugar de `make`; el ejecutable es `gestor.exe`.

Hay que tener `g++` instalado. Los warnings cuentan como errores a corregir (`-Wall -Wextra`).

## Reglas del proyecto

- Codigo con **clases** (POO): atributos privados, constructores, getters/setters, herencia con `virtual` y `new`/`delete`.
- Solo librerias vistas en clase: `<iostream>`, `<cstdlib>`, `<fstream>`, `<random>`.
- Sin `struct`, `enum`, `const T&`, `try/catch` ni `<ctime>`.
- Al iniciar el programa pide la fecha de hoy (DD-MM-AAAA).
- Usuarios de prueba: `cajero1` / `1234`, `cajero2` / `5678` y `juan` / `4321` (encargado).
- Inventario: si existe `productos.txt`, se carga al iniciar; si no existe, arranca vacio. Al salir se guardan `productos.txt` y `lotes.txt`.
  - `productos.txt`: una linea por producto, campos separados por `;`: `codigo;nombre;precio;iva;stockMinimo`
  - `lotes.txt`: una linea por lote, campos separados por `;`: `codigo;vencimiento;cantidad`

## Pendientes

Para ver que falta implementar: `grep -rn TODO src`
