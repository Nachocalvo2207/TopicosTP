#include "socios.h"
#include "indice.h"

void mostrar_menu(char * letra){
//Mostrar menu
fflush(stdin);
printf("Ingrese la letra de la operaci%cn a realizar:\na. Alta\nb. Baja\nc. Modificaci%cn\nd. Mostrar informaci%cn de un socio\ne. Listado de socios ordenados por clave (DNI)\nf. Salir\n",162,162,162);
//leer por teclado la opcion y convertirla a mayuscula
scanf("%c",letra);
*letra=aMayuscula(*letra);
/////validar que sea correcta la opci�n
while(*letra<'A'||*letra>'F'){
    printf("Ingrese opci%cn v%clida: ",162,160);
    fflush(stdin);
    scanf("%c",letra);
    *letra=aMayuscula(*letra);
}
fflush(stdin);
}

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



int validar_nacimiento(Socio* soc, t_fecha* fechaProc)
{
    if ( validar_fecha(&soc->fechaNac)  && validar_fecha(fechaProc) )
    {
        if ((soc->fechaNac.anio < fechaProc->anio - EDAD_MIN) ||
            (soc->fechaNac.anio == fechaProc->anio - EDAD_MIN && soc->fechaNac.mes < fechaProc->mes) ||
            (soc->fechaNac.anio == fechaProc->anio - EDAD_MIN && soc->fechaNac.mes == fechaProc->mes && soc->fechaNac.dia <= fechaProc->dia))

            return TODO_OK;

    }

    printf("Fecha de nacimiento invalida");
   return ERROR;
}

int validar_DNI(const int DNI)
{
    if(DNI<DNI_MIN || DNI>DNI_MAX)
        return ERR_DNI;

    return TODO_OK;
}

int validar_fecha(t_fecha* fecha)
{
    if(fecha->anio<FECHA_MIN || fecha->anio>FECHA_MAX)
        return ERR_FECHA;


    if(fecha->mes < 1 || fecha->mes > 12)
        return ERR_FECHA;

    if(fecha->dia<1 || fecha->dia>31)
        return ERR_FECHA;


    if((fecha->mes==4 || fecha->mes==6 || fecha->mes==9 || fecha->mes==11) && fecha->dia>30)
            return ERR_FECHA;

    if(fecha->mes==2){
        if(( (fecha->anio%4==0 && fecha->anio%100!=0 ) || fecha->anio%400==0) && fecha->dia>29)
            return ERR_FECHA;

        }else if(fecha->dia>28){
            return ERR_FECHA;
            }

    return TODO_OK;
}

int validar_sexo(const char sexo)
{
    if( sexo != 'M' && sexo != 'F' && sexo != 'O' )
        return ERROR;

    return TODO_OK;
}

int validar_afliacion(Socio* soc,t_fecha* fechaProc)
{
    /// Validar si las fechas de afiliacion y procesamiento son validas
    if (validar_fecha(&soc->fechaAfiliacion) && validar_fecha(fechaProc) )
    {
        /// Comprobar que la fecha de afiliacion es <= fecha de procesamiento
        if ((soc->fechaAfiliacion.anio < fechaProc->anio) ||
            (soc->fechaAfiliacion.anio == fechaProc->anio && soc->fechaAfiliacion.mes < fechaProc->mes) ||
            (soc->fechaAfiliacion.anio == fechaProc->anio && soc->fechaAfiliacion.mes == fechaProc->mes && soc->fechaAfiliacion.dia <= fechaProc->dia))
        {
            /// Comprobar que la fecha de afiliacion es mayor que la fecha de nacimiento
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
    if(strcmp(categoria, "MENOR") ||strcmp(categoria, "CADETE") || strcmp(categoria, "ADULTO") || strcmp(categoria, "VITALICIO")  || strcmp(categoria, "HONORARIO") || strcmp(categoria, "JUBILADO")  )
        return TODO_OK;

    return ERROR;
}

int validar_ultima_cuota(Socio* soc, t_fecha* fechaProc)
{
    /// Validar si las fechas son correctas
    if (!validar_fecha(&soc->UltCuotaPaga) )
        {
            soc->UltCuotaPaga.dia = fechaProc->dia;
            soc->UltCuotaPaga.mes = fechaProc->mes;
            soc->UltCuotaPaga.anio = fechaProc->anio;

        }
    if ( validar_fecha(fechaProc) )
    {
        /// Validar que la fecha de la última cuota <= fecha de procesamiento
        if ((soc->UltCuotaPaga.anio < fechaProc->anio) ||
            (soc->UltCuotaPaga.anio == fechaProc->anio && soc->UltCuotaPaga.mes < fechaProc->mes) ||
            (soc->UltCuotaPaga.anio == fechaProc->anio && soc->UltCuotaPaga.mes == fechaProc->mes && soc->UltCuotaPaga.dia <= fechaProc->dia))
        {
            /// Validar que la fecha de la última cuota >= fecha de afiliación
            if ((soc->UltCuotaPaga.anio > soc->fechaAfiliacion.anio) ||
                (soc->UltCuotaPaga.anio == soc->fechaAfiliacion.anio && soc->UltCuotaPaga.mes > soc->fechaAfiliacion.mes) ||
                (soc->UltCuotaPaga.anio == soc->fechaAfiliacion.anio && soc->UltCuotaPaga.mes == soc->fechaAfiliacion.mes && soc->UltCuotaPaga.dia >= soc->fechaAfiliacion.dia))
                    return TODO_OK; // La fecha de la última cuota es válida

        }
    }

    return ERROR; // Fecha inválida
}

int validar_estado(const char estado)
{
    if( estado != 'A' && estado != 'I' )
    {
        return ERROR;
    }

    return TODO_OK;
}

int validar_fecha_de_baja(Socio* soc)
{

   ///Valido que el estado sea A
    if( soc->estado == 'A') {
        soc->fechaBaja.dia = 1;
        soc->fechaBaja.mes = 1;
        soc->fechaBaja.anio = 1900;
        return SOCIO_ACTIVO;
    }

    ///Valido la fecha de baja
    if(!validar_fecha(&soc->fechaBaja))
        return ERR_FECHA;

   ///Chequeo que el socio este INACTIVO
    if( soc->estado == 'I')
    {
        /// Comparar que fecha de baja sea mayor a fecha de afiliación
        if ((soc->fechaBaja.anio > soc->fechaAfiliacion.anio) ||
            (soc->fechaBaja.anio == soc->fechaAfiliacion.anio && soc->fechaBaja.mes > soc->fechaAfiliacion.mes) ||
            (soc->fechaBaja.anio == soc->fechaAfiliacion.anio && soc->fechaBaja.mes == soc->fechaAfiliacion.mes && soc->fechaBaja.dia > soc->fechaAfiliacion.dia))
        {

            /// Comparar que fecha de baja sea mayor a fecha de nacimiento
            if ((soc->fechaBaja.anio > soc->fechaNac.anio) ||
                (soc->fechaBaja.anio == soc->fechaNac.anio && soc->fechaBaja.mes > soc->fechaNac.mes) ||
                (soc->fechaBaja.anio == soc->fechaNac.anio && soc->fechaBaja.mes == soc->fechaNac.mes && soc->fechaBaja.dia > soc->fechaNac.dia))

                return TODO_OK; // La fecha de baja es válida

        }

    }
   return TODO_OK;
}

FILE* abrir_archivo(const char* filename, const char* modo)
{
    FILE* archivo = fopen(filename, modo);
    if (!archivo)
    {
        printf("Error al abrir el archivo %s\n", filename);
        fclose(archivo);
    }
    return archivo;
}
///30567845;Lopez, Juan Carlos;1990-05-12;M;2015-08-20;ADULTO;2023-09-15;A;
void archivo_variable_a_binario(FILE* pbinario, FILE* ptexto, FILE *perror){
    char registro [TAM_REGISTRO];
    Socio socio;
    t_fecha fecha;
    while(fgets(registro,TAM_REGISTRO,ptexto)){
        cargar_estructura(registro,&socio);
        // VALIDACIONES ACA, ENVIAR SOCIO YA CARGADO. CREAR FUNCIÓN CON TODAS LAS VALIDACIONES JUNTAS
        //SI TODO OK, ESCRIBE EN EL BINARIO
        if(validaciones(&socio,&fecha)){
                fwrite(&socio,sizeof(Socio),1,pbinario);
        }
        else{
            //SI HAY ERROR, ESCRIBE EN TEXTO DE ERROR
            fprintf(perror,"%ld;%s;%d/%d/%d;%c;%d/%d/%d;%s;%d/%d/%d;%c;%d/%d/%d",socio.DNI,socio.ApYNom,socio.fechaNac.dia,socio.fechaNac.mes,
           socio.fechaNac.anio,socio.sexo,socio.fechaAfiliacion.dia,socio.fechaAfiliacion.mes,socio.fechaAfiliacion.anio,socio.categoria,
           socio.UltCuotaPaga.dia,socio.UltCuotaPaga.mes,socio.UltCuotaPaga.anio,socio.estado,socio.fechaBaja.dia,socio.fechaBaja.mes,
           socio.fechaBaja.anio);
        }
    }
}

void cargar_estructura(const char* registro,Socio *socio){
    sscanf(registro,"%ld;%[^;];%d/%d/%d;%c;%d/%d/%d;%[^;];%d/%d/%d;%c;%d/%d/%d",&socio->DNI,socio->ApYNom,&socio->fechaNac.dia,&socio->fechaNac.mes,
           &socio->fechaNac.anio,&socio->sexo,&socio->fechaAfiliacion.dia,&socio->fechaAfiliacion.mes,&socio->fechaAfiliacion.anio,socio->categoria,
           &socio->UltCuotaPaga.dia,&socio->UltCuotaPaga.mes,&socio->UltCuotaPaga.anio,&socio->estado,&socio->fechaBaja.dia,&socio->fechaBaja.mes,
           &socio->fechaBaja.anio);
}

int validaciones(Socio* socio, t_fecha* fechaProc)
{
//UNIR TODAS LAS VALIDACIONES ACÁ.
    ///Valido que todo sea correcto
    if(
    validar_DNI(socio->DNI)
    && validar_nacimiento(socio,fechaProc)
    && validar_sexo(socio->sexo)
    && validar_afliacion(socio,fechaProc)
    && validar_categoria(socio->categoria)
    && validar_ultima_cuota(socio,fechaProc)
    && validar_estado(socio->estado)
    && validar_fecha_de_baja(socio)
    )
        return TODO_OK;
    return ERROR;
}
