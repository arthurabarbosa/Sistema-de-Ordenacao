#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H

#include "pokelista.h"

// TAD que gerencia os Pokémons recuperados usando PokeLista
typedef struct {
    PokeLista recuperados;
} CentroPesquisa;

// Armazena contadores de desempenho dos algoritmos
typedef struct {
    long long comparacoes;
    long long movimentacoes;
} Metricas;

int inicializa_centro(CentroPesquisa *cpesq, int capacidade_max);
int insere_recuperado(CentroPesquisa *cpesq, Pokemon pk);
void imprime_recuperados(CentroPesquisa *cpesq);
void libera_centro(CentroPesquisa *cpesq);

void prepara_metricas(Metricas *ptr);
void troca(Pokemon *vetor, Metricas *ptr, int i, int j);
void bubbleSort(Pokemon *vetor, Metricas *ptr, int n);
int particiona(Pokemon *vetor, Metricas *ptr, int inicio, int fim);
void quickSort(Pokemon *vetor, Metricas *ptr, int inicio, int fim);

#endif