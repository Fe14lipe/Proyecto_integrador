#include <stdio.h>
#include <string.h>
#include "inventario.h"
#include "lectura.h"

int main() {
    char nombres_productos[MAX_PRODUCTO][MAX_NOMBRE];
    int cantidades_productos[MAX_PRODUCTO];
    float precios_productos[MAX_PRODUCTO];
    int conteo_productos = 0;

    char cedulas_clientes[MAX_CLIENTE][MAX_CEDULA];
    char nombres_clientes[MAX_CLIENTE][MAX_NOMBRE];
    int conteo_clientes = 0;

    char fechas_facturas[MAX_FACTURAS][MAX_FECHA];
    char cedulas_facturas[MAX_FACTURAS][MAX_CEDULA];
    char nombres_facturas[MAX_FACTURAS][MAX_NOMBRE];
    float valores_pagados_facturas[MAX_FACTURAS];
    int cantidades_productos_facturas[MAX_FACTURAS];
    int conteo_facturas = 0;

    cargarProductos(nombres_productos, cantidades_productos, precios_productos, &conteo_productos, "inventario.txt");
    cargarClientes(cedulas_clientes, nombres_clientes, &conteo_clientes, "clientes.txt");
    cargarFacturas(fechas_facturas, cedulas_facturas, nombres_facturas, valores_pagados_facturas, cantidades_productos_facturas, &conteo_facturas, "facturas.txt");

    int opcion;
    do {
        Menu();
        opcion = leerEntero("\nEscoja una opcion: ");

        switch (opcion) {
            case 1:
                agregarProducto(nombres_productos, cantidades_productos, precios_productos, &conteo_productos);
                break;
            case 2:
                editarProducto(nombres_productos, cantidades_productos, precios_productos, conteo_productos);
                break;
            case 3:
                borrarProducto(nombres_productos, cantidades_productos, precios_productos, &conteo_productos);
                break;
            case 4:
                listarProductos(nombres_productos, cantidades_productos, precios_productos, conteo_productos);
                break;
            case 5:
                agregarCliente(cedulas_clientes, nombres_clientes, &conteo_clientes);
                break;
            case 6:
                editarCliente(cedulas_clientes, nombres_clientes, conteo_clientes);
                break;
            case 7:
                listarClientes(cedulas_clientes, nombres_clientes, conteo_clientes);
                break;
            case 8:
                facturar(fechas_facturas, cedulas_facturas, nombres_facturas, valores_pagados_facturas, cantidades_productos_facturas, &conteo_facturas,
                         nombres_productos, cantidades_productos, precios_productos, conteo_productos,
                         cedulas_clientes, nombres_clientes, conteo_clientes);
                break;
            case 9:
                buscarFactura(fechas_facturas, cedulas_facturas, nombres_facturas, valores_pagados_facturas, cantidades_productos_facturas, conteo_facturas);
                break;
            case 10:
                listarFacturas(fechas_facturas, cedulas_facturas, nombres_facturas, valores_pagados_facturas, cantidades_productos_facturas, conteo_facturas);
                break;
            case 11:
                printf("Saliendo del sistema...\n");
                guardarProductos(nombres_productos, cantidades_productos, precios_productos, conteo_productos, "inventario.txt");
                guardarClientes(cedulas_clientes, nombres_clientes, conteo_clientes, "clientes.txt");
                guardarFacturas(fechas_facturas, cedulas_facturas, nombres_facturas, valores_pagados_facturas, cantidades_productos_facturas, conteo_facturas, "facturas.txt");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 11);

    return 0;
}