#include <stdio.h>
#include <stdlib.h>
#include "socios.h"

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
///    abrir_archivo(ARCH_TXT,"r");

    printf("Ingrese la fecha de proceso:\n");
    printf("Dia:");
    scanf("%d",&fec.dia);
    printf("Mes:");
    scanf("%d",&fec.mes);
    printf("A%co:",164);
    scanf("%d",&fec.anio);

    while(!validar_fecha(&fec)){
       printf("Ingrese fecha v%clida: ",160);
       printf("Dia: ");
       scanf("%d",&fec.dia);
       printf("Mes: ");
       scanf("%d",&fec.mes);
       printf("Año: ");
       scanf("%d",&fec.anio);
    }
    Socio soc = {41162300, "Juan Perez", {13, 1, 1998}, 'O', {1, 1, 2021}, "MENOR", {1, 1, 2024}, 'A', {1, 1, 2023}};
    validaciones(&soc,&fec);

do{
    mostrar_menu(&opcion);
    switch(opcion){
        case 'A':

            break;
        case 'B':

            break;
        case 'C':

            break;
        case 'D':

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
