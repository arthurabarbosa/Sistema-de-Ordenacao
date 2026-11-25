#include "centropesquisa.h"

// Inicializa a lista vetorial interna do centro
int inicializa_centro(CentroPesquisa *cpesq, int capacidade_max) {
    return inicializa_lista(&cpesq->recuperados, capacidade_max);
}

// Adiciona um Pokémon recuperado à lista do centro
int insere_recuperado(CentroPesquisa *cpesq, Pokemon pk) {
    return insere_lista(&cpesq->recuperados, pk);
}

// Imprime os Pokémons armazenados no centro
void imprime_recuperados(CentroPesquisa *cpesq) {
    imprime_lista(&cpesq->recuperados);
}

// Libera a memória alocada pelo centro
void libera_centro(CentroPesquisa *cpesq) {
    libera_lista(&cpesq->recuperados);
}

// Zera os contadores antes de iniciar uma ordenação
void prepara_metricas(Metricas *ptr) {
    ptr->comparacoes = 0;
    ptr->movimentacoes = 0;
}

// Troca dois elementos de posição e contabiliza 3 movimentações
void troca(Pokemon *vetor, Metricas *ptr, int i, int j) {
    if (i != j) {
        Pokemon temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        ptr->movimentacoes += 3;
    }
}

// Regra de ordenação: menor poder primeiro, empate desempata pelo menor número na Pokédex
int desempate(Pokemon a, Pokemon b) {
    if (a.pt_poder != b.pt_poder) {
        return a.pt_poder < b.pt_poder;
    }
    return a.numero_pokedex <= b.numero_pokedex;
}

// Ordenação por bolha (O(n²))
void bubbleSort(Pokemon *vetor, Metricas *ptr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            ptr->comparacoes++;
            if (!desempate(vetor[j], vetor[j + 1])) {
                troca(vetor, ptr, j, j + 1);
            }
        }
    }
}

// Particionamento de Lomuto: coloca o pivô na posição correta e menores à esquerda
int particiona(Pokemon *vetor, Metricas *ptr, int inicio, int fim) {
    Pokemon pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        ptr->comparacoes++;
        if (desempate(vetor[j], pivo)) {
            i++;
            troca(vetor, ptr, i, j);
        }
    }

    troca(vetor, ptr, i + 1, fim);
    return i + 1;
}

// Ordenação rápida recursiva (O(n log n) no caso médio)
void quickSort(Pokemon *vetor, Metricas *ptr, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particiona(vetor, ptr, inicio, fim);
        quickSort(vetor, ptr, inicio, indicePivo - 1);
        quickSort(vetor, ptr, indicePivo + 1, fim);
    }
}