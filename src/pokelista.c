#include <stdio.h>
#include <stdlib.h>
#include "pokelista.h"

// Inicializa a lista encadeada criando a célula cabeça
int inicializa_lista(PokeLista *lista) {
    lista->primeiro = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    
    return 0;
}

// Insere um elemento no final da lista
int insere_lista(PokeLista *lista, Pokemon p) {
    lista->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->poke = p;
    lista->ultimo->prox = NULL;

    return 0;
}

int imprime_lista(PokeLista *lista) {
    if (lista->primeiro == lista->ultimo) {
        return 0;
    }
    Celula *atual = lista->primeiro->prox;

    while (atual != NULL) {
        printf("ID: %d | Nome: %s | Tipo: %s | Poder: %d\n", 
               atual->poke.id, atual->poke.nome, atual->poke.tipo, atual->poke.pt_poder);
        atual = atual->prox; 
    }

    return 1;
}

Pokemon* converte_encad_vetor(PokeLista *pokemons, int n) {
    Pokemon *vetor = (Pokemon *) malloc(n * sizeof(Pokemon));
    if (vetor == NULL) return NULL;

    Celula *no = pokemons->primeiro->prox;
    for (int i = 0; i < n && no != NULL; i++) {
        vetor[i] = no->poke;
        no = no->prox;
    }
    return vetor;
}

void imprime_vetor(Pokemon *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Nome: %s | Tipo: %s | Poder: %d\n", 
               vetor[i].id, vetor[i].nome, vetor[i].tipo, vetor[i].pt_poder);
    }
}