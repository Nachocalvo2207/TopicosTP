#include "socios.h"

int normalizar_a_y_n(char * s){
    char * auxEsc=s;
    char auxLec[60];
    strcpy(auxLec,s);
    *auxEsc
    while(*auxLec){
        while()
    }

    return TODO_OK;
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


void verificar_fecha(t_fecha* fecha)
{
    while(fecha->anio < 1900 || fecha->anio > 2024)
    {
        printf("El anio ingresado no es valido. Ingreselo nuevamente: ");
        scanf("%d", &fecha->anio);
    }
    while (fecha->mes < 1 || fecha->mes > 12)
    {
        printf("El mes ingresado no es valido. Ingreselo nuevamente: ");
        scanf("%d", &fecha->mes);
    }
    if(fecha->mes == 2)
        {
            {
                if(fecha->anio % 4 == 0 && fecha->anio % 100 != 0 || fecha->anio % 400 == 0)
                {
                    while(fecha->dia < 1 || fecha->dia > 29)
                    {
                        printf("El dia ingresado no es valido. Ingreselo nuevamente: ");
                        scanf("%d", &fecha->dia);
                    }
                }
                else
                {
                    while(fecha->dia < 1 || fecha->dia > 28)
                    {
                        printf("El dia ingresado no es valido. Ingreselo nuevamente: ");
                        scanf("%d", &fecha->dia);
                    }
                }
            }
        }
    else if(fecha->mes == 4 || fecha->mes == 6 || fecha->mes == 9 || fecha->mes == 11)
        {
            while(fecha->dia < 1 || fecha->dia > 30)
            {
                printf("El dia ingresado no es valido. Ingreselo nuevamente: ");
                scanf("%d", &fecha->dia);
            }
        }
    else
        {
            while(fecha->dia < 1 || fecha->dia > 31)
            {
                printf("El dia ingresado no es valido. Ingreselo nuevamente: ");
                scanf("%d", &fecha->dia);
            }
        }
}
