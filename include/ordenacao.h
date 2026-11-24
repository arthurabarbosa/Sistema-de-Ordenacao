#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "pokemon.h"

typedef struct {
    long long comparacoes;
    long long movimentacoes;
} Metricas;

void prepara_metricas(Metricas *ptr);
void troca(Pokemon *vetor, Metricas *ptr, int i, int j);
void bubbleSort(Pokemon *vetor, Metricas *ptr, int n);
int particiona(Pokemon *vetor, Metricas *ptr, int inicio, int fim);
void quickSort(Pokemon *vetor, Metricas *ptr, int inicio, int fim);

#endif