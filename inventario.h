#define MAX_PRODUCTO 50
#define MAX_CLIENTE 50
#define MAX_FACTURAS 50
#define MAX_NOMBRE 50
#define MAX_CEDULA 10
#define MAX_FECHA 10

// Funciones para productos
void cargarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int* conteo, const char* filename);
void guardarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int conteo, const char* filename);
void agregarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int* conteo);
void editarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int conteo);
void borrarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int* conteo);
void listarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int conteo);

// Funciones para clientes
void cargarClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int* conteo, const char* filename);
void guardarClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int conteo, const char* filename);
void agregarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int* conteo);
void editarCliente(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int conteo);
void listarClientes(char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], int conteo);

// Funciones para facturas
void cargarFacturas(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                    float valores_pagados[], int cantidades_productos[], int* conteo, const char* filename);
void guardarFacturas(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                     float valores_pagados[], int cantidades_productos[], int conteo, const char* filename);
void facturar(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
              float valores_pagados[], int cantidades_productos[], int* conteo_facturas,
              char nombres_productos[][MAX_NOMBRE], int cantidades_productos_inv[], float precios_productos[], int conteo_productos,
              char cedulas_clientes[][MAX_CEDULA], char nombres_clientes[][MAX_NOMBRE], int conteo_clientes);
void buscarFactura(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                   float valores_pagados[], int cantidades_productos[], int conteo);
void listarFacturas(char fechas[][MAX_FECHA], char cedulas[][MAX_CEDULA], char nombres[][MAX_NOMBRE], 
                    float valores_pagados[], int cantidades_productos[], int conteo);

void Menu();