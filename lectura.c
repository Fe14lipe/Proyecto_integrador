#include <stdio.h>
#include <string.h>
#include "lectura.h"

int leerEnteroPositivo(char*mensaje){
    int valor;
    do{
        printf("ingrese un dato: ");
        scanf("%d",&valor);
    }while(valor <= 0);
    return valor;
}

int leerEntero(const char* mensaje) {
    int valor;
    printf("%s", mensaje);
    while (scanf("%d", &valor) != 1) {
        while (getchar() != '\n'); // Limpiar el buffer de entrada
        printf("Entrada no valida. %s", mensaje);
    }
    return valor;
}


int leerEnteroEntre(char* mensaje, int a, int b) {
    int num;
    do {
        printf("%s", mensaje);
        scanf("%d", &num);
        if (num < a || num > b) {
            printf("Error: Debe ingresar un número entre %d y %d.\n", a, b);
        }
    } while (num < a || num > b);
    return num;
}

float leerFlotantePositivo(char*mensaje){
    float valor;
    do{
        printf("Ingrese un dato: ");
        scanf("%f",&valor);
    }while(valor <= 0);
    return valor;
}

float leerFlotanteEntre(char* mensaje, float a, float b) {
    float num;
    do {
        printf("%s", mensaje);
        scanf("%f", &num);
        if (num < a || num > b) {
            printf("Error: Debe ingresar un número entre %f y %f.\n", a, b);
        }
    } while (num < a || num > b);
    return num;
}

float leerFlotante (char*mensaje){
    float valor;
    printf("%s",valor);
    scanf("%f",&valor);
    return valor;
}

float leerFlotanteMayorIgual(char* mensaje, float lim){
    float valor;
    do{
        printf("Ingrese un dato: ");
        scanf("%f",&valor);
    }while(valor < lim);
    return valor;
}

char leerCaracter (char*mensaje){
    char caracter;
    printf("%s", mensaje);
    scanf("%c", &caracter);
    return caracter;
}