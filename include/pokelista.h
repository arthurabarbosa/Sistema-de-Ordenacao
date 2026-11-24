#ifndef POKELISTA_H
#define POKELISTA_H
#include "pokemon.h"
#define ID_INVALIDO -1

// Célula da lista encadeada contendo um Pokémon e o ponteiro para a próxima célula
typedef struct Celula {
    Pokemon poke;
    struct Celula* prox;
} Celula;

// Estrutura do tipo Lista Dinâmica Simplesmente Encadeada (com Nó Cabeça)
typedef struct {
    Celula* primeiro; // Ponteiro para a célula cabeça
    Celula* ultimo;   // Ponteiro para o último elemento da lista
} PokeLista;

int inicializa_lista(PokeLista *lista);
int insere_lista(PokeLista *lista, Pokemon p);
int imprime_lista(PokeLista *lista);
Pokemon* converte_encad_vetor(PokeLista *pokemons, int n);
void imprime_vetor(Pokemon *vetor, int n);

#endif