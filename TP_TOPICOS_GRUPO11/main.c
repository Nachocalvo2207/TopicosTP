#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include "indice.h"

//
//// Integrantes del grupo:
//    -----------------
//    Apellido: Rodriguez
//    Nombre: Iara Sol
//    DNI: 42247089
//
//    Apellido: Calvo
//    Nombre: Ignacio Facundo
//    DNI: 41162300


int main()
{   char opcion;
    t_fecha fec;

    printf("Ingrese la fecha de proceso:\n");
    printf("Dia:");
    scanf("%d",&fec.dia);
    printf("Mes:");
    scanf("%d",&fec.mes);
    printf("A%co:",164);
    scanf("%d",&fec.anio);

    while(!validar_fecha(&fec)){
       printf("Ingrese fecha v%clida:\n ",160);
       printf("Dia: ");
       scanf("%d",&fec.dia);
       printf("Mes: ");
       scanf("%d",&fec.mes);
       printf("A%co:",164);
       scanf("%d",&fec.anio);
    }

    FILE* archOrig = abrir_archivo(ARCH_TXT,"rt");
    FILE* archbinario = abrir_archivo(ARCH_BIN,"wb");
    FILE* archErrores = abrir_archivo(ARCH_ERRORES,"wt");

    archivo_variable_a_binario(archbinario,archOrig,archErrores,&fec);

    fclose(archOrig);
    fclose(archErrores);

    t_indice indice;

    indice_crear(&indice);
    fclose(archbinario);
    indice_cargar(&indice,ARCH_BIN);

do{
    mostrar_menu(&opcion);

    switch(opcion){
        case 'A':
            alta_socio(&indice,ARCH_BIN,&fec);
            break;
        case 'B':
            baja_socio(&indice, ARCH_BIN);
            break;
        case 'C':
        modificar_socio(&indice,ARCH_BIN,&fec);
            break;
        case 'D':
        mostrar_informacion(&indice, ARCH_BIN);
            break;
        case 'E':
        mostrar_ordenado(&indice,ARCH_BIN);
            break;
    }
}while(opcion!='F');

    return 0;
    indice_vaciar(&indice);
}
