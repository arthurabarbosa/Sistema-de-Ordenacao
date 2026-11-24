#include <stdio.h>
#include <string.h>
#include "pokemon.h"

// Copia os parâmetros recebidos para os campos da struct
int set(Pokemon *pk, int id, int numero, char *name, char *type, int pt_poder) {
    pk->id = id;
    pk->numero_pokedex = numero;
    strcpy(pk->nome, name);
    strcpy(pk->tipo, type);
    pk->pt_poder = pt_poder;
    return 0;
}

int get_id(Pokemon *pk) {
    return pk->id;
}

int get_numeropokedex(Pokemon *pk) {
    return pk->numero_pokedex;
}

void get_nome(Pokemon *pk, char *name) {
    strcpy(name, pk->nome);
}

void get_tipo(Pokemon *pk, char *type) {
    strcpy(type, pk->tipo);
}

int get_pt_poder(Pokemon *pk) {
    return pk->pt_poder;
}

void imprime_pokemon(Pokemon *pk) {
    printf("Pokémon alvo: %s\n", pk->nome);
}

// Percorre o vetor e imprime os dados de cada Pokémon
void imprime_vetor(Pokemon *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Pokedex: %d | Nome: %s | Tipo: %s | Poder: %d\n", 
               vetor[i].id, vetor[i].numero_pokedex, vetor[i].nome, vetor[i].tipo, vetor[i].pt_poder);
    }
}