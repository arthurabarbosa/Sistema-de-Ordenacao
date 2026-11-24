#include <stdio.h>
#include <stdlib.h>
#include "pokelista.h"

// Aloca o vetor da lista e zera o contador de elementos
int inicializa_lista(PokeLista *lista, int capacidade) {
    lista->vetor = (Pokemon*) malloc(capacidade * sizeof(Pokemon));
    if (lista->vetor == NULL) {
        return 0;
    }
    
    lista->qtd = 0;
    lista->capacidade = capacidade;
    return 1;
}

// Insere no final do vetor se houver espaço disponível
int insere_lista(PokeLista *lista, Pokemon p) {
    if (lista->qtd >= lista->capacidade) {
        return 0;
    }
    
    lista->vetor[lista->qtd] = p;
    lista->qtd++;
    return 1;
}

// Exibe todos os elementos válidos da lista
void imprime_lista(PokeLista *lista) {
    if (lista->qtd == 0) {
        printf("Lista vazia.\n");
        return;
    }
    imprime_vetor(lista->vetor, lista->qtd);
}

// Libera a memória do vetor
void libera_lista(PokeLista *lista) {
    if (lista->vetor != NULL) {
        free(lista->vetor);
        lista->vetor = NULL;
    }
    lista->qtd = 0;
    lista->capacidade = 0;
}