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