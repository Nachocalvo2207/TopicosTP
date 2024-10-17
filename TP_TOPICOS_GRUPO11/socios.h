#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define miisalpha(x) ((( (x) >= 'A'&& (x) <= 'Z' )||( (x) >= 'a' && (x) <='z' )) ? 1 : 0)
#define miisdigit(x) (( (x) >= '1' && (x) <= '9' ) ? 1 : 0)
#define miislower(x) (( (x) >= 'a' && (x) <= 'z' ) ? 1 : 0)
#define miisupper(x) (( (x) >= 'A' && (x) <= 'Z' ) ? 1 : 0)
#define miesespacio(x) (( (x) == ' ' ) ? 1 : 0)
#define miescoma(x) (( (x) == ',' ) ? 1 : 0)
#define mitoupper(x) (( (x) >= 'a' && (x) <= 'z' ) ? (x-('a'-'A')) : x)
#define mitolower(x) (( (x) >= 'A' && (x) <= 'Z' ) ? (x+('a'-'A')) : x)

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
