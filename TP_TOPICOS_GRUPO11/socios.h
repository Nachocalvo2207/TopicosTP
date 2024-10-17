#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define ERROR 3

#define esLetra(x) ((( (x) >= 'A'&& (x) <= 'Z' )||( (x) >= 'a' && (x) <='z' )) ? 1 : 0)
#define esNumero(x) (( (x) >= '1' && (x) <= '9' ) ? 1 : 0)
#define esMinuscula(x) (( (x) >= 'a' && (x) <= 'z' ) ? 1 : 0)
#define esMayuscula(x) (( (x) >= 'A' && (x) <= 'Z' ) ? 1 : 0)
#define esEsespacio(x) (( (x) == ' ' ) ? 1 : 0)
#define esComa(x) (( (x) == ',' ) ? 1 : 0)
#define aMayuscula(x) (( (x) >= 'a' && (x) <= 'z' ) ? (x-('a'-'A')) : x)
#define aMinuscula(x) (( (x) >= 'A' && (x) <= 'Z' ) ? (x+('a'-'A')) : x)

typedef struct {
    unsigned long DNI;
    char ApYNom[60];
    t_fecha fechaNac;
    char sexo [1];
    t_fecha fechaAfiliacion;
    char categoria [10];
    t_fecha UltCuotaPaga;
    char estado[1];
    t_fecha fechaBaja;
}Socio;

typedef struct {
    int dia;
    int mes;
    int anio;
}t_fecha;


void verificar_fecha(t_fecha* fecha);

#endif // SOCIOS_H_INCLUDED
