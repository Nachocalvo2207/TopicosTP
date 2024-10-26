#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#define TAM_INICIAL 100

#define ERR_MEM 0;

typedef struct {
    long dni;
    unsigned nro_reg;
}t_reg_indice;

typedef struct {
    t_reg_indice *arr;
    unsigned tam;
    unsigned max;
}t_indice;

void indice_crear(t_indice* indice);
int indice_cargar(t_indice* indice,const char* path);
int indice_lleno(t_indice* indice, unsigned tam);
int indice_vacio(const t_indice *indice);

int comparar_reg_indice (void* a,void* b);
void ordenamiento(void* indice,size_t ce,size_t tam,int (*cmp)(void*,void*));
void intercambio(void* a,void* b,size_t tam);


#endif // INDICE_H_INCLUDED

