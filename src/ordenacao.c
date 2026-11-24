#include "pokemon.h"
#include "ordenacao.h"

void prepara_metricas(Metricas *ptr) {
    ptr->comparacoes = 0;
    ptr->movimentacoes = 0;
}

void troca(Pokemon *vetor, Metricas *ptr, int i, int j) {
    if (i != j) {
        Pokemon temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
        
        ptr->movimentacoes += 3;
    }
}

void bubbleSort(Pokemon *vetor, Metricas *ptr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            ptr->comparacoes++;
            if (vetor[j].pt_poder > vetor[j + 1].pt_poder) {
                troca(vetor, ptr, j, j + 1);
            }
        }
    }
}

// Função auxiliar que escolhe um pivô e separa os menores à esquerda e maiores à direita
int particiona(Pokemon *vetor, Metricas *ptr, int inicio, int fim) {
    int pivo = vetor[fim].pt_poder; // Escolhe o último elemento como pivô
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        ptr->comparacoes++; // Conta a cada iteração do for
        // Se o elemento atual for menor ou igual ao pivô, joga para a esquerda
        if (vetor[j].pt_poder <= pivo) {
            i++;
            troca(vetor, ptr, i, j);
        }
    }

    // Coloca o pivô na sua posição final correta
    troca(vetor, ptr, i + 1, fim);
    return i + 1;
}

// Função principal do Quicksort
void quickSort(Pokemon *vetor, Metricas *ptr, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particiona(vetor, ptr, inicio, fim);

        // Ordena recursivamente os elementos antes e depois do pivô
        quickSort(vetor, ptr, inicio, indicePivo - 1);
        quickSort(vetor, ptr, indicePivo + 1, fim);
    }
}