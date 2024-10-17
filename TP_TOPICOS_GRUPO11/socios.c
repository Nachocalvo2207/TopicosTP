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
}



void crear_archivo(const char* arch) {
    FILE *arch = fopen(arch, "wt");
    if (!arch) {
        printf("Error de escritura del archivo.\n");
        return;
    }
    fclose(arch);
}
void verificar_fecha_nac(t_fecha* fecha) {
    // Obtengo fecha actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fopen("error_arch.txt", "rt");
    
    // Calculo la fecha mínima permitida
    t_fecha fecha_minima;
    fecha_minima.anio = tm.tm_year + 1900 - 10;
    fecha_minima.mes = tm.tm_mon + 1;
    fecha_minima.dia = tm.tm_mday;

    // Chequear si tiene al menos 10 años
    if (fecha->anio > fecha_minima.anio ||
        (fecha->anio == fecha_minima.anio && fecha->mes > fecha_minima.mes) ||
        (fecha->anio == fecha_minima.anio && fecha->mes == fecha_minima.mes && fecha->dia > fecha_minima.dia)) {
        printf("La fecha de nacimiento debe ser al menos 10 años atrás.\n");
        ///enviar al arrchivo error_arch.txt

    }
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


void verificar_sexo(Socio soc)
{
    while(soc->sexo != 'M' && soc->sexo != 'F')
    {
        printf("El sexo ingresado no es valido. Ingreselo nuevamente: ");
        scanf("%c", &soc->sexo);
    }
}
