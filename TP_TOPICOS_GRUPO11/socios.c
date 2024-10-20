#include "socios.h"

//int normalizar_a_y_n(char * s){
//    // gomez maira Luisa
//    char * auxEsc=s;
//    char copia[60];
//    int espacio=0, tienecoma,comalista=0,palabra=1;
//    mistrcpy(copia,s);
//    char* auxLec = copia;
//    tienecoma= tiene_coma(s);
//    if(esLetra(*auxLec)){
//        *auxEsc=aMayuscula(*auxLec); // G
//        auxLec++;
//        auxEsc++;
//    }else{
//        return ERROR;
//    }
//    while(*auxLec){
//        if(esLetra(*auxLec)&&palabra==1){
//            *auxEsc=aMinuscula(*auxLec); // Gomez
//            auxLec++;
//            auxEsc++;
//        }else if(esEspacio(*auxLec)&&tienecoma==0&&comalista==0){ // Gomez,
//            *auxEsc=',';
//            auxEsc++;
//            auxLec++;
//            comalista=1;
//        }else if(esComa(*auxLec)&&tienecoma==1&&comalista==0){
//            *auxEsc=',';
//            auxEsc++;
//            auxLec++;
//            comalista=1;
//        }
//        else if(esEspacio(*auxLec)&&espacio==0){  //Gomez,
//            *auxEsc=' ';
//            auxEsc++;
//            auxLec++;
//            espacio=1;
//            palabra=0;
//        }else if(esLetra(*auxLec)&&palabra==0){ //Gomez, M
//            *auxEsc=aMayuscula(*auxLec);
//            auxLec++;
//            auxEsc++;
//            palabra=1;
//        }else if(esNumero(*auxLec)){
//            return ERROR;
//        }else{
//            auxLec++;
//            auxEsc++;
//        }
//    }
//    *auxEsc='\0'; // Gomez, Maira Luisa\0
//    return TODO_OK;
//}
//
//int tiene_coma(char * s){
//    char* aux = s;
//    int coma=0;
//    while(*aux){
//        if(esComa(*aux)){
//            coma=1;
//        }
//        aux++;
//    }
//    return coma;
//}
//
//char* mistrcpy(char *s1, const char *s2){
//    char *aux=s1;
//    while(*s2){
//        *aux=*s2;
//        aux++;
//        s2++;
//    }
//    *aux='\0';
//    return s1;
//}


int validar_fecha(t_fecha* fecha)
{
    if(fecha->anio<FECHA_MIN || fecha->anio>FECHA_MAX){
        printf("El anio ingresado no es valido\n");
        return ERR_FECHA;
    }
    if(fecha->mes<1 || fecha->mes>12){
        printf("El mes ingresado no es valido\n");
        return ERR_FECHA;
    }
    if(fecha->dia<1 || fecha->dia>31){
        printf("El dia ingresado no es valido\n");
        return ERR_FECHA;
    }
    if((fecha->mes==4 || fecha->mes==6 || fecha->mes==9 || fecha->mes==11) && fecha->dia>30){
            printf("El dia ingresado no es valido\n");
            return ERR_FECHA;
    }
    if(fecha->mes==2){
        if((fecha->anio%4==0 && fecha->anio%100!=0 || fecha->anio%400==0) && fecha->dia>29){
                printf("El dia ingresado no es valido\n");
                return ERR_FECHA;
        }else if(fecha->dia>28){
                printf("El dia ingresado no es valido\n");
                return ERR_FECHA;
        }
    }
    printf("La fecha ingresada es correcta\n");
    return TODO_OK;
}


int validar_DNI(const int DNI)
{
    if(DNI < DNI_MIN || DNI > DNI_MAX)
        return ERR_DNI;

    return TODO_OK;
}

int validar_nacimiento(t_fecha* fechaNac,t_fecha* fechaProc)
{
                    /// VALIDO SI LA FECHA ES VALIDA                                                VALIDO SI LA FECHA DE NAC ES 10 MAYOR A FECHA PROCESO
    if(( validar_fecha(fechaNac) == 0 ||validar_fecha(fechaProc) == 0 ) && ( (fechaProc->anio - fechaNac->anio > EDAD_MIN) ||(fechaProc->anio - fechaNac->anio == EDAD_MIN && fechaProc->mes > fechaNac->mes) ||(fechaProc->anio - fechaNac->anio == EDAD_MIN && fechaProc->mes == fechaNac->mes && fechaProc->dia > fechaNac->dia) ) )
        return TODO_OK;
    return TODO_OK;
    ;

   return TODO_OK;
}



int validar_sexo(const char sexo)
{
    if( sexo != 'M' && sexo != 'F' && sexo != 'O' )
    {
        printf("Sexo no valido.");
        return ERROR;
    }

    printf("Sexo validado");
    return TODO_OK;
}

int validar_afliacion(Socio* soc,t_fecha* fechaProc)
{
    /// Validar si las fechas de afiliaci�n y procesamiento son v�lidas
    if (validar_fecha(&soc->fechaAfiliacion) == 0 && validar_fecha(fechaProc) == 0)
    {
        /// Comprobar que la fecha de afiliaci�n es <= fecha de procesamiento
        if ((soc->fechaAfiliacion.anio < fechaProc->anio) ||
            (soc->fechaAfiliacion.anio == fechaProc->anio && soc->fechaAfiliacion.mes < fechaProc->mes) ||
            (soc->fechaAfiliacion.anio == fechaProc->anio && soc->fechaAfiliacion.mes == fechaProc->mes && soc->fechaAfiliacion.dia <= fechaProc->dia))
        {
            /// Comprobar que la fecha de afiliaci�n es mayor que la fecha de nacimiento
            if ((soc->fechaAfiliacion.anio > soc->fechaNac.anio) ||
                (soc->fechaAfiliacion.anio == soc->fechaNac.anio && soc->fechaAfiliacion.mes > soc->fechaNac.mes) ||
                (soc->fechaAfiliacion.anio == soc->fechaNac.anio && soc->fechaAfiliacion.mes == soc->fechaNac.mes && soc->fechaAfiliacion.dia > soc->fechaNac.dia))
                    return TODO_OK; // Afiliaci�n v�lida

        }
    }

    return ERR_FECHA; // Afiliaci�n inv�lida
}

int validar_categoria(const char* categoria)
{
    if(strcmp(categoria, "MENOR") == 0 ||strcmp(categoria, "CADETE") == 0 || strcmp(categoria, "ADULTO") == 0 || strcmp(categoria, "VITALICIO") == 0 || strcmp(categoria, "HONORARIO") == 0 || strcmp(categoria, "JUBILADO") == 0 )
    {
        printf("Categoria valida");
        return TODO_OK;
    }

    printf("Cat invalida");
    return ERROR;
}

int generar_archivo(Socio* soc);

