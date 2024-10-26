#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#define TAM_INICIAL 100
#define NO_EXISTE_DNI 0
#define ERR_MEM 0
#define AGRANDAR 1.3

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
void indice_vaciar(t_indice *indice);
int indice_buscar(t_indice* indice, t_reg_indice* reg_indice);

int comparar_t_indice (void* a,void* b);
void ordenamiento(t_indice* indice);
void intercambio(void* a,void* b,size_t tam);


#endif // INDICE_H_INCLUDED

