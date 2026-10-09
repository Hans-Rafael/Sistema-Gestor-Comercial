# Sistema-Gestor-Comercial
Sistema de Gestión Comercial y POS en C++ con control de stock FEFO, facturación electrónica simulada (ARCA) y gestión de caja.

## Compilar

Desde la raiz del proyecto:

```bash
g++ -std=c++17 -Wall -Wextra -IModelos -IInventarioStock -IVentasFacturacion -ICaja -IInterfazUtilidades main.cpp Modelos/*.cpp InventarioStock/*.cpp VentasFacturacion/*.cpp Caja/*.cpp InterfazUtilidades/*.cpp -o gestor
```

Ejecutar: `./gestor`
