#include "socios.h"

int normalizar_a_y_n(char * s){
    // gomez maira Luisa
    char * auxEsc=s;
    char copia[60];
    int espacio=0, tienecoma,comalista=0,palabra=1;
    mistrcpy(copia,s);
    char* auxLec = copia;
    tienecoma= tiene_coma(s);
    if(esLetra(*auxLec)){
        *auxEsc=aMayuscula(*auxLec); // G
        auxLec++;
        auxEsc++;
    }else{
        return ERROR;
    }
    while(*auxLec){
        if(esLetra(*auxLec)&&palabra==1){
            *auxEsc=aMinuscula(*auxLec); // Gomez
            auxLec++;
            auxEsc++;
        }else if(esEspacio(*auxLec)&&tienecoma==0&&comalista==0){ // Gomez,
            *auxEsc=',';
            auxEsc++;
            auxLec++;
            comalista=1;
        }else if(esComa(*auxLec)&&tienecoma==1&&comalista==0){
            *auxEsc=',';
            auxEsc++;
            auxLec++;
            comalista=1;
        }
        else if(esEspacio(*auxLec)&&espacio==0){  //Gomez,
            *auxEsc=' ';
            auxEsc++;
            auxLec++;
            espacio=1;
            palabra=0;
        }else if(esLetra(*auxLec)&&palabra==0){ //Gomez, M
            *auxEsc=aMayuscula(*auxLec);
            auxLec++;
            auxEsc++;
            palabra=1;
        }else if(esNumero(*auxLec)){
            return ERROR;
        }else{
            auxLec++;
            auxEsc++;
        }
    }
    *auxEsc='\0'; // Gomez, Maira Luisa\0
    return TODO_OK;
}

int tiene_coma(char * s){
    char* aux = s;
    int coma=0;
    while(*aux){
        if(esComa(*aux)){
            coma=1;
        }
        aux++;
    }
    return coma;
}

char* mistrcpy(char *s1, const char *s2){
    char *aux=s1;
    while(*s2){
        *aux=*s2;
        aux++;
        s2++;
    }
    *aux='\0';
    return s1;
}


int verificar_fecha(t_fecha* fecha)
{
    if(fecha->anio<1900 || fecha->anio>2021){
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
    if(fecha->mes==4 || fecha->mes==6 || fecha->mes==9 || fecha->mes==11){
        if(fecha->dia>30){
            printf("El dia ingresado no es valido\n");
            return ERR_FECHA;
        }
    }
    if(fecha->mes==2){
        if(fecha->anio%4==0 && fecha->anio%100!=0 || fecha->anio%400==0){
            if(fecha->dia>29){
                printf("El dia ingresado no es valido\n");
                return ERR_FECHA;
            }
        }else{
            if(fecha->dia>28){
                printf("El dia ingresado no es valido\n");
                return ERR_FECHA;
            }
        }
    }
    printf("La fecha ingresada es correcta\n");
    return TODO_OK;
}


int verificar_nacimiento(Socio* soc,t_fecha* fecha){
    verificar_fecha(fecha);
    if(soc->fechaNac.anio-fecha->anio<EDAD_MIN){
        return ERROR;
    }
    return TODO_OK;
}

int verificar_sexo(Socio* soc)
{
    if(soc->sexo != 'M' && soc->sexo != 'F' && soc->sexo != 'O')
        printf("Sexo no valido.");
        return ERROR;

    printf("Sexo validado");
    return TODO_OK;
}


