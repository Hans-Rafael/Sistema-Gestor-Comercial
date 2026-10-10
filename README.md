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

## Pendientes

Para ver que falta implementar: `grep -rn TODO src`
