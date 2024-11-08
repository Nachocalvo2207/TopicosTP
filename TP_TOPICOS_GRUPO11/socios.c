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
    char * auxEsc=s;
    char copia[60];
    int espacio=0, tienecoma,comalista=0,palabra=1;
    mistrcpy(copia,s);
    char* auxLec = copia;
    tienecoma= tiene_coma(s);
    if(esLetra(*auxLec)){
        *auxEsc=aMayuscula(*auxLec);
        auxLec++;
        auxEsc++;
    }else{
        return ERROR;
    }
    while(*auxLec){
        if(esLetra(*auxLec)&&palabra==1){
            *auxEsc=aMinuscula(*auxLec);
            auxLec++;
            auxEsc++;
        }else if(esEspacio(*auxLec)&&tienecoma==0&&comalista==0){
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
        else if(esEspacio(*auxLec)&&espacio==0){
            *auxEsc=' ';
            auxEsc++;
            auxLec++;
            espacio=1;
            palabra=0;
        }else if(esLetra(*auxLec)&&palabra==0){
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
    *auxEsc='\0';
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

    printf("\nFecha de nacimiento invalida");
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

    if(fecha->mes == 2) {
        if(((fecha->anio % 4 == 0 && fecha->anio % 100 != 0) || fecha->anio % 400 == 0)) {
            if(fecha->dia > 29)
                return ERR_FECHA;
        } else {  // Año no bisiesto
            if(fecha->dia > 28)
                return ERR_FECHA;
        }
    }

    return TODO_OK;
}

int validar_sexo(const char sexo)
{
    char sexo_mayus = aMayuscula(sexo);

    if( sexo_mayus != 'M' && sexo_mayus != 'F' && sexo_mayus != 'O' )
        return ERROR;

    return TODO_OK;
}

int validar_afliacion(Socio* soc,t_fecha* fechaProc)
{
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
    char categoria_mayus[50];

    int i;
    for (i = 0; categoria[i] != '\0' && i < sizeof(categoria_mayus) - 1; i++) {
        categoria_mayus[i] = aMayuscula(categoria[i]);
    }
    categoria_mayus[i] = '\0';
    if(strcmp(categoria_mayus, "MENOR") ||strcmp(categoria_mayus, "CADETE") || strcmp(categoria_mayus, "ADULTO") || strcmp(categoria_mayus, "VITALICIO")  || strcmp(categoria_mayus, "HONORARIO") || strcmp(categoria_mayus, "JUBILADO")  )
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

int validar_estado(char* estado)
{
    *estado = aMayuscula(*estado);
    if( *estado != 'A' && *estado != 'I' )
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

void archivo_variable_a_binario(FILE* pbinario, FILE* ptexto, FILE *perror,t_fecha* fecha){
    int cont = 0;
    char registro [TAM_REGISTRO];
    Socio socio;
    while(fgets(registro,TAM_REGISTRO,ptexto)){
        cargar_estructura(registro,&socio);
        // VALIDACIONES ACA, ENVIAR SOCIO YA CARGADO. CREAR FUNCIÓN CON TODAS LAS VALIDACIONES JUNTAS
        //SI TODO OK, ESCRIBE EN EL BINARIO
        if(validaciones(&socio,fecha)){
                fwrite(&socio,sizeof(Socio),1,pbinario);
                cont++;
        }
        else{
            //SI HAY ERROR, ESCRIBE EN TEXTO DE ERROR
            fprintf(perror,"%ld;%s;%d/%d/%d;%c;%d/%d/%d;%s;%d/%d/%d;%c;%d/%d/%d",socio.DNI,socio.ApYNom,socio.fechaNac.dia,socio.fechaNac.mes,
           socio.fechaNac.anio,socio.sexo,socio.fechaAfiliacion.dia,socio.fechaAfiliacion.mes,socio.fechaAfiliacion.anio,socio.categoria,
           socio.UltCuotaPaga.dia,socio.UltCuotaPaga.mes,socio.UltCuotaPaga.anio,socio.estado,socio.fechaBaja.dia,socio.fechaBaja.mes,
           socio.fechaBaja.anio);
        }
    }
    if(cont==0){
        printf("No se encontraron registros validos.\n");
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
    //Valido que todo sea correcto
    if(
    validar_DNI(socio->DNI)
    && validar_nacimiento(socio,fechaProc)
    && validar_sexo(socio->sexo)
    && validar_afliacion(socio,fechaProc)
    && validar_categoria(socio->categoria)
    && validar_ultima_cuota(socio,fechaProc)
    && validar_estado(&(socio->estado))
    && validar_fecha_de_baja(socio)
    )
        return TODO_OK;
    return ERROR;
}

int alta_socio(t_indice* indice,const char* path,t_fecha* fecha)
{
    FILE* arch = abrir_archivo(ARCH_BIN,"ab");
    if(!arch)
    {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }
    Socio socio;
    fseek(arch,0,SEEK_END);
    printf("Ingrese el DNI: ");
    scanf("%ld",&socio.DNI);
    fflush(stdin);
    t_reg_indice dni_buscar;
    dni_buscar.dni = socio.DNI;
    if(!validar_DNI(socio.DNI))
    {
        puts("DNI Invalido\n");
        return ERR_DNI;
    }

    int pos = indice_buscar(indice,&dni_buscar);
    if(pos)
    {
        printf("El dni ya se encuentra en el archivo\n");
    }else
    {
        printf("Ingrese el nombre y apellido: \n");
        scanf("%[^\n]",socio.ApYNom);
        fflush(stdin);
        printf("Ingrese la fecha de nacimiento: \n");
        printf("Dia: \n");
        scanf("%d",&socio.fechaNac.dia);
        fflush(stdin);
        printf("Mes: \n");
        scanf("%d",&socio.fechaNac.mes);
        fflush(stdin);
        printf("A%co: \n",164);
        scanf("%d",&socio.fechaNac.anio);
        fflush(stdin);
        printf("Ingrese el sexo: \n");
        scanf("%c",&socio.sexo);
        fflush(stdin);
        printf("Ingrese la fecha de afiliacion:\n");
        printf("Dia: \n");
        scanf("%d",&socio.fechaAfiliacion.dia);
        fflush(stdin);
        printf("Mes: \n");
        scanf("%d",&socio.fechaAfiliacion.mes);
        fflush(stdin);
        printf("A%co: \n",164);
        scanf("%d",&socio.fechaAfiliacion.anio);
        fflush(stdin);
        printf("Ingrese la categoria: \n");
        scanf("%s",socio.categoria);
        printf("Ingrese la fecha de la ultima cuota paga: \n");
        printf("Dia: \n");
        scanf("%d",&socio.UltCuotaPaga.dia);
        fflush(stdin);
        printf("Mes: \n");
        scanf("%d",&socio.UltCuotaPaga.mes);
        fflush(stdin);
        printf("A%co: \n",164);
        scanf("%d",&socio.UltCuotaPaga.anio);
        fflush(stdin);
        socio.estado = 'A';

        if(validaciones(&socio,fecha))
        {
            //Necesito que me agregue al final del archivo, necesito que agregue tamanio de socio

            fwrite(&socio,sizeof(Socio),1,arch);
            fclose(arch);
            indice_vaciar(indice);
            indice_crear(indice);
            indice_cargar(indice,ARCH_BIN);

        }else {
            printf("Los datos ingresados no son validos. \n");
        }
    }
    return TODO_OK;

}

void mostrar_menu_modificacion(char * letra){
fflush(stdin);
printf("Ingrese la letra del dato a modificar:\na. Apellido y Nombre \nb. Fecha de nacimiento\nc. Sexo\nd. Fecha de afiliaci%cn\ne. Categor%ca\nf. Fecha de %cltima cuota paga\ng. Salir\n",162,161,163);
//leer por teclado la opcion y convertirla a mayuscula
scanf("%c",letra);
*letra=aMayuscula(*letra);
/////validar que sea correcta la opcion
while(*letra<'A'||*letra>'G'){
    printf("Ingrese opci%cn v%clida: ",162,160);
    fflush(stdin);
    scanf("%c",letra);
    *letra=aMayuscula(*letra);
}
fflush(stdin);
}

int mostrar_informacion(t_indice *indice, const char *path){
    FILE* arch = abrir_archivo(ARCH_BIN,"r+b");
    if(!arch)
    {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }
    Socio socio;
    printf("Ingrese el DNI a consultar: ");
    scanf("%ld",&socio.DNI);
    t_reg_indice dni_buscar;
    dni_buscar.dni = socio.DNI;
    if(!validar_DNI(socio.DNI))
    {
        puts("DNI Invalido\n");
        return ERR_DNI;
    }
    int pos = indice_buscar(indice,&dni_buscar);
    if(!pos){
        puts("DNI no encontrado\n");
        return ERR_DNI;
    }else{
        fseek(arch, dni_buscar.nro_reg * sizeof(Socio), SEEK_SET);
        fread(&socio, sizeof(socio), 1, arch);
        printf("%ld %-30s %d/%d/%d \t%c \t%d/%d/%d \t%-10s \t%d/%d/%d\t\t%-6c\t%d/%d/%d\n", socio.DNI,socio.ApYNom,socio.fechaNac.dia,socio.fechaNac.mes,socio.fechaNac.anio,socio.sexo,
               socio.fechaAfiliacion.dia,socio.fechaAfiliacion.mes,socio.fechaAfiliacion.anio,socio.categoria,socio.UltCuotaPaga.dia,
               socio.UltCuotaPaga.mes,socio.UltCuotaPaga.anio,socio.estado,socio.fechaBaja.dia,socio.fechaBaja.mes,socio.fechaBaja.anio);
    }
    fclose(arch);
    return TODO_OK;
}

int modificar_socio(t_indice* indice,const char* path,t_fecha* fecha)
{
    FILE* arch = abrir_archivo(ARCH_BIN,"r+b");
    if(!arch)
    {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }
    Socio socio;

    printf("Ingrese el DNI: ");
    scanf("%ld",&socio.DNI);
    t_reg_indice dni_buscar;
    dni_buscar.dni = socio.DNI;
    if(!validar_DNI(socio.DNI))
    {
        puts("DNI Invalido\n");
        return ERR_DNI;
    }
    char opcion;

    if(indice_buscar(indice,&dni_buscar))
    {
        fseek(arch,dni_buscar.nro_reg * sizeof(Socio),SEEK_SET);
        fread(&socio,sizeof(Socio),1,arch);
        do{
            mostrar_menu_modificacion(&opcion);
            switch(opcion){
                case 'A':
                    printf("Ingrese el nombre y apellido: \n");
                    scanf("%s",socio.ApYNom);
                    normalizar_a_y_n(socio.ApYNom);
                    break;
                case 'B':
                    printf("Ingrese la fecha de nacimiento: \n");
                    printf("Dia: \n");
                    scanf("%d",&socio.fechaNac.dia);
                    fflush(stdin);
                    printf("Mes: \n");
                    scanf("%d",&socio.fechaNac.mes);
                    fflush(stdin);
                    printf("A%co: \n",164);
                    scanf("%d",&socio.fechaNac.anio);
                    validar_fecha(&socio.fechaNac);
                    fflush(stdin);
                    break;
                case 'C':
                    printf("Ingrese el sexo: \n");
                    scanf("%c",&socio.sexo);
                    fflush(stdin);
                    socio.sexo = aMayuscula(socio.sexo);
                    validar_sexo(socio.sexo);
                    break;
                case 'D':
                    printf("Ingrese la fecha de afiliacion:\n");
                    printf("Dia: \n");
                    scanf("%d",&socio.fechaAfiliacion.dia);
                    fflush(stdin);
                    printf("Mes: \n");
                    scanf("%d",&socio.fechaAfiliacion.mes);
                    fflush(stdin);
                    printf("A%co: \n",164);
                    scanf("%d",&socio.fechaAfiliacion.anio);
                    fflush(stdin);
                    validar_afliacion(&socio,fecha);
                    break;
                case 'E':
                    printf("Ingrese la categoria: \n");
                    scanf("%s",socio.categoria);
                    fflush(stdin);
                    validar_categoria(socio.categoria);
                    break;
                case 'F':
                    printf("Ingrese la fecha de la ultima cuota paga: \n");
                    printf("Dia: \n");
                    scanf("%d",&socio.UltCuotaPaga.dia);
                    fflush(stdin);
                    printf("Mes: \n");
                    scanf("%d",&socio.UltCuotaPaga.mes);
                    fflush(stdin);
                    printf("A%co: \n",164);
                    scanf("%d",&socio.UltCuotaPaga.anio);
                    fflush(stdin);
                    validar_ultima_cuota(&socio,fecha);
                    break;
            }
        }while(opcion!='G');
    }else{
        puts("DNI no encontrado\n");
        return ERR_DNI;
    }

    fseek(arch, dni_buscar.nro_reg * sizeof(Socio), SEEK_SET);
    fwrite(&socio,sizeof(Socio),1,arch);
    fclose(arch);
    indice_vaciar(indice);
    indice_crear(indice);
    indice_cargar(indice,ARCH_BIN);
    puts("Modificacion exitosa\n");
    return TODO_OK;

}


int mostrar_ordenado(t_indice *indice, const char *path) {
    FILE *arch = fopen(path, "rb");

    Socio socio;

    if (!arch) {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }
    printf("DNI\t Apellido y nombre\t\tFecha Nac.\tSexo\tFecha Afil.\tCategor%ca\tFecha %clt. cuota\tEstado\tFecha Baja\n",161,163);

    for (int i = 0; i < indice->tam; i++) {
        fseek(arch, indice->arr[i].nro_reg * sizeof(Socio), SEEK_SET);
        fread(&socio, sizeof(socio), 1, arch);
        printf("%ld %-30s %d/%d/%d \t%c \t%d/%d/%d \t%-10s \t%d/%d/%d\t\t%-6c\t%d/%d/%d\n", socio.DNI,socio.ApYNom,socio.fechaNac.dia,socio.fechaNac.mes,socio.fechaNac.anio,socio.sexo,
               socio.fechaAfiliacion.dia,socio.fechaAfiliacion.mes,socio.fechaAfiliacion.anio,socio.categoria,socio.UltCuotaPaga.dia,
               socio.UltCuotaPaga.mes,socio.UltCuotaPaga.anio,socio.estado,socio.fechaBaja.dia,socio.fechaBaja.mes,socio.fechaBaja.anio);
    }
    fclose(arch);
    return TODO_OK;
}

int baja_socio(t_indice *indice,const char *path){
FILE* arch = abrir_archivo(ARCH_BIN,"r+b");
    if(!arch)
    {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }
    Socio socio;
    printf("Ingrese el DNI a dar de baja: ");
    scanf("%ld",&socio.DNI);
    t_reg_indice dni_buscar;
    dni_buscar.dni = socio.DNI;
    if(!validar_DNI(socio.DNI))
    {
        puts("DNI invalido\n");
        return ERR_DNI;
    }
    int pos = indice_buscar(indice,&dni_buscar);
    if(!pos){
        puts("DNI no encontrado\n");
        return ERR_DNI;
    }else{
        fseek(arch, dni_buscar.nro_reg * sizeof(Socio), SEEK_SET);
        fread(&socio, sizeof(socio), 1, arch);
        socio.estado='I';
        fseek(arch, dni_buscar.nro_reg * sizeof(Socio), SEEK_SET);
        fwrite(&socio,sizeof(Socio),1,arch);
        fclose(arch);
        indice_vaciar(indice);
        indice_crear(indice);
        indice_cargar(indice,ARCH_BIN);
        puts("Baja exitosa.\n");
    }
    return TODO_OK;
}
