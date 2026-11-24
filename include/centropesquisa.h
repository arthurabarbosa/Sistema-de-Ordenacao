#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H

#include "pokelista.h"

// TAD que gerencia os Pokémons recuperados usando PokeLista
typedef struct {
    PokeLista recuperados;
} CentroPesquisa;

int inicializa_centro(CentroPesquisa *cpesq, int capacidade_max);
int insere_recuperado(CentroPesquisa *cpesq, Pokemon pk);
void imprime_recuperados(CentroPesquisa *cpesq);
void libera_centro(CentroPesquisa *cpesq);

#endif