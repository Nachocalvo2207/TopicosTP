#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct {
    unsigned long DNI;
    char ApYNom[60];
    t_fecha fechaNac;
    char sexo [1];
    t_fecha fechaAfiliacion;
    char categoria [10];
    t_fecha UltCuotaPaga;
    char estado[1];
    t_fecha fechaBaja;
}Socio;

typedef struct {
    int dia;
    int mes;
    int anio;
}t_fecha;


#endif // SOCIOS_H_INCLUDED
