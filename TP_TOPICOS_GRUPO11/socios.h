#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define ERROR 3
#define ERR_FECHA 4
#define ERR_DNI 1

#define DNI_MIN 100000
#define DNI_MAX 100000000
#define EDAD_MIN 10
#define FECHA_MIN 1900
#define FECHA_MAX 2024

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
    char sexo;
    t_fecha fechaAfiliacion;
    char categoria [10];
    t_fecha UltCuotaPaga;
    char estado;
    t_fecha fechaBaja;
}Socio;

char* mistrcpy(char *s1, const char *s2);
int normalizar_a_y_n(char * s);
int tiene_coma(char * s);

int generar_archivo(Socio* soc);

int validar_DNI(int DNI);
int validar_fecha(t_fecha* fecha);
int validar_nacimiento(t_fecha* fechaNac,t_fecha* fechaProc);
int validar_sexo(char sexo);



#endif // SOCIOS_H_INCLUDED
