#include <stdlib.h>
#include "centropesquisa.h"

int inicializa_centro(CentroPesquisa *cpesq, int capacidade_max) {
    cpesq->recuperados = (Pokemon*) malloc(capacidade_max * sizeof(Pokemon));
    cpesq->qtd_recuperados = 0;
    cpesq->capacidade = capacidade_max;
    return (cpesq->recuperados != NULL) ? 1 : 0;
}

int insere_recuperado(CentroPesquisa *cpesq, Pokemon pk) {
    if (cpesq->qtd_recuperados >= cpesq->capacidade) {
        return 0;
    }
    cpesq->recuperados[cpesq->qtd_recuperados] = pk;
    cpesq->qtd_recuperados++;
    return 1;
}

void libera_centro(CentroPesquisa *cpesq) {
    free(cpesq->recuperados);
    cpesq->recuperados = NULL;
}