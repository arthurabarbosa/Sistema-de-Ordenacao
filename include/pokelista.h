#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon.h"

// Lista vetorial (sequencial) de Pokémons
typedef struct {
    Pokemon *vetor;   // Vetor alocado dinamicamente
    int qtd;          // Quantidade atual de elementos inseridos
    int capacidade;   // Capacidade máxima do vetor
} PokeLista;

int inicializa_lista(PokeLista *lista, int capacidade);
int insere_lista(PokeLista *lista, Pokemon p);
void imprime_lista(PokeLista *lista);
void libera_lista(PokeLista *lista);

#endif