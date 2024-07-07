#include <stdio.h>
#include <string.h>
#include "inventario.h"

void cargarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int* conteo, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de inventario. Iniciando inventario vacio.\n");
        *conteo = 0;
        return;
    }

    fscanf(file, "%d\n", conteo);
    for (int i = 0; i < *conteo; i++) {
        fscanf(file, "%49s %d %f\n", nombres[i], &cantidades[i], &precios[i]);
    }
    fclose(file);
}

void guardarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int conteo, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("No se pudo guardar el archivo de inventario.\n");
        return;
    }

    fprintf(file, "%d\n", conteo);
    for (int i = 0; i < conteo; i++) {
        fprintf(file, "%s %d %.2f\n", nombres[i], cantidades[i], precios[i]);
    }
    fclose(file);
}

void agregarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int* conteo) {
    if (*conteo >= MAX_PRODUCTO) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[*conteo]);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidades[*conteo]);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precios[*conteo]);

    (*conteo)++;
    guardarProductos(nombres, cantidades, precios, *conteo, "inventario.txt");
    printf("Producto agregado exitosamente.\n");
}

void editarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int conteo) {
    char name[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", name);

    for (int i = 0; i < conteo; i++) {
        if (strcmp(nombres[i], name) == 0) {
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", nombres[i]);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &cantidades[i]);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precios[i]);

            guardarProductos(nombres, cantidades, precios, conteo, "inventario.txt");
            printf("Producto editado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void borrarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int* conteo) {
    char name[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", name);

    for (int i = 0; i < *conteo; i++) {
        if (strcmp(nombres[i], name) == 0) {
            for (int j = i; j < *conteo - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            (*conteo)--;
            guardarProductos(nombres, cantidades, precios, *conteo, "inventario.txt");
            printf("Producto eliminado exitosamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int conteo) {
    if (conteo == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("Productos en el inventario:\n");
    for (int i = 0; i < conteo; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", nombres[i], cantidades[i], precios[i]);
    }
}

void cargarClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int* conteo, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de clientes. Iniciando lista de clientes vacia.\n");
        *conteo = 0;
        return;
    }

    fscanf(file, "%d\n", conteo);
    for (int i = 0; i < *conteo; i++) {
        fscanf(file, "%10s %49s\n", cedulas[i], nombres[i]);
    }
    fclose(file);
}

void guardarClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int conteo, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("No se pudo guardar el archivo de clientes.\n");
        return;
    }

    fprintf(file, "%d\n", conteo);
    for (int i = 0; i < conteo; i++) {
        fprintf(file, "%s %s\n", cedulas[i], nombres[i]);
    }
    fclose(file);
}

void agregarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int* conteo) {
    if (*conteo >= MAX_CLIENTE) {
        printf("No se pueden agregar mas clientes.\n");
        return;
    }

    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedulas[*conteo]);
    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombres[*conteo]);

    (*conteo)++;
    guardarClientes(cedulas, nombres, *conteo, "clientes.txt");
    printf("Cliente agregado exitosamente.\n");
}

void editarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int conteo) {
    char cedula[MAX_CEDULA];
    printf("Ingrese la cedula del cliente a editar: ");
    scanf("%s", cedula);

    for (int i = 0; i < conteo; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            printf("Ingrese el nuevo nombre del cliente: ");
            scanf("%s", nombres[i]);

            guardarClientes(cedulas, nombres, conteo, "clientes.txt");
            printf("Cliente editado exitosamente.\n");
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

void listarClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int conteo) {
    if (conteo == 0) {
        printf("No hay clientes en el registro.\n");
        return;
    }

    printf("Clientes registrados:\n");
    for (int i = 0; i < conteo; i++) {
        printf("Cedula: %s, Nombre: %s\n", cedulas[i], nombres[i]);
    }
}

void cargarFacturas(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                    float valores_pagados[], int cantidades_productos[], int* conteo, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de facturas. Iniciando lista de facturas vacia.\n");
        *conteo = 0;
        return;
    }

    fscanf(file, "%d\n", conteo);
    for (int i = 0; i < *conteo; i++) {
        fscanf(file, "%10s %10s %49s %f %d\n", fechas[i], cedulas[i], nombres[i], 
               &valores_pagados[i], &cantidades_productos[i]);
    }
    fclose(file);
}

void guardarFacturas(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                     float valores_pagados[], int cantidades_productos[], int conteo, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("No se pudo guardar el archivo de facturas.\n");
        return;
    }

    fprintf(file, "%d\n", conteo);
    for (int i = 0; i < conteo; i++) {
        fprintf(file, "%s %s %s %.2f %d\n", fechas[i], cedulas[i], nombres[i], 
                valores_pagados[i], cantidades_productos[i]);
    }
    fclose(file);
}

void facturar(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
              float valores_pagados[], int cantidades_productos[], int* conteo_facturas,
              char nombres_productos[][MAX_NOMBRE], int cantidades_productos_inv[], float precios_productos[], int conteo_productos,
              char cedulas_clientes[][MAX_CEDULA], char nombres_clientes[][MAX_NOMBRE], int conteo_clientes) {
    if (*conteo_facturas >= MAX_FACTURAS) {
        printf("No se pueden agregar mas facturas.\n");
        return;
    }

    char nombre_producto[MAX_NOMBRE];
    int cantidad;

    printf("Ingrese la fecha (DD/MM/YYYY): ");
    scanf("%s", fechas[*conteo_facturas]);
    printf("Ingrese la cedula del cliente: ");
    scanf("%s", cedulas[*conteo_facturas]);
    getchar(); // Consume el newline después de la cédula
    printf("Ingrese el nombre del cliente: ");
    fgets(nombres[*conteo_facturas], MAX_NOMBRE, stdin);
    nombres[*conteo_facturas][strcspn(nombres[*conteo_facturas], "\n")] = 0; // Elimina el newline al final
    
    printf("Productos disponibles:\n");
    for (int i = 0; i < conteo_productos; i++) {
        printf("%d. %s (Cantidad: %d, Precio: %.2f)\n", i+1, nombres_productos[i], cantidades_productos_inv[i], precios_productos[i]);
    }
    
    int producto_index;
    printf("Seleccione el numero del producto: ");
    scanf("%d", &producto_index);
    producto_index--; // Ajustar para índice base 0
    
    if (producto_index < 0 || producto_index >= conteo_productos) {
        printf("Producto no valido.\n");
        return;
    }

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad);

    if (cantidades_productos_inv[producto_index] >= cantidad) {
        valores_pagados[*conteo_facturas] = precios_productos[producto_index] * cantidad;
        cantidades_productos[*conteo_facturas] = cantidad;
        cantidades_productos_inv[producto_index] -= cantidad;

        guardarProductos(nombres_productos, cantidades_productos_inv, precios_productos, conteo_productos, "inventario.txt");
        (*conteo_facturas)++;
        guardarFacturas(fechas, cedulas, nombres, valores_pagados, cantidades_productos, *conteo_facturas, "facturas.txt");

        printf("Factura creada exitosamente.\n");
    } else {
        printf("Stock insuficiente.\n");
    }
}

void buscarFactura(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                   float valores_pagados[], int cantidades_productos[], int conteo) {
    char fecha[MAX_FECHA];
    printf("Ingrese la fecha de la factura a buscar (DD/MM/YYYY): ");
    scanf("%s", fecha);

    for (int i = 0; i < conteo; i++) {
        if (strcmp(fechas[i], fecha) == 0) {
            printf("Fecha: %s, Cedula: %s, Nombre: %s, Valor Pagado: %.2f, Cantidad Productos: %d\n",
                   fechas[i], cedulas[i], nombres[i], valores_pagados[i], cantidades_productos[i]);
            return;
        }
    }
    printf("Factura no encontrada.\n");
}

void listarFacturas(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                    float valores_pagados[], int cantidades_productos[], int conteo) {
    if (conteo == 0) {
        printf("No hay facturas en el registro.\n");
        return;
    }

    printf("Facturas registradas:\n");
    for (int i = 0; i < conteo; i++) {
        printf("Fecha: %s, Cedula: %s, Nombre: %s, Valor Pagado: %.2f, Cantidad Productos: %d\n",
               fechas[i], cedulas[i], nombres[i], valores_pagados[i], cantidades_productos[i]);
    }
}

void Menu() {
    printf("\nSistema de Inventario de Tienda de Ropa Urbana\n");
    printf("1. Ingresar producto\n");
    printf("2. Editar producto\n");
    printf("3. Eliminar producto\n");
    printf("4. Listar productos\n");
    printf("5. Ingresar cliente\n");
    printf("6. Editar cliente\n");
    printf("7. Listar clientes\n");
    printf("8. Facturar\n");
    printf("9. Buscar factura\n");
    printf("10. Listar facturas\n");
    printf("11. Salir\n");
}