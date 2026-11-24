#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H
#include "pokemon.h"

typedef struct {
    Pokemon *recuperados;
    int qtd_recuperados;
    int capacidade;
} CentroPesquisa;

int inicializa_centro(CentroPesquisa *cpesq, int capacidade_max);
int insere_recuperado(CentroPesquisa *cpesq, Pokemon pk);
void libera_centro(CentroPesquisa *cpesq);

#endif