#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "indice.h"

#define ARCH_TXT "mi_ruta/socios_bien.txt"
#define ARCH_BIN "mi_ruta/socios.dat"
#define ARCH_ERRORES "mi_ruta/socios_errores.txt"

#define TODO_OK 1
#define ERROR 0
#define ERR_FECHA 0
#define ERR_DNI 0
#define SOCIO_ACTIVO 1
#define ERR_ARCH 0

#define DNI_MIN 100000
#define DNI_MAX 100000000
#define EDAD_MIN 10
#define FECHA_MIN 1900
#define FECHA_MAX 2024
#define TAM_REGISTRO 132

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

void mostrar_menu(char * letra);
int validar_DNI(const int DNI);
int validar_fecha(t_fecha* fecha);
int validar_nacimiento(Socio* soc, t_fecha* fechaProc);
int validar_sexo(const char sexo);
int validar_afliacion(Socio* soc,t_fecha* fechaProc);
int validar_ultima_cuota(Socio* soc,t_fecha* fechaProc);
int validar_estado(char* estado);
int validar_fecha_de_baja(Socio* soc);
int validaciones(Socio* socio,t_fecha* fechaProc);

void archivo_variable_a_binario(FILE* pbinario, FILE* ptexto, FILE *perror,t_fecha* fecha);
void cargar_estructura(const char* registro,Socio *socio);
void alta_socio(t_indice* indice,const char* path,t_fecha* fecha);
int mostrar_ordenado(t_indice *indice, const char *path);

FILE* abrir_archivo(const char* filename, const char* modo);

#endif // SOCIOS_H_INCLUDED
