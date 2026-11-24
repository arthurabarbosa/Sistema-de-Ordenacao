#include <stdio.h>
#include <string.h>
#include "pokemon.h"

// Define todos os dados do Pokémon passado por ponteiro
int set(Pokemon *pk, int id, int numero, char *name, char *type, int pt_poder) {
    pk->id = id;
    pk->numero_pokedex = numero;
    strcpy(pk->nome, name);
    strcpy(pk->tipo, type);
    pk->pt_poder = pt_poder;

    return 0;
}

// Retorna o ID único do Pokémon
int get_id(Pokemon *pk) {
    return pk->id;
}

// Retorna o número do Pokémon na Pokédex
int get_numeropokedex(Pokemon *pk) {
    return pk->numero_pokedex;
}

// Copia o nome do Pokémon para a variável de saída
void get_nome(Pokemon *pk, char *name) {
    strcpy(name, pk->nome);
}

// Copia o tipo do Pokémon para a variável de saída
void get_tipo(Pokemon *pk, char *type) {
    strcpy(type, pk->tipo);
}

// Retorna os pontos de poder do Pokémon na Pokédex
int get_pt_poder(Pokemon *pk) {
    return pk->pt_poder;
}

// Exibe na tela o nome do Pokémon
void imprime_pokemon(Pokemon *pk) {
    printf("Pokémon alvo: %s\n", pk->nome);
}

// Percorre e imprime todos os Pokémons de um vetor
void imprime_vetor(Pokemon *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Nome: %s | Tipo: %s | Poder: %d\n", 
               vetor[i].id, vetor[i].nome, vetor[i].tipo, vetor[i].pt_poder);
    }
}