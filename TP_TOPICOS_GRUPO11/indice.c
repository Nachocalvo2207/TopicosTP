#include "socios.h"
#include "indice.h"

void indice_crear(t_indice* indice)
{
    indice->arr = (t_reg_indice *) malloc(TAM_INICIAL * sizeof(t_reg_indice));
    if(!indice->arr)
    {
        printf("Error de reserva de memoria\n");
        exit(1);
    }
    indice->max = TAM_INICIAL;
    indice->tam = 0;
}

/* int indice_buscar (const t_indice*, t_reg_indice* reg_indice): si el dni existe deja el registro en reg_ind;
 */


int indice_cargar(t_indice* indice,const char* path)
{
    FILE* arch = fopen(path,"rb");
    int ce = 0;
    Socio socio;
    fread(&socio,sizeof(Socio),1,arch);

    while(!feof(arch))
    {
        if(indice->max == indice->tam)
            indice_lleno(indice,sizeof(t_reg_indice));

        if(socio.estado == 'A')
        {
        indice->arr[ce].dni = socio.DNI;
        indice->arr[ce].nro_reg = ce;
        ce++;
        }

        fread(&socio,sizeof(Socio),1,arch);
    }
    indice->tam = ce;

    ordenamiento(indice,ce,sizeof(t_reg_indice),comparar_reg_indice);
    fclose(arch);
    return TODO_OK;

}

int indice_vacio(const t_indice *indice)
{
    if(indice->tam == 0)
        printf("El indice se encuentra vacio\n");

    return TODO_OK;
}


//A esto agregar que se debe modificar en el .bin
int indice_eliminar(t_indice* indice, t_reg_indice reg_indice)
{
    int i;
    for(i=0;i<indice->tam;i++)
    {
        if(indice->arr[i].dni == reg_indice.dni)
        {
            for(int j=i;j<indice->tam-1;j++)
            {
                indice->arr[j] = indice->arr[j+1];
            }
            indice->tam--;
            return TODO_OK;
        }
    }

    return ERR_DNI;
}



int indice_buscar(const t_indice* indice, t_reg_indice* reg_indice)
{
    for(int i=0;i<indice->tam;i++)
    {
        if(indice->arr[i].dni == reg_indice->dni)
        {
            reg_indice->nro_reg = indice->arr[i].nro_reg;
            return i;
        }
    }

    return NO_EXISTE_DNI;
}

void ordenamiento(void* indice,size_t ce,size_t tam,int (*cmp)(void*,void*))
{
    int i,j;

    for(i=0;i<ce-1;i++)
        for(j=0;j<ce-i-1;j++)
            if(cmp(indice+j*tam,indice+(j+1)*tam)>0)
                intercambio(indice+j*tam,indice+(j+1)*tam,tam);

}

int comparar_reg_indice (void* a,void* b)
{
    t_reg_indice* aDNI = (t_reg_indice*)a;
    t_reg_indice* bDNI = (t_reg_indice*)b;

    return aDNI->dni - bDNI->dni;
}

void intercambio(void* a,void* b,size_t tam)
{
    void* aux = malloc(tam);
    if(!aux)
    {
        printf("Error de reserva de memoria\n");
        exit(1);
    }

    memcpy(aux,a,tam);
    memcpy(a,b,tam);
    memcpy(b,aux,tam);

    free(aux);
}

int indice_lleno(t_indice* indice, unsigned tam)
{
    indice->arr = (t_reg_indice *) realloc(indice->arr,indice->tam * 1.3 * sizeof(t_reg_indice));
    if(!indice->arr)
    {
        printf("Error de reserva de memoria\n");
        return ERR_MEM;
    }
    indice->tam *= 1.3;

    return TODO_OK;
}

/* Modificación: Si existe la clave que se quiere modificar y el estado del registro no es ‘I’, actualizar la información deseada. Si se detectan errores, se ignora todo lo ingresado. */
/* 
int modificar_socio(t_indice* indice)
{
    FILE* arch = fopen(ARCH_BIN,"r+b");
    if(!arch)
    {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }

    Socio socio;
    t_reg_indice reg_indice;
    printf("\n Ingrese el DNI del socio a modificar: \n");
    scanf("%ld",&reg_indice.dni);
    if(indice_buscar(indice,&reg_indice) == NO_EXISTE_DNI)
    {
        printf("El DNI ingresado no existe\n");
        return ERR_DNI;
    }

    fread(&socio,sizeof(Socio),1,arch);

    /*modifico: 
    ayn
    fecha nac
    sexo
    fecha afil
    categoria
    fecha ult cuota paga 
    while (!feof(arch))
    {
        
    }

    


} */
int mostrar_ordenado(t_indice *indice, const char *path) {
    FILE *arch = fopen(path, "rb");

    Socio socio;

    if (!arch) {
        printf("Error de lectura de archivo\n");
        return ERR_ARCH;
    }
    printf("DNI\tApellido y nombre\tFecha Nac.\tSexo\tFecha Afil.\tCategor%ca\tFecha %clt. cuota paga\tEstado\tFecha Baja\n",161,163);

    for (int i = 0; i < indice->tam; i++) {
        fseek(arch, indice->arr[i].nro_reg * sizeof(Socio), SEEK_SET);
        fread(&socio, sizeof(socio), 1, arch);
        printf("%ld %s  %d/%d/%d %c %d/%d/%d %s %d/%d/%d %c %d/%d/%d\n", socio.DNI,socio.ApYNom,socio.fechaNac.dia,socio.fechaNac.mes,socio.fechaNac.anio,socio.sexo,
               socio.fechaAfiliacion.dia,socio.fechaAfiliacion.mes,socio.fechaAfiliacion.anio,socio.categoria,socio.UltCuotaPaga.dia,
               socio.UltCuotaPaga.mes,socio.UltCuotaPaga.anio,socio.estado,socio.fechaBaja.dia,socio.fechaBaja.mes,socio.fechaBaja.anio);
    }
    fclose(arch);
    return TODO_OK;
}


