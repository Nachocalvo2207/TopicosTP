#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#define TAM_INICIAL 100

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

#endif // INDICE_H_INCLUDED
