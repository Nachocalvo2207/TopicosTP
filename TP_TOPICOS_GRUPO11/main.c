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
    t_fecha fec = {22,7,2024};

    ///printf("Ingrese la fecha de proceso: DD/MM/AAAA: ");
    ///scanf("%d/%d/%d",&fec.dia,&fec.mes,&fec.anio);
    validar_fecha(&fec);

    Socio soc = {1234, "Juan Perez", {13, 1, 2020}, 'O', {1, 1, 2021}, "MENOR", {1, 1, 2024}, 'I', {1, 1, 2023}};
///    validar_DNI(soc.DNI);
///    validar_nacimiento(&soc.fechaNac,&fec);
///    validar_sexo(soc.sexo);
///    generar_socios
///    validar_afliacion(&soc,&fec);
///    validar_categoria(soc.categoria);
///    validar_ultima_cuota(&soc,&fec);
///    validar_estado(soc.estado);
    validar_fecha_de_baja(&soc);
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
