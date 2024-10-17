#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define ERROR 3
#define Edad_Minima 10

#define esLetra(x) ((( (x) >= 'A'&& (x) <= 'Z' )||( (x) >= 'a' && (x) <='z' )) ? 1 : 0)
#define esNumero(x) (( (x) >= '1' && (x) <= '9' ) ? 1 : 0)
#define esMinuscula(x) (( (x) >= 'a' && (x) <= 'z' ) ? 1 : 0)
#define esMayuscula(x) (( (x) >= 'A' && (x) <= 'Z' ) ? 1 : 0)
#define esEspacio(x) (( (x) == ' ' ) ? 1 : 0)
#define esComa(x) (( (x) == ',' ) ? 1 : 0)
#define aMayuscula(x) (( (x) >= 'a' && (x) <= 'z' ) ? (x-('a'-'A')) : x)
#define aMinuscula(x) (( (x) >= 'A' && (x) <= 'Z' ) ? (x+('a'-'A')) : x)

typedef struct {
    int dia;
    int mes;
    int anio;
}t_fecha;

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

void crear_archivo(const char* arch);
void verificar_fecha(t_fecha* fecha);
char* mistrcpy(char *s1, const char *s2);
int normalizar_a_y_n(char * s);
int tiene_coma(char * s);


#endif // SOCIOS_H_INCLUDED
