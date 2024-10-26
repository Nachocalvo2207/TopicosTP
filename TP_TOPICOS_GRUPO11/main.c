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
    ///Aca vamos a poner la fecha de inicio entiendo
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
    t_reg_indice reg_indice;

    reg_indice.dni=30567845;

    indice_crear(&indice);
    fclose(archbinario);
    indice_cargar(&indice,ARCH_BIN);
    printf("%d",indice_buscar(&indice,&reg_indice));
do{
    mostrar_menu(&opcion);

    switch(opcion){
        case 'A':
            alta_socio(&indice,ARCH_BIN,&fec);
            break;
        case 'B':
///            baja_socio(&indice,ARCH_BIN,&fec);
            break;
        case 'C':
            modificar_socio(&indice,ARCH_BIN,&fec);
            break;
        case 'D':

            break;
        case 'E':
        mostrar_ordenado(&indice,ARCH_BIN);
            break;
    }
}while(opcion!='F');

    return 0;

}


///Para modificar recorro el archivo:
///lees un socio
///si NO es el socio que buscas
///Sigue recorriendo


/// Ingresar datos nuevo()
/// Validar Socio()
///fseek(SEEK_CUR,-sizeof(Socio))
/// Guardo Socio (no tiene que ser funcion, casi seguro) ---> r+b
/// aca para de recorrer ak return

///Si no encuentra nada, avisa
