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
//    Nombre: Ignacio Facund
//    DNI: 41162300


int main()
{
    ///Aca vamos a poner la fecha de inicio entiendo
//    t_fecha fec;
//    printf("Ingrese la fecha de proceso: DD/MM/AAAA: ");
//    scanf("%d/%d/%d",&fec.dia,&fec.mes,&fec.anio);
//    verificar_fecha(&fec);

    Socio soc = {12345678, "Juan Perez", {1, 1, 1990}, "M", {1, 1, 2020}, "Categoria1", {1, 1, 2021}, "A", {1, 1, 2022}};
    verificar_nacimiento(&soc, &soc.fechaAfiliacion);
    verificar_sexo(&soc);
    return 0;

}
